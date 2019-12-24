#include<iostream>
using namespace std;

//C/C++

//bool Test1()
//{
//	//成功返回true ，失败返回false
//	return false;
//}
//
//void Test2()
//{
//	// .....
//	//假设此处遇到非法情况
//	throw 1;
//}
//
//// 如果采用原生态指针(T*)管理资源，程序存在资源泄漏的风险就比较大
//
//void TestFunc()
//{
//	int *p = new int[10];
//	FILE *pf = fopen("2223.txt", "rb");
//	if (nullptr == pf)
//	{
//		delete[] p;
//		return;
//	}
//
//	// ...
//	if (!Test1())
//	{
//		delete[] p;
//		fclose(pf);
//		return;
//	}
//
//	try
//	{
//		Test2();
//	}
//	catch (...)
//	{
//		delete[] p;
//		fclose(pf);
//		throw;
//	}
//	delete[] p;
//	fclose(pf);
//}


//能否让程序自我感知：对象在销毁时自动释放资源


// RAII---资源获取即初始化
// 在构造函数中放资源
// 在析构函数中释放资源


#if 0
//智能指针的简单模拟实现
template<class T>
class SmartPtr
{
public:
	//RAII: 作用--->用户不用考虑什么时候该释放资源
	//				把释放资源的工作交给编译器
	SmartPtr(T* ptr = nullptr)
	:_ptr(ptr)
	{
		cout << "SmartPtr(T*)" << endl;
	}

	~SmartPtr()
	{
		cout << "~SmartPtr(T*)" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	//让该类的对象具备指针类似的行为
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestSmartPtr()
{
	SmartPtr<int> spl(new int);
	*spl = 10;

	SmartPtr<A> sp2(new A);
	sp2->a = 1;
	sp2->b = 2;
	sp2->c = 3;
}

int main()
{
	TestSmartPtr();
	return 0;
}

#endif

//缺陷：浅拷贝
//String--->引出的浅拷贝的问题--->深拷贝
//不能采用深拷贝的方式进行解决


#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{
		cout << "SmartPtr()" << endl;
	}

	~SmartPtr()
	{
		cout << "~SmartPtr()" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


void TestSmartPtr()
{
	int a = 10;
	int *pa = &a;
	int *pb(pa);

	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(sp1);//使用sp1构造sp2
}

//两个指针指向同一片空间，连续释放导致程序崩溃
int main()
{
	TestSmartPtr();
	return 0;
}
#endif

//所有不同类型的智能指针：
//RAII:资源可以自动释放
//类对象具有指针类似的行为：operator*()/operator->()
//浅拷贝的解决方式