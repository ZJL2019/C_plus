#pragma once
#include <vector>
#include <iostream>
#include "Common.h"
using namespace std;
template<class T>
struct HashNode
{
	HashNode(const T& data=T())
		:pNext_(nullptr)
		,data_(data)
	{}

	HashNode<T>* pNext_;
	T data_;
};

template<class T, class DF = DFDef<T>>
class HashBucket;

template<class T,class DF=DFDef<T>>
struct HBIterator
{
	typedef HashNode<T> Node;
	typedef HBIterator<T,DF> Self;
	HBIterator(Node* pNode=nullptr,HashBucket<T,DF>* ht=nullptr)
		:pNode_(pNode)
		, ht_(ht)
	{}

	T& operator* ()
	{
		return pNode_->data_;
	}

	T* operator->()
	{
		return &(pNode_->data_);
	}

	Self& operator++()
	{
		Next();
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Next();
		return temp;
	}

	bool operator != (const Self& s)
	{
		return pNode_ != s.pNode_;
	}

	bool operator==(const Self& s)
	{
		return pNode_ == s.pNode_;
	}

	void Next()
	{
		if (pNode_->pNext_)
		{
			pNode_ = pNode_->pNext_;
		}
		else
		{
			size_t bucketNo = ht_->HashFunc(pNode_->data_) + 1;
			for (; bucketNo < ht_->table_.capacity(); bucketNo++)
			{
				if (ht_->table_[bucketNo])
				{
					pNode_ = ht_->table_[bucketNo];
					return;
				}
			}
			pNode_ = nullptr;
		}
	}

	HashNode<T>* pNode_;
	HashBucket<T, DF>* ht_;
};


template<class T,class DF>
class HashBucket
{
	friend struct HBIterator<T, DF>;

	typedef HashNode<T> Node;
	typedef HBIterator<T, DF> Iterator;

public:
	HashBucket(size_t capacity = 10)
		:size_(0)
	{
		table_.resize(GetNextPrime(capacity));
	}
	//在插入时哈希桶中元素唯一
	bool InsertUnique(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* pCur = table_[bucketNo];
		
		while (pCur)
		{
			if (pCur->data_ == data)
			{
				return false;
			}
			pCur = pCur->pNext_;
		}

		//头插
		pCur = new Node(data);
		pCur->pNext_ = table_[bucketNo];
		table_[bucketNo] = pCur;
		++size_;
		return  true;
	}

	//哈希桶中可插入相同元素
	bool InsertEqual(const T& data)
	{

	}

	bool EraseUnique(const T& data)
	{
		size_t bucketNo = HashFunc(data);

		Node* pCur = table_[bucketNo];
		Node* pPre = nullptr;
		while (pCur)
		{
			if (pCur->data_ ==data)
			{
				if (pPre == nullptr)
				{
					table_[bucketNo] = pCur->pNext_;
				}
				else
				{
					pPre->pNext_ = pCur->pNext_;
				}
				delete pCur;
				--size_;
				return true;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->pNext_;
			}
		}
		return false;
	}
	//将所有值为data的结点删除
	bool EraseEqual(const T& data)
	{

	}

	Node* Find(const T& data)const
	{
		size_t bucketNo = HashFunc(data);
		Node* pCur = table_[bucketNo];
		while (pCur)
		{
			if (pCur->data_ == data)
			{
				return pCur;
			}
			pCur = pCur->pNext_;
		}
		return nullptr;
	}

	size_t size()const
	{
		return size_;
	}

	bool empty()const
	{
		return size_ == 0;
	}

	Iterator begin()
	{
		for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
		{
			if (table_[bucketNo])
				return Iterator(table_[bucketNo], this);
		}
		return end();
	}

	Iterator end()
	{
		return Iterator(nullptr, this);
	}

	//测试
	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
		{
			Node* pCur = table_[bucketNo];
			std::cout << "table_[" << bucketNo << "]:";
			while (pCur)
			{
				std::cout << pCur->data_ << "----->";
				pCur = pCur->pNext_;
			}
			std::cout << "NULL" << std::endl;
		}
	}
private:
	void CheckCapicaty()
	{
		if (size_ == table_.capacity())
		{

		}
	}
	size_t HashFunc(const T& data)const
	{
		return DF()(data) % table_.capacity();
	}
private:
	std::vector<Node*> table_;
	size_t size_;
};

void TestHashBucket()
{
	HashBucket<int> ht;
	int array[] = { 4,1,5,7,6,9 };
	for (auto e : array)
	{
		ht.InsertUnique(e);
	}
	std::cout << ht.size() << std::endl;
	ht.PrintHashBucket();

	ht.InsertUnique(44);
	ht.InsertUnique(54);
	auto it = ht.begin();
	while (it != ht.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	ht.PrintHashBucket();

	ht.EraseUnique(44);
	if (ht.Find(44))
	{
		std::cout << "44 is in HashBucket" << std::endl;
	}
	else
	{
		std::cout << "54 is not in HashBucket" << std::endl;
	}
	std::cout << ht.size() << std::endl;
	ht.PrintHashBucket();
}