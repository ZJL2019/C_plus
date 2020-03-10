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

template<class T, class KOFV,class DF = DFStr>
class HashBucket;

template<class T,class KOFV,class DF= DFStr>
struct HBIterator
{
	typedef HashNode<T> Node;
	typedef HBIterator<T,KOFV,DF> Self;
	HBIterator(Node* pNode=nullptr,HashBucket<T,KOFV,DF>* ht=nullptr)
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
	HashBucket<T,KOFV, DF>* ht_;
};


template<class T,class KOFV,class DF>
class HashBucket
{
	friend struct HBIterator<T, KOFV,DF>;
	typedef HashNode<T> Node;

public:
	typedef HBIterator<T, KOFV,DF> iterator;

public:
	HashBucket(size_t capacity = 10)
		:size_(0)
	{
		table_.resize(GetNextPrime(10));
	}
	~HashBucket()
	{
		clear();
	}
	//在插入时哈希桶中元素唯一
	std::pair<iterator,bool>InsertUnique(const T& data)
	{
		CheckCapacity();

		size_t bucketNo = HashFunc(data);
		Node* pCur = table_[bucketNo];
		
		while (pCur)
		{
			if (KOFV()(pCur->data_) == KOFV()(data))
				return  make_pair(iterator(pCur, this), false);

			pCur = pCur->pNext_;
		}

		//头插
		pCur = new Node(data);
		pCur->pNext_ = table_[bucketNo];
		table_[bucketNo] = pCur;
		++size_;

		return make_pair(iterator(pCur, this), true);
	}

	size_t EraseUnique(const T& data)
	{
		size_t bucketNo = HashFunc(data);

		Node* pCur = table_[bucketNo];
		Node* pPre = nullptr;
		while (pCur)
		{
			if (KOFV()(pCur->data_) ==KOFV()(data))
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
				return 1;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->pNext_;
			}
		}
		return 0;
	}

	iterator Find(const T& data)
	{
		size_t bucketNo = HashFunc(data);
		Node* pCur = table_[bucketNo];
		while (pCur)
		{
			if (KOFV()(pCur->data_) == KOFV()(data))
				return iterator(pCur, this);

			pCur = pCur->pNext_;
		}
		return end();
	}

	size_t size()const
	{
		return size_;
	}

	bool empty()const
	{
		return size_ == 0;
	}

	iterator begin()
	{
		for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
		{
			if (table_[bucketNo])
				return iterator(table_[bucketNo], this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	void clear()
	{
		for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
		{
			Node* cur = table_[bucketNo];
			while (cur)
			{
				table_[bucketNo] = cur->pNext_;
				delete cur;
				cur = table_[bucketNo];
			}
		}
		size_ = 0;
	}

	size_t bucket_count()const
	{
		return table_.capacity();
	}

	size_t bucket_size(size_t bucketNo)const
	{
		if (bucketNo >= bucket_count())
		{
			return 0;
		}
		size_t count = 0;
		Node* cur = table_[bucketNo];
		while (cur)
		{
			count++;
			cur = cur->pNext_;
		}
		return count;
	}

	size_t bucket(const T& data)
	{
		return HashFunc(data);
	}

	void swap(HashBucket<T, KOFV, DF>& ht)
	{
		table_.swap(ht.table_);
		std::swap(size_, ht.size_);
	}

private:
	void CheckCapacity()
	{
		if (size_ == table_.capacity())
		{
			HashBucket<T, KOFV, DF> newHT(GetNextPrime(size_));
			for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
			{
				Node* cur = table_[bucketNo];
				while (cur)
				{
					size_t newBucketNo = newHT.HashFunc(cur->data_);
					table_[bucketNo] = cur->pNext_;
					cur->pNext_ = newHT.table_[newBucketNo];
					newHT.table_[newBucketNo] = cur;
					newHT.size_++;
				
					cur = table_[bucketNo];
				}
			}
			this->swap(newHT);

			//该方式效率太低
			/*for (size_t bucketNo = 0; bucketNo < table_.capacity(); bucketNo++)
			{
				Node* cur = table_[bucketNo];
				while (cur)
				{
					newHT.InsertUnique(cur->data_);
					cur=cur->pNext_；
				}
			}
			this->swap(newHT);*/
		}
	}
	size_t HashFunc(const T& data)const
	{
		return DF()(KOFV()(data)) % table_.capacity();
	}
private:
	std::vector<Node*> table_;
	size_t size_;
};
