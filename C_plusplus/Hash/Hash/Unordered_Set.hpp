#pragma once
#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace MUnorder_Set
{
	template<class K>
	class unordered_set
	{
	public:
		typedef K ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data;
			}
		};

		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;
	public:
		unordered_set()
			:ht_()
		{}

		iterator begin()
		{
			return ht_.begin();
		}

		iterator end()
		{
			return ht_.end();
		}

		bool empty()const
		{
			return ht_.empty();
		}

		size_t size()const
		{
			return ht_.size();
		}

		pair<iterator, bool>insert(const ValueType& key)
		{
			return ht_.InsertUnique(key);
		}

		size_t erase(const K& key)
		{
			return ht_.EraseUnique(key);
		}

		iterator find(const K& key)
		{
			return ht_.Find(key);
		}

		void clear()
		{
			ht_.clear();
		}

		void swap(const unordered_set<K>& m)
		{
			ht_.swap(m.ht_);
		}

		size_t bucket_count()const
		{
			return ht_.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return ht_.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return ht_.bucket(key);
		}

	private:
		HashBucket<ValueType, KOFV> ht_;
	};
}

void TestUnorderedSet()
{
	MUnorder_Set::unordered_set<string> m;

	m.insert("apple");
	m.insert("banana");
	m.insert("orange");
	m.insert("peach");

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // 桶的个数
	cout << m.bucket_size(0) << endl;  // 0号桶中的元素个数
	cout << m.bucket("orange") << endl;   // 获取key所在的桶号

	// key不能重复
	m.insert("apple");
	cout << m.size() << endl;

	m.erase("orange");
	cout << m.size() << endl;

	m.clear();
}