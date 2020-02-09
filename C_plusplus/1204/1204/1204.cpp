#include <string>
#include <iostream>
using namespace std;
#if 0
// 比较暴力，不是很友好
int Div(int left, int right)
{
	if (0 == right)
		exit(0);

	return left / right;
}
#endif

#if 0
#include <windows.h>

void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		// 获取最近发生错误的错误码(是windows操作系统维护的)
		int errNo = GetLastError();
		cout << errNo << endl;

		return;
	}

	// ....
	fclose(pf);
}

int main()
{
	Test();
	//Test1();
	return 0;
}
#endif

#if 0
void Test()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		// 获取最近发生错误的错误码(是windows操作系统维护的)
		int errNo = GetLastError();
		cout << errNo << endl;

		goto L;
	}

	// ....
	fclose(pf);

L:
}
#endif


#if 0
int main()
{
https://www.baidu.com;

	return 0;
}
#endif

#if 0
#include <malloc.h>

#include <setjmp.h>

// 该全局变量中将来保存的是longjmp函数的跳转位置
jmp_buf buff;  // 有setjmp来设置buff的跳转信息

void Test1()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		// 一旦申请空间失败时，longjmp会跳转到buff指定的位置
		longjmp(buff, 1);
	}

	///正常操作
}

void Test2()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		longjmp(buff, 2);
	}

	// ....
	fclose(pf);
}

int main()
{
	// setjmp设置longjmp函数的跳转点
	// 注意：setjmp在首次调用时，一定会返回0
	int iState = 0;//setjmp(buff);
	if (0 == iState)
	{
		// 正常操作
		Test1();
		Test2();
	}
	else
	{
		// 程序遇到非法情况，longjmp跳转到此位置
		// 一般情况：写的是程序的错误处理代码
		switch (iState)
		{
		case 1:
			cout << "malloc申请空间失败" << endl;
			break;
		case 2:
			cout << "打开文件失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}

	iState = setjmp(buff);
	return 0;
}
#endif


#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
	{
		throw 1;
	}

	// ...
	// 进行常规的文件操作

	fclose(pf);
}


void Test2()
{
	char* p = (char*)malloc(0x7fffffff);
	if (nullptr == p)
	{
		throw 1.0;
	}

	///正常操作
	free(p);
}


int main()
{
	int a = 10;
	double d = 12.34;
	a = d; // double和int之间可以发生隐式类型转化

	// 异常捕获是按照类型来进行捕获的
	// 而且之间基本不会发生类型转化
	try
	{
		Test2();
		Test1();
	}
	catch (int e)
	{
		// 捕获所有int类型的异常
		// 错误处理流程
		cout << e << endl;
	}
	catch (double e)
	{
		cout << e << endl;
	}
	//...
	return 0;
}
#endif


#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
		throw 1;

	// ...
	fclose(pf);
}


void Test2()
{
	int* p = new int[10];

	// ...
	try
	{
		Test1();
	}
	catch (int e)
	{
		delete[] p;
		cout << e << endl;
		return;
	}


	// ...
	delete[] p;
}

int main()
{
	try
	{
		Test2();
		Test1();
	}
	catch (int e)
	{
		cout << e << endl;
	}

	return 0;
}
#endif

#if 0
void Test()
{
	int a = 10;
	cout << &a << endl;

	// 在抛异常时，并不是将a本身抛出，而是抛出了一份a的副本
	throw a;
}

int main()
{
	try
	{
		Test();
	}
	catch (int& ra)
	{
		cout << &ra << endl;
	}
	return 0;
}
#endif


#if 0
class A
{
public:
	A()
	{
		cout << "A::A()" << this << endl;
	}

	A(const A& a)
	{
		cout << "AA::(const A&):" << this << endl;
	}

	~A()
	{
		cout << "A::~A()" << this << endl;
	}
};
void Test()
{
	A  a;
	cout << &a << endl;

	// 在抛异常时，并不是将a本身抛出，而是抛出了一份a的副本
	throw a;  // 实际抛的是a的副本
}

int main()
{
	try
	{
		Test();
	}
	// 	catch (A& ra)
	// 	{
	// 		cout << &ra << endl;
	// 	}
	catch (...) // 万能捕获，即：任意类型的异常都可以采用catch(...)的方式进行捕获
	{
		cout << "A" << endl;
	}
	return 0;
}
#endif

#if 0
void Test1()
{
	FILE* pf = fopen("2222.txt", "rb");
	if (nullptr == pf)
		throw 1;

	// ...
	fclose(pf);
}


void Test2()
{
	int* p = new int[10];

	// ...
	try
	{
		Test1();
	}
	catch (...)
	{
		// 1. 假设Test2现在根本不知道Test1抛出异常的类型
		// 2. 假设Test2知道Test1所抛出异常的类型，但是Test2没有必要必须要解决Test1抛出的异常
		delete[] p;
		throw;   // 异常的重新抛出
	}

	// ...
	delete[] p;
}

int main()
{
	try
	{
		Test2();
	}
	catch (int e)
	{
		cout << e << endl;
	}

	return 0;
}
#endif

#if 0
void Test()
{
	throw 1;
}


template<class T>
void Test2(T a)
{
	throw a;
}

template<class T>
void Test3(T a)
{
	try
	{
		Test2(a);
	}
	catch (T a)
	{
		cout << a << endl;
	}
}

int main()
{
	Test3(10);
	return 0;
}
#endif

#if 0
// 如果抛异常，只能抛出整形的异常
// 否则：在编译期间就会报错
void Test1()throw(int)
{
	throw 1.0;
}

// 该函数一定不会抛出异常
// 否则：在编译期间就会报错
void Test2()throw()
{
	throw 1;
}

int main()
{
	return 0;
}
#endif

class Exception
{
public:
	Exception(const string& errInfo, int errNo)
		: _errInfo(errInfo)
		, _errNo(errNo)
	{}

	virtual void What() = 0;

protected:
	string _errInfo;
	int _errNo;
};

class NetException : public Exception
{
public:
	NetException(const string& errInfo, int errNo)
		: Exception(errInfo, errNo)
	{}

	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};


// 
class DBException : public Exception
{
public:
	DBException(const string& errInfo, int errNo)
		: Exception(errInfo, errNo)
	{}

	virtual void What()
	{
		cout << _errInfo << ":" << _errNo << endl;
	}
};

// 通过网络传递数据
void Test1()
{
	NetException e("网络中断", 400);
	throw e;
}

// 操作数据库
void Test2()
{
	DBException e("数据库未打开", 500);
}

int main()
{
	try
	{
		char* p = new char[0x7fffffff];

		Test1();
		Test2();

	}
	catch (Exception& e)
	{
		e.What();
	}
	catch (exception& e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	return 0;
}