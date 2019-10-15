#include<iostream>
using namespace std;

// list: 带头结点双向循环链表

// 1、使用
// 2、了解底层结构
// 3、模拟实现

#include<list>
#include<vector>

void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L3(v.begin(), v.end());
	list<int> L4(L3);

	cout << L1.size() << endl;

	// 采用迭代器方式
	// C++98
	//list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it!=L2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << L3.front() << endl;
	cout << L3.back() << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

}

void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.size() << endl;

	L.push_front(0);
	cout << L.front() << endl;

	L.pop_front();
	cout << L.front() << endl;

	L.pop_back();
	cout << L.back() << endl;

	auto it = find(L.begin(), L.end(), 2);
	if (it != L.end())
	{
		L.insert(it, 5);
	}

	L.erase(it);

}

bool IsOdd(int data)
{
	if (0 == data % 2)
	{
		return true;
	}
	return false;
}

void TestList3()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	//删除所有2
	//L.remove(2);

	//删除L中所有的偶数
	//remove_if:删除所有满足条件的结点
	//条件：就是该函数的参数
	//该函数的实现原理：对每个结点中的值域用参数条件验证，如果满足则删除，如果不满足，什么都不做
	L.remove_if(IsOdd);

}

//注意：使用unique时必须保证链表是有序的
void TestList4()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	L.sort();
	L.unique();
}

//list中的迭代器失效-----迭代器指向的结点不存在
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();

	//erase之后，it所指向的结点已经被删除掉了
	//it迭代器失效
	L.erase(it);
	it = L.begin();
	while (it!=L.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	TestListIterator();
	return 0;
}

