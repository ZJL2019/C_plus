#pragma once
#include "RBTree.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace MyMap
{
	template <class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& v)const
			{
				return v.first;
			}
		};
	public:
		typename typedef RBTree<ValueType, KOFV>::Iterator iterator;
	public:
		map()
			:rbt()
		{}

		iterator begin()
		{
			return rbt.begin();
		}

		iterator end()
		{
			return rbt.end();
		}

		bool empty()const
		{
			return rbt.Empty();
		}

		size_t size()const
		{
			return rbt.Size();
		}

		pair<iterator, bool>insert(const ValueType& v)
		{
			return rbt.insert(v);
		}

		iterator find(const K& key)
		{
			return rbt.Find(ValueType(key, V()));
		}

		V& operator[](const K& key)
		{
			return (*(rbt.insert(ValueType(key, V())).first)).second;
		}

	private:
		RBTree<ValueType, KOFV> rbt;
	};
}


void TestMyMap()
{
	MyMap::map<string, string> m;
	m.insert(pair<string, string>("apple", "苹果"));
	m.insert(make_pair("orange", "橘子"));

	cout << m["apple"] << endl;
	cout << m.size() << endl;

	m["peach"]="桃子";
	cout << m.size() << endl;

	m.insert(make_pair("orange", "橙子"));
	cout << m.size() << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "----->" << it->second << endl;
		++it;
	}

	auto rit = m.end();
	while (rit != m.begin())
	{
		rit--;
		cout << rit->first << "----->" << rit->second << endl;
	}
}