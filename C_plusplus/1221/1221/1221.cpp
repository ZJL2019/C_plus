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


//C++98--
//auto_ptr
//解决浅拷贝方式：资源转移--->当前对象
//缺陷：p1和p2不可以同时访问同一个资源
#if 0
namespace my_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	//具有指针类似的行为
		T&operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		//解决浅拷贝问题
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//ap3=ap2
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//如果当前对象管理资源，先释放资源
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;//资源转移
				ap._ptr = nullptr;//ap与资源断开联系
			}
			return *this;
		}

	private:
		T* _ptr;
	};
}
#endif

//增加bool_owner:标记释放 对资有释放的权利
//改进之后的auto_ptr的实现原理
//RAII +  operator*()/operator->() + 解决浅拷贝：资源管理权限(对资源释放的权利)转移
#if 0
namespace my_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}

		~auto_ptr()
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T*operator->()
		{
			return _ptr;
		}

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			,_owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr&&_owner)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

	private:
		T *_ptr;
		mutable bool _owner;
	};
}

void TestAutoPtr1()
{
	int a = 10;
	int *pa = &a;
	int *pb = pa;

	*pa = 100;
	*pb = 200;

	my_ptr::auto_ptr<int> ap1(new int);
	my_ptr::auto_ptr<int> ap2(ap1);

	//资源转移的缺陷：ap1已和资源断开连接，不能再操作资源
	*ap2 = 200;
	*ap1 = 100;

	my_ptr::auto_ptr<int> ap3(new int);
	ap3 = ap2;
}

//带_owner版本的auto_ptr缺陷：可能会造成野指针--导致代码崩溃
void TestAutoPtr2()
{
	my_ptr::auto_ptr<int> ap1(new int);
	if (true)
	{
		my_ptr::auto_ptr<int> ap2(ap1);
		*ap2 = 20;
	}

	//ap1是野指针
	*ap1 = 10;
}

int main()
{
	//TestAutoPtr1();
	TestAutoPtr2();
	return 0;
}
#endif

