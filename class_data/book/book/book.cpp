
#include<iostream>
using namespace std;
#include<iomanip>
#define BOOK_ISBN 15
#define BOOK_NAME 30
#define BOOK_PRI 10
typedef struct book
{
	char ISBN[BOOK_ISBN];
	char BOOK[BOOK_NAME];
	char PRI[BOOK_PRI];
}book;

template <class T>
struct ListNode
{
	ListNode(const T& data = T())
	:_pNext(nullptr)
	, _pPre(nullptr)
	, _data(data)
	{}

	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
	T _data;
};

template<class T>
struct list_iterator
{
	typedef ListNode<T> Node;
	typedef list_iterator<T> Self;
public:
	list_iterator(Node* pCur)
		:_pCur(pCur)
	{}
	T& operator*()
	{
		return _pCur->_data;
	}
	T* operator->()
	{
		return &(_pCur->_data);
	}


	Self& operator++()
	{
		_pCur = _pCur->_pNext;
		return *this;
	}
	Self operator++ (int)
	{
		Self temp(*this);
		_pCur = _pCur->_pNext;
		return temp;
	}

	Self& operator--()
	{
		_pCur = _pCur->_pPre;
		return *this;
	}
	Self operator-- (int)
	{
		Self temp(*this);
		_pCur = _pCur->_pPre;
		return temp;
	}

	bool operator !=(const Self& s)
	{
		return _pCur != s._pCur;
	}

	bool operator ==(const Self& s)
	{
		return _pCur == s._pCur;
	}

	Node* _pCur;
};

template<class T>
class List_book
{
	typedef ListNode<T> Node;
	typedef list_iterator<T> Iterator;
public:
	List_book()
	{
		CreatHead();
	}
	~List_book()
	{
		clear();
		delete _phead;
	}

	Iterator begin()
	{
		return Iterator(_phead->_pNext);
	}

	Iterator end()
	{
		return Iterator(_phead);
	}

	size_t size()const
	{
		size_t count = 0;
		Node* pCur = _phead->_pNext;
		while (pCur != _phead)
		{
			count++;
			pCur = pCur->_pNext;
		}
		return count;
	}

	void push_back(const T& data)
	{
		insert(end(), data);
	}

	void pop_back()
	{
		erase(--end());
	}
	void pop_front()
	{
		erase(begin());
	}
	void push_front(const T& data)
	{
		insert(begin(), data);
	}
	T& front()
	{
		return _pHead->_pNext->_data;
	}


	const T& front()const
	{
		return _pHead->_pNext->_data;
	}

	T& back()
	{
		return _pHead->_pPre->_data;
	}

	const T& back()const
	{
		return _pHead->_pPre->_data;
	}

	Iterator  find(char* find_s)
	{
		Node* pCur = _phead->_pNext;
		while (pCur != _phead)
		{
			if (strcmp(pCur->_data.ISBN, find_s) == 0 || strcmp(pCur->_data.BOOK,find_s)==0 || strcmp(pCur->_data.PRI,find_s)==0)
			{
				cout << pCur->_data.ISBN << "     " << pCur->_data.BOOK << "     " << pCur->_data.PRI;
				cout << endl;
				return Iterator(pCur);
			}
			pCur = pCur->_pNext;
		}
		return nullptr;
	}

	void print(const List_book<T>& L)
	{
		Node* pCur = _phead->_pNext;
		cout << left << setw(10) << "BOOK_ISBN" << setw(10) << "BOOK_NAME" << setw(10) << "BOOK_PRI";
		cout << endl;
		while (pCur != _phead)
		{
			cout << left << setw(10) << pCur->_data.ISBN << setw(10) << pCur->_data.BOOK << setw(10) << pCur->_data.PRI;
			cout << endl;
			pCur = pCur->_pNext;
		}
	}

