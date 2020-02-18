#pragma once
#include <iostream>
#include <vector>
#include "Common.h"
enum STATE { EMPTY, EXIST, DELETE };

template <class T>
struct Elem
{
	Elem(const T& data=T())
		:data_(data)
		,state_(EMPTY)
	{}

	T data_;
	STATE state_;
};


//约定：哈希表中数据唯一
template <class T,class DF=DFDef<T>,bool IsLine=true>
class HashTable
{
public:
	HashTable(size_t  capacity = 10)
		:size_(0)
	{
		table_.resize(GetNextPrime(capacity));
	}

	bool Insert(const T& data)
	{
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		while (table_[hashAddr].state_!=EMPTY)
		{
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
			{
				return false;
			}
			//线性探测
			if (IsLine)
			{
				hashAddr++;
				if (hashAddr == table_.capacity())
				{
					hashAddr = 0;
				}
			}
			//二次探测
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr = hashAddr % table_.capacity();
			}
		}
		table_[hashAddr].data_ = data;
		table_[hashAddr].state_ = EXIST;
		++size_;
		++total_;
		return true;
	}

	int Find(const T& data)
	{
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		while (table_[hashAddr].state_ != EMPTY)
		{
			if (table_[hashAddr].state_ == EXIST && table_[hashAddr].data_ == data)
			{
				return hashAddr;
			}
			//线性探测
			if (IsLine)
			{
				hashAddr++;
				if (hashAddr == table_.capacity())
				{
					hashAddr = 0;
				}
			}
			//二次探测
			else
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr = hashAddr % table_.capacity();
			}
		}
		return -1;
	}

	bool Erase(const T& data)
	{
		int pos = Find(data);
		if (pos != -1)
		{
			table_[pos].state_ = DELETE;
			size_--;
			return true;
		}
		return false;
	}

	size_t Size()
	{
		return size_;
	}

	void Swap(HashTable<T,DF,IsLine>& ht)
	{
		table_.swap(ht.table_);
		swap(size_, ht.size_);
	}

private:

	void CheckCapacity()
	{
		//if (size_*10 / table_.capacity() >= 7)
		if (total_*10 / table_.capacity() >= 7)
		{
			HashTable<T, DF, IsLine> newHT(GetNextPrime(table_.capacity()));
			for (auto e : table_)
			{
				if (e.state_ == EXIST)
				{
					newHT.Insert(e);
				}
			}
			Swap(newHT);
		}
	}

	size_t HashFunc(const T& data)const
	{
		return DF()(data) % table_.capacity();
	}
private:
	std::vector<Elem<T>> table_;
	size_t size_;//哈希表中存储的有效元素的个数
	size_t total_;//哈希表中已经存储的元素个数：有效元素和删除元素
};

void TestHashTable1()
{
	int array[] = { 21,67,112,99,5,13,44 };
	HashTable<int> ht;
	for (auto e : array)
	{
		ht.Insert(e);
	}
	std::cout << ht.Size() << std::endl;
	ht.Insert(87);
	ht.Insert(77);
	std::cout << ht.Size() << std::endl;

	ht.Erase(67);
	if (ht.Find(67) != -1)
	{
		std::cout << "67 is in HashTable" << std::endl;
	}
	else
	{
		std::cout << "67 is not in HashTable" << std::endl;
	}

	if (ht.Find(87) != -1)
	{
		std::cout << "87 is in HashTable" << std::endl;
	}
	else
	{
		std::cout << "87 is not in HashTable" << std::endl;
	}
}

void TestHashTable2()
{
	HashTable<std::string, DFStr, false> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");
}