#pragma once
#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace MUnorder_Map
{
	template<class K,class V>
	class unordered_map
	{
	public:
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};
		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_map()
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

		size_t size() const
		{
			return ht_.size();
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return ht_.InsertUnique(data);
		}

		size_t erase(const K& key)
		{
			return ht_.EraseUnique(ValueType(key, V()));
		}

		iterator find(const K& key)
		{
			return ht_.Find(ValueType(key, V()));
		}

		void clear()
		{
			ht_.clear();
		}

		void swap(const unordered_map<K, V>& m)
		{
			ht_.swap(m.ht_);
		}

		V& operator[](const K& key)
		{
			return (*(insert(ValueType(key, V())).first)).second;
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
			return ht_.bucket(ValueType(key, V()));
		}

	private:
		HashBucket<ValueType, KOFV> ht_;
	};
}


void TestUnordered_map()
{
	MUnorder_Map::unordered_map<string, string> m;
	m.insert(pair<string, string>("蛋糕", "10元"));
	m.insert(pair<string, string>("奶酪", "15元"));
	m.insert(pair<string, string>("面包", "19元"));


	m.insert(make_pair("薯片", "20"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;
	cout << m.bucket_size(0) << endl;

	cout << m.bucket("蛋糕") << endl;//获取key所在的桶号

	m["咖喱"] = "10元";//如果key不存在则将key-val插入到容器中，返回默认val
	cout << m["咖喱"] << endl;
	cout << m.size() << endl;

	m.erase("咖喱");
	cout << m.size() << endl;
	auto it = m.find("蛋糕");
	cout << it->first << "is" << it->second << endl;
	m.clear();
	cout << m.empty() << endl;

	
}