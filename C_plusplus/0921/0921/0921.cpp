#include<iostream>
using namespace std;

#if 0
//C语言中malloc的开辟方式
int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);
	return 0;
}
#endif


#if 0
//new/delete   new[]/delete[]
//malloc/free
//注意：一定要匹配使用
//1、new和delete不是函数，是C++提供的新的操作符
//2、new/new[]只需在其后跟空间类型，不需要传递字节数
//3、new后跟的就是空间类型，因此不需要强转
//4、new/new[]可以进行初始化
//5、new的结果不需要判空
//6、new申请单个类型元素的空间----默认情况：new出的空间在堆上
int main()
{
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif



#if 0
//如果没有匹配使用，产生什么后果？
//如果申请的是内置类型的空间，不会产生任何后果。
void Test1()
{
	int* p1=(int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;
}


//自定义类型

class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
	int* _p;
};

// 对于自定义类型，只要涉及到[ ]，必然会崩溃
// new会调用构造函数
// free 不会调用析构函数-----对象中的资源不会被销毁


void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;
	//delete[] p2;

	//malloc 申请空间时不会调用构造函数---申请的是与对象大小相同的一块内存空间
	//				不能将该块内存看成是一个对象

	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif 


#if 0
//自定义类型在使用new和delete时，必须匹配使用[ ]
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
#endif

#if 0
void* operator new(size_t size,const char* filename,const char* funName,size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__,__FUNCDNAME__,__LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
//1、new------>能够将申请空间的信息打印
//2、delete--->能够将释放空间的信息打印
void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test(int data)
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
// placement-new
// 定位new表达式：在已经存在的空间上执行构造函数
// 语法： new(地址) Test(参数)

/*
用来申请空间的new操作符-----C++提供的关键字----专门用来申请空间
	1、调用void* operator new（size_t size)
	{
		//调用malloc循环申请 + 空间不足的应对措施
	}

	2、调用构造函数
	void* operator new(size_t size)是一个函数，一般情况下不需要自己给出
	除非需要定制特殊功能

	定位new表达式：
	new(p)  T
	1、void* operator new(size_t size,void* where)
	{
		return where;
	}
	2、执行构造函数
*/


int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	//只要求在pt指向的空间上执行构造函数
	new(pt) Test(10);

	/*
	定位new表达式：调用operator new
	void* operator new(size_t size,void* where)
	{
		return where;
	}
	*/

	//因为空间是由malloc开辟的，尽量保持匹配
	//delete pt;
	pt->~Test();
	free(pt);
	// 需要将pt指向的空间当成对象来使用
	return 0;
}
#endif

#if 0
class Test
{
public:
	~Test()
	{
		Test* p = new Test;
		delete p;
	}
};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
#endif

#if 0
class Object
{
public:
	static Object* GetObject(int data)
	{
		return new Object(data);
	}
	~Object()
	{

	}
	//C++11
	//1、释放new的空间
	//2、在默认成员函数后跟上=delete。删除默认的拷贝构造函数
	Object(const Object& o) = delete;
private:
	//C++98
	//禁用默认拷贝构造函数
	//Object(const Object& o);
	Object(int data)
	{}
};

int main()
{
	Object* p = Object::GetObject(10);
	delete p;


	Object o(*p);
	return 0;
}
#endif


#if 0
//64位系统 & 程序按照64位的方式编译----指针就是8个字节

int main()
{
	cout << sizeof(int*) << endl;
	//开辟4G的空间只能在64位系统下开辟
	void* p = new char[0xfffffffful];
	cout << "new:" << p<< endl;
	return 0;
}
#endif

#if 0
//写一个通用函数的加法函数？--任意类型都可以处理
//函数重载
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif


#if 0
// 与类型无关
//Add 函数模板

template<typename T> //模板参数列表
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

template<typename T1,typename T2> //模板参数列表
T1 Add(T1 left, T2 right)
{
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;

	return left + right;
}

int main()
{
	// 对函数模板进行实例化
	// 在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	// 在对实参的类型进行推演，根据推演的结果，确认模板参数列表中T的实际类型
	// 结合函数模板生成处理具体类型的函数
	// 隐式实例化
	Add(1, 2);  // int ,int----T==>int  生成int Add函数--->Add<int>
	Add(1.0, 2.0); //double, double----T == >double  生成double Add函数--->Add<double>
	Add('1', '2'); //char, char----T == >char  生成char Add函数--->Add<char>
	
	Add(1, (int)2.0);//如果实参的类型不同，则必须进行强转成一致类型

	//或者进行显示实例化
	//显式实例化---直接指定参数T的实际类型
	//编译器：可能会进行隐式类型转化
	Add<int>(1, 2.0);


	//或者定义两个模板参数
	Add(1, 2.0);

	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<typename T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	
	//同名函数与函数模板同时存在，优先使同名函数
	//对函数模板进行显示实例化

	Add<>(1, 2);

	Add<int>(1, 2);
	return 0;
}
#endif


#if 0
int Add(int left, int right)
{
	return left + right;
}

template<typename T1,typename T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	//同名函数与函数模板同时存在
	//如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
	Add(1, 2);
	Add(1.0, 2);
}
#endif


