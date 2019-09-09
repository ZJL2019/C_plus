#include<iostream>
using namespace std;

#if 0
int& TestFunc(int& ra)
{
	return ra;
}

int main()
{
	int a = 10;
	int& rra = TestFunc(a);
	return 0;
}

//引用做函数返回值，尽可能不返回栈上的空间
#endif

#if 0
//传参效率比较：传值最慢(值需要拷贝），传地址和传引用效率几乎一样
#include<time.h>
struct A
{
	int a[10000];
};
void TestFunc1(A a)
{}

void TestFunc2(A* a)
{}

void TestFunc3(A& a)
{}



void  TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	//以地址作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc2(&a);
	}
	size_t end2 = clock();

	//以引用作为函数参数
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc3(a);
	}
	size_t end3= clock();

	//分别计算三个函数运行结束后的时间
	cout << "TestFunc1(int)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int*)-time:" << end2 - begin2 << endl;
	cout << "TestFunc3(int&)-time:" << end3 - begin3 << endl;
}

//运行多次，检测值和引用在传参方面的效率区别
int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

#if 0
//引用和指针有什么区别？
//在底层调用的原理上是一模一样的，在表层的调用上有部分区别
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void Swap(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	int* pa = &a;
	*pa = 20;

	int& ra = a;
	ra = 20;

	Swap(&a, &b);
	Swap(a, b);
	return 0;//编译器在底层的实际操作：Swap(&a,&b)
}
#endif


#if 0
int main()
{
	int* pa;

	int a = 10;
	//int& ra;
	//引用必须初始化，而指针则不需要
	//没有NULL引用，但有NULL指针
	int b = 20;

	pa = &a;
	pa = &b;
	//同一个指针可以指向不同变量的地址
	//一个引用只能引用一个实体
	
	int& ra = a;
	ra++;
	//引用自加则引用的实体加一
	//指针自加则是指针偏移其指针类型的大小

	char c = 'c';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;
	cout << sizeof(rc) << endl;
	//引用大小为引用类型的大小
	//指针大小为始终是地址空间所占字节个数(32位平台下为4个字节）
	
	//指针需要显式解引用，引用则是编译器自己处理

	int** p;
	//有多级指针但是没有多级引用

	//右值引用
	const int&& r = 10;
	return 0;
}
#endif

#if 0
//代码能否通过编译？能否正常运行？可能会在那块出错？
void Swap(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int a = 10;
	int* pb = NULL;

	Swap(a, *pb);
	return 0;
}
//代码可以通过编译，不可以正常运行，将会在函数中ra=rb赋值时出错
//原因：因为传参是空指针所以int& rb=*pb；在底层实现中，引用是将*rb的地址传给了函数
//故函数编译没有问题，但是在赋值时，同指针一样解引用后为NULL，故赋值无法实现
#endif

#if 0
//C++中，被const修饰的变量----->常量
//具有宏替换的特性---->在编译阶段进行替换--->会参与类型检测
int main()
{
	const int a = 10;
	
	int* pa = (int*)&a;
	*pa = 100;

	printf("%d",/*a*/10);
	printf("%d", *pa);
	return 0;
}
#endif


#if 0
//宏函数缺陷：副作用  在预处理阶段替换，不会进行类型检测   不可以调试
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a);//((a)>(++b)?(a):(++b))
	return 0;
}
#endif

#if 0
inline int Add(int left, int right)//inline 内联函数的关键字
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	//内联函数会优化函数调用的过程使主函数中的函数被函数体完全替换
	cout << c << endl;
	return 0;
}
#endif


#if 0
//#include"a.h"
//内联函数不建议声明和定义分离，分离会导致链接错误
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	return 0;
}

#endif

#if 0
//编译器在编译阶段，根据提供的初始化表达式实际类型，来确定变量的类型
int main()
{
	auto a = 10;
	auto b = 12.34;
	//auto c；
	//auto 必须初始化，否则不能推演出原本类型，发生冲突
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	//typeid().name(),可用于查看变量名
	return 0;
}
#endif


#if 0
//auto更方便输出
#include<map>
#include<string>

int main()
{
	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "peach", "桃子" } };
	
	//C++98语法
	//std::map<std::string, std::string>::iterator it = m.begin();

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		it++;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa2 = &a;
	//这时定义都是指针类型pa1中auto为int*，pa2中auto为int

	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;
	
	auto ra = a;
	ra = 20;
	//声明引用使必须auto&

	auto& rra = a;
	rra = 30;

	return 0;
}
#endif

#if 0
int main()
{
	//auto a = 1, b = 2.0, c = 3;
	//定义一行多个变量的类型必须相同
	//在声明符列表中，“auto”必须始终推导为同一类型
	return 0;
}
#endif


#if 0

//void TestFunc(auto a)
//{}
//auto 不能作为函数的参数类型

int main()
{
	int arr1[10] = { 1, 2, 3 };
	//auto arr2[] = { 1, 2, 3 };
	//数组的元素类型不能是包含“auto”的类型
	return 0;
}
#endif


#if 0
int main()
{
	//[array, array + sizeof(array) / sizeof(array[0])]
	//原循环
	/*int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;*/

	//范围for循环
	//auto 可用于循环更方便
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (auto& e : array)
		e *= 2;
	//用auto& 相当于引用数组中的每个元素从而实现更改数值
	for (auto e : array)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

#if 0
//void TestFunc(int* array)
//{
//	for (auto e : array)
//		cout << e << " ";
//}
//auto无法在函数内部调用数组，因为数组传参只传首地址
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	TestFunc(array);
	return 0;
}

#endif