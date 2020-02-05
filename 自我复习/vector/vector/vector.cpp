#include "vector.hpp"
void TestVector1()
{
	Vector<int> v1;
	Vector<int> v2(10, 5);
	int array[] = { 1,2,3,4,5 };
	Vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	Vector<int> v4(v3);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v2.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl; 
	auto it =v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector2()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector3()
{
	Vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

int main()
{
	//TestVector1();
	//TestVector2();
	TestVector3();
	return 0;
}