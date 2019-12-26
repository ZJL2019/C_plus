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

#if 0
//建议：什么情况下都不要使用auto_ptr

#include<memory>

int main()
{
	auto_ptr<int> ap1(new int);
	auto_ptr<int> ap2(ap1);
	return 0;
}
#endif

//C++11:auto_ptr---->保留：资源转移实现
//提供更靠谱的智能指针

//智能指针原理：RAII(自动释放资源) + operator*()/operator->()(具有指针类似的行为) + 提供解决浅拷贝方式

//浅拷贝引起的原因：默认拷贝构造函数 和 默认的赋值运算符重载

// unique_ptr
//资源不共享，资源独占

#if 0
#include<memory>

int main()
{
	unique_ptr<int> up1(new int);
	//unique_ptr<int> up2(up1);
	
	unique_ptr<int> up3(new int);
	//up3 = up1;
	return 0;
}
#endif


#if 0
//解决浅拷贝的方式：资源独占(只能一个对象使用，不能共享)-->实现：禁止调用构造拷贝和赋值运算符重载
namespace my_ptr
{
	template<class T>
	class unique_ptr
	{
	public:
		//RAII
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;//释放资源的方式固定了，只能管理new的资源，不能处理任意类型的资源
				_ptr = nullptr;
			}
		}

		//具有指针类似的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		//解决浅拷贝：禁止调用拷贝构造函数和赋值运算符重载
		
		//C++98
		/*
	private://拷贝构造的权限一定设置成为private，原因：为了防止用户自己在类外定义
		unique_ptr(const unique_ptr<T>& up);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
		*/

		//C++11 禁止调用拷贝构造和赋值运算符重载
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
		//1、释放new的空间
		//2、默认成员函数=delete：告诉编译器，删除该默认成员函数

	private:
		T* _ptr;
	};
	//用户在外部实现
	/*template<class T>
	unique_ptr<T>::unique_ptr(const unique_ptr<T>& up)
	{}*/
}


void TestUniquePtr()
{
	my_ptr::unique_ptr<int> up1(new int);
	//my_ptr::unique_ptr<int> up2(up1);

	my_ptr::unique_ptr<int>up3(new int);
	//up3 = up1;
}

#endif

#if 0
#include<memory>
#include<malloc.h>

int main()
{
	unique_ptr<int> up1(new int);
	unique_ptr<int> up2((int*)malloc(sizeof(int)));
	return 0;
}

#endif


#if 0
template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};


class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

namespace my_ptr
{
	template<class T,class DF=DFDef<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				DF df;
				df(_ptr);
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

		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

	private:
		T* _ptr;
	};
}


void TestUniquePtr()
{
	my_ptr::unique_ptr<int> up1(new int);
	my_ptr::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
	my_ptr::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
}

int main()
{
	TestUniquePtr();
	return 0;
}

#endif

namespace my_ptr
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			,_pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr;
				delete _pCount;
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

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_pCount(sp._pCount)
		{
			if (_ptr)
			{
				++*_pCount;
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//1、与旧资源断开联系
				//this现在不是用自己的资源，要与sp对象共享资源
				if (_ptr && 0 == --*_pCount)
				{
					//当前对象是最后一个使用资源的对象
					delete _ptr;
					delete _pCount;
				}
				//2、与sp共享资源及计数
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
				{
					++*_pCount;
				}
			}
			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		T* _ptr;
		int* _pCount;
	};
}

void TestShardPtr()
{
	my_ptr::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;

	my_ptr::shared_ptr<int>sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	my_ptr::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;

	my_ptr::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp4 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}

int main()
{
	TestShardPtr();
	return 0;
}