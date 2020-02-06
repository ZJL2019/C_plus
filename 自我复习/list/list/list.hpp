#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct ListNode
{
	ListNode(const T& data=T())
		:_pNext(nullptr)
		,_pPre(nullptr)
		,_data(data)
	{}

	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
	T _data;
};

template <typename T>
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
	//Ç°ÖÃ
	Self& operator++()
	{
		_pCur = _pCur->_pNext;
		return *this;
	}
	//ºóÖÃ
	Self operator++(int)
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

	Self operator--(int)
	{
		Self temp(*this);
		_pCur = _pCur->_pPre;
		return temp;
	}

	bool operator!=(const Self& s)
	{
		return _pCur != s._pCur;
	}

	bool operator==(const Self& s)
	{
		return _pCur == s._pCur;
	}

	Node* _pCur;
};

template<typename Iterator,typename T>
struct list_reverse_iterator
{
	typedef list_reverse_iterator<Iterator, T> Self;
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

template<typename T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef list_iterator<T> iterator;
	typedef list_reverse_iterator<iterator, T> reverse_iterator;
public:
	List()
	{
		CreateHead();
	}

	List(int n, const T& data)
	{
		CreateHead();
		for (size_t i = 0; i < n; i++)
		{
			push_back(data);
		}
	}

	template<typename Iterator>
	List(Iterator first, Iterator last)
	{
		CreateHead();
		while (first != last)
		{
			push_back(*first);
			first++;
		}
	}

	List(const List<T>& L)
	{
		CreateHead();
		Node* pCur = L._pHead->_pNext;
		while (pCur != L._pHead)
		{
			push_back(pCur->_data);
			pCur = pCur->_pNext;
		}
	}

	List<T>& operator=(const List<T>& L)
	{
		if (this != &L)
		{
			clear();
			Node* pCur = L._pHead->_pNext;
			while (pCur != _pHead)
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}
		return *this;
	}

	~List()
	{
		clear();
		delete _pHead;
	}

	//iterator
public:
	iterator begin()
	{
		return iterator(_pHead->_pNext);
	}

	iterator end()
	{
		return iterator(_pHead);
	}

	reverse_iterator rbegin()
	{
		return end();
	}

	reverse_iterator rend()
	{
		return begin();
	}

	//capacity
	size_t size()const
	{
		size_t count = 0;
		Node* pCur = _pHead->_pNext;
		while (pCur != _pHead)
		{
			count++;
			pCur = pCur->_pNext;
		}
		return count;
	}

	bool empty()const
	{
		return _pHead->_pNext == _pHead;
	}

	void resize(size_t newsize, const T& data = T())
	{
		size_t oldsize = size();
		if (newsize > oldsize)
		{
			for (size_t i = oldsize; i < newsize; i++)
			{
				push_back(data);
			}
		}
		else
		{
			for (size_t i = newsize; i < oldsize; i++)
			{
				pop_back();
			}
		}
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


	//modify
	void push_back(const T& data)
	{
		insert(end(), data);
	}

	void pop_back()
	{
		erase(--end());
	}

	void push_front(const T& data)
	{
		insert(begin(), data);
	}

	void pop_front()
	{
		erase(begin());
	}

	iterator insert(iterator pos, const T& data)
	{
		Node* pNewNode = new Node(data);
		Node* pCur = pos._pCur;
		pNewNode->_pPre = pCur->_pPre;
		pNewNode->_pNext = pCur;
		pNewNode->_pPre->_pNext = pNewNode;
		pCur->_pPre = pNewNode;

		return iterator(pNewNode);
	}

	iterator erase(iterator pos)
	{
		Node* pDelNode = pos._pCur;
		if (pDelNode == _pHead)
		{
			return end();
		}
		Node* pRet = pDelNode->_pNext;
		pDelNode->_pPre->_pNext = pDelNode->_pNext;
		pDelNode->_pNext->_pPre = pDelNode->_pPre;
		delete pDelNode;

		return iterator(pRet);
	}

	void clear()
	{
		Node* pCur = _pHead->_pNext;
		while (pCur != _pHead)
		{
			_pHead->_pNext = pCur->_pNext;
			delete pCur;
			pCur = _pHead->_pNext;
		}
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}

	void swap(List<T>& L)
	{
		swap(_pHead, L._pHead);
	}

private:
	void CreateHead()
	{
		_pHead = new Node;
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}

protected:
	Node* _pHead;
};