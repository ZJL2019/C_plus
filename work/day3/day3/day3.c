#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int FibRec(unsigned int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return FibRec(n - 1) + FibRec(n - 2);
	}
}

int FibIte(unsigned int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	unsigned int i = 2;
	while (i < n)
	{
		third = first + second;
		first = second;
		second = third;
		i++;
	}
	return third;
}

int main()
{
	//int a = 5;
	//if (a = 0)//if条件中是赋值语句，故此时a的值为0；
	//{
	//	printf("%d\n", a - 10);
	//}
	//else
	//{
	//	printf("%d\n", a++);//因为输出为a++，先输出a的值再进行++，故结果为0
	//}


//****************************************************

	/*int x, y,z;
	x = z = 2;
	y = 3;
	if (x > y)
		z = 1;
	else if (x == y)
		z = 0;
	else
		z = -1;
	printf("%d\n", z);*/
//****************************************************
	//char acHello[] = { "hello\0world" };
	//char acNew[] = { 0 };
	//strcpy(acNew, acHello);
	//strlen(acNew);//5
	//sizeof(acHello);//12
//****************************************************
	printf("%d\n", FibRec(5));
	printf("%d\n", FibIte(5));
	return 0;
}