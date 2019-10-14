#include<iostream>
using namespace std;
#include<vector>


#if 0
//vector底层结构：动态类型的顺序表
//vector<char>  string

void TestVector1()
{
	//(constructor)

	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//输出的三种方式
	//顺序遍历
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	//泛运for
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

	//迭代器

	//C++98
	//vector<int>::iterator it = v4.begin();
	auto it1 = v4.begin();
	while (it1 != v4.begin())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	auto it2 = v5.rbegin();
	while (it2!=v5.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
void TestVector2()
{
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end() - 1);


	//InputIterator find (InputIterator first, InputIterator last, const T& val);
	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
	{
		v5.erase(pos);
	}

	v5.clear();
}

void TestVector3()
{
	//二维
	vector<vector<int>> vv;
	//10*10---->6
	vv.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		vv[i].resize(10, 6);
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	return 0;
}
#endif


#if 0
//扩容检测
int main()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
	//扩容约为1.5*capacity
	return 0;
}
#endif


#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//迭代器：类似是指针的一种类型，可以将迭代器定义的对象当成是指针的方式进行应用
	//作用：帮助用户透明的(用户可以不用知道该容器的底层数据结构)遍历容器中的元素
	
	//void assign(size_type n, const value_type& val);
	//v.assign(20,8);//重新给对象中赋值
	
	auto it = v.begin();

	v.push_back(1);//可能会导致迭代失效
	//原因：如果当前有效元素个数等于容量，在尾插时需要扩容
	//从而导致重新分配空间，原空间释放，故迭代器失效
	//所有牵扯扩容，和重新分配空间的操作都有可能使迭代器失效

	//解决方式：
	//1、在扩容之后设置迭代器
	//2、或者重新定义迭代器

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}

	cout << endl;
	return 0;
}

#endif

#if 0
//将vector中所有的元素清除掉
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	
	//方式1
	//v.resize(0);

	//方式2
	//v.clear();

	//方式3
	//v.erase(v.begin(), v.end());

	//方式4
	auto it = v.begin();
	while (it!=v.end())
	{
		it = v.erase(it);
		//eraser的返回值为删除位置的后一个位置
	}
	cout << v.size() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int& ra = v[0];
	ra = 10;
	v.push_back(1);
	//引用会失效
	//原因：扩容，原空间释放，所以当前引用指向的已经不是v
	ra = 100;
	return 0;
}
#endif



