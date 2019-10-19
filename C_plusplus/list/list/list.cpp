#include<iostream>
using namespace std;

namespace bite
{
	//list：带头结点的双向循环链表
	template<class T>
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

	//list迭代器：将节点类型的指针重新封装
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		list_iterator(Node* pCur)
			:_pCur(pCur)
		{}
		//按照指针的方式进行应用
		T& operator*()
		{
			return _pCur->_data;
		}

		T* operator->()
		{
			return &(_pCur->_data);
		}

		//移动
		Self& operator++()
		{
			_pCur = _pCur->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}

		Self& operator--()
		{
			_pCur = _pCur->_pPre;
		}

		Self operator--(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _pCur == s._pCur;
		}

		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}

		Node* _pCur;
	};

	template<class Iterator, class T>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<Iterator ,T> Self;
	public:
		list_reverse_iterator(Iterator it)
			:_it(it)
		{}

		T& operator*()
		{
			Iterator temp = _it;
			--temp;
			return *temp;
		}

		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_it--;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_it++;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
		bool operator==(const Self& s)
		{
			return _it == s._it;
		}
		Iterator _it;
	};

	template<class T>
	class list

	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T> iterator;
		typedef list_reverse_iterator<iterator, T> reverse_iterator;
	protected:
		Node* _pHead;
	};
	
}