#include<stdio.h>

#if 0
//两种命名空间的定义方式

//一个命名空间就相当于是一个作用域

int a = 0;//定义全局变量

namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//命名空间可以嵌套
namespace N2
{
	int a = 10;
	int b = 20;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 10;
		int b = 20;

		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}

//命名空间中成员的访问方式
//1.变量前加作用域限定符以及命名空间的名字
//2.using N1::Add;  Add就成为当前文件中的一个全局变量
//使用using时，应避免当前的变量名与本程序中定义的全局变量名重复

using N1::Add;

int main()
{
	int a = 30;
	printf("%d\n", a);
	//测试输出为main函数中的a的值，满足就近原则
	printf("%d\n", ::a);
	//测试输出为0904.cpp中定义的全局变量
	printf("%d\n", N1::a);
	//测试输出为命名空间N1中的a的值
	printf("%d\n", N1::Add(10, 20));
	//测试输出为命名空间N1中的Add函数
	printf("%d\n",Add(10, 20));
	//测试使用using之后，Add以及为全局变量可直接调用


	return 0;
}

#endif


#if 0
//如果一个工程中包含多个相同名称的命名空间，编译会将其合并成为一个
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N1
{
	int c = 30;
	int d = 40;
}
//当出现同名的命名空间定义时，其内部变量名和其初始化值不能与命名空间中变量重复

//如果命名空间中的成员在当前文件中使用较多
using namespace N1;
//使用这种方式，使命名空间中的所有变量都成为本文件中的全局变量
int main()
{
	int a = 30;
	printf("%d\n", N1::a);
	printf("%d\n", N1::b);
	printf("%d\n", N1::Add(10,20));
	//测试结果相同
	printf("%d\n", a);
	printf("%d\n", ::a);
	//故在文件中，如果main函数中已有的变量与使用using之后的命名空间中的变量重复，则因为其全局变量的缘故需::a如此引用
	printf("%d\n", b);

	return 0;
}

#endif



//#include<iostream.h>  错误，c++中头文件多没有.h后缀

#include<iostream>
using namespace std;//c++中将部分关键字存放在命名空间std中，故需要使用命名空间std，才可以使iostream生效

#if 0
int main()
{
	int a;
	double d;
	cin >> a;//输入流，通过控制台输入将其流至a
	cin >> d;

	cout << a << " " << d << endl;
	//输出流，通过将变量的值输出至控制台
	cin >> a >> d;
	cout << a << " " << d << endl;

	cout << 10 << "\n";
	//"\n"=="endl",c++中既可以使用endl也可使用"\n",完全支持c语法
	cout << 12.34 << endl;
	cout << 10 << " " << 12.34 << endl;
	cout << "hello world" << endl;
	//cout 可以自动判断用户输出的变量的类型
	return 0;
}
#endif


#if 0
//缺省参数
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc();//10
	TestFunc(20);//20
	//c++支持缺省参数，只需要函数定义或声明时赋初始默认值
	return 0;
}

#endif

#if 0
//缺省参数分类
//全缺省参数---所有参数都带有默认值
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << " " << endl;
}

int main()
{
	TestFunc();
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	//依次左往右依次赋给函数的参数列表
	return 0;
}

#endif


#if 0
//半缺省参数：只有部分参数带有默认值，规则：只能从右往左依次给出
//void TestFunc(int a=1, int b = 2, int c )错误
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	return 0;
}
#endif

#if 0
int g_a = 10;
void TestFunc(int a = g_a);
void TestFunc(int a)
{
	cout << a << endl;
}
//函数在设置默认参数时，可以在声明中设置，也可以在定义中设置
//注意：声明和定义不可同时设置默认参数
int main()
{
	TestFunc();
	return 0;
}

#endif