#pragma once
#include "RBTree.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace MySet
{
	template <class K>
	class set
	{
		typedef K ValueType;
		struct KOFV
		{
			const K& operator()(const ValueType& v)const
			{
				return v;
			}
		};
	public:
		typename typedef RBTree<ValueType, KOFV>::Iterator iterator;
	public:
		set()
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
			return rbt.Find(key);
		}

	private:
		RBTree<ValueType, KOFV> rbt;
	};
}


void TestMySet()
{
	MySet::set<string> s;
	s.insert("apple");
	s.insert("orange");
	s.insert("peach");
	cout << s.size() << endl;

	if (s.find("orange") != s.end())
	{
		cout << "orange is in set" << endl;
	}
	else
	{
		cout << "orange is not in set" << endl;
	}

	if (s.find("banana") != s.end())
	{
		cout << "banana is in set" << endl;
	}
	else
	{
		cout << "banana is not in set" << endl;
	}
}