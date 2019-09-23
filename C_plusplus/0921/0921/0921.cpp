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