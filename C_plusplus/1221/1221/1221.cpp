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