	void modify(Iterator pos)
	{
		Node* pCur = pos._pCur;
		cout <<left<<setw(10)<< pCur->_data.ISBN <<setw(10)<< pCur->_data.BOOK <<setw(10)<< pCur->_data.PRI;
		cout << endl;
		cout << "BOOK_ISBN:";
		cin >> pCur->_data.ISBN;
		cout << "BOOK_NAME:";
		cin >> pCur->_data.BOOK;
		cout << "BOOK_PRI:";
		cin >> pCur->_data.PRI;
	}

	Iterator insert(Iterator pos, const T& data)
	{
		Node* pNewNode = new Node(data);
		Node* pCur = pos._pCur;

		pNewNode->_pPre = pCur->_pPre;
		pNewNode->_pNext = pCur;
		pNewNode->_pPre->_pNext = pNewNode;
		pCur->_pPre = pNewNode;
		return Iterator(pNewNode);
	}
	Iterator erase(Iterator pos)
	{
		Node* pDelNode = pos._pCur;
		if (pDelNode == _phead)
		{
			return end();
		}

		Node* pRet = pDelNode->_pNext;
		pDelNode->_pPre->_pNext = pDelNode->_pNext;
		pDelNode->_pNext->_pPre = pDelNode->_pPre;
		delete pDelNode;
		return Iterator(pRet);
	}
	void clear()
	{
		Node* pCur = _phead->_pNext;
		while (pCur != _phead)
		{
			_phead->_pNext = pCur->_pNext;
			delete pCur;
			pCur = _phead->_pNext;
		}
		_phead->_pNext = _phead;
		_phead->_pPre = _phead;
	}
private:
	void CreatHead()
	{
		_phead = new Node;
		_phead->_pNext = _phead;
		_phead->_pPre = _phead;
	}
protected:
	Node* _phead;
};

void MENU()
{
	cout << "            图书管理系统            " << endl;
	cout << "1、录入        2、查找       3、删除" << endl;
	cout << "4、总数        5、更改       6、退出" << endl;
}

int FindWay()
{
	cout << "输入1使用查找删除；输入2使用直接后删；输入3使用直接头删";
	int n = 0;
	cin >> n;
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int main()
{

	List_book<book> L;
	book b1;
	MENU();
	int n = 0;
loop:
	cout << "请选择功能：";
	cin >> n;
	int i = 0;
	int k = false;
	switch (n)
	{
	case 1:
		cout << "输入1为从前录入，(默认从后录入):";
		cin >> k;
		if (k==1)
		{
			cout << "录入几本书：";
			cin >> i;
			while (i > 0)
			{
				cout << "BOOK_ISBN:";
				cin >> b1.ISBN;
				cout << "BOOK_NAME:";
				cin >> b1.BOOK;
				cout << "BOOK_PRI:";
				cin >> b1.PRI;
				L.push_front(b1);
				i--;
				cout << endl;
			}
		}
		else
		{
			cout << "录入几本书：";
			cin >> i;
			while (i > 0)
			{
				cout << "BOOK_ISBN:";
				cin >> b1.ISBN;
				cout << "BOOK_NAME:";
				cin >> b1.BOOK;
				cout << "BOOK_PRI:";
				cin >> b1.PRI;
				L.push_back(b1);
				i--;
				cout << endl;
			}
		}
		break;
	case 2:
		cout << "查找信息：";
		char a[15];
		cin >> a;
		L.find(a);
		break;
	case 3:
		if (FindWay()==1)
		{
			cout << "查找信息：";
			char b[15];
			cin >> b;
			L.erase(L.find(b));
		}
		else if (FindWay() == 2)
		{
			L.pop_back();
		}
		else
		{
			L.pop_front();
		}
		break;
	case 4:
		cout << "总数：" << L.size() << endl;
		L.print(L);
		break;
	case 5:
		cout << "查找信息：";
		char c[15];
		cin >> c;
		L.modify(L.find(c));
		break;
	case 6:
		return 0;
	default:
		break;
	}
	goto loop;
}
