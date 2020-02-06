#include "list.hpp"
#include <vector>

void TestList1()
{
	List<int> L1;
	List<int> L2(10, 5);

	vector<int> v{ 1,2,3,4,5,6,7,8,9,0 };
	List<int> L3(v.begin(), v.end());
	List<int> L4(L3);

	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

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
	List<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_back();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
	{
		cout << "clear is OK" << endl;
	}
}

void TestList3()
{
	List<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.resize(10, 5);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.resize(2);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	TestList1();
	TestList2();
	TestList3();
	return 0;
}