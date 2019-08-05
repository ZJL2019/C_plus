#define _CRT_SECURE_NO_WARNINGS 1
#pragma pack(4)
#define F(X,Y) ((X)+(Y))
#include<stdio.h>
#include<stdlib.h>
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}

int fun1(int x)
{
	int n = 0;
	int i, sum=0;
	for (i = x; i; i /= 2)
	{
		if (i % 2 == 1)
		{
			n++;
		}
	}
}

int  count_one_bits3(int n)//best
{
	int count = 0;
	while (n != 0)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

int main()
{
	/*char a[20];
	char *p1 = (char*)a;
	char *p2 = (char*)(a + 5);
	int n = p2 - p1;*/


	/*int a = 3;
	int b = 4;
	printf("%d\n", F(a++, b++));
	*/
	/*int x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
	printf("%d", x);*/
	
	
	/*int i = 1, sum = 0;
	while (i < 10)
	{
		sum = sum + 1;
		i++;
	}
	printf("%d %d", i, sum);
	*/




	/*struct tagTest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char d;
		long a;
	};
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;
	printf("%d,%d,%d", sizeof(stT1), sizeof(stT2), sizeof(stT3));*/


	/*enum ENUM_A
	{
		X1,
		Y1,
		Z1 = 5,
		A1,
		B1
	};
	enum ENUM_A enumA = Y1;
	enum ENUM_A enumB = B1;*/

	//int j = 4;
	//int m = 1;
	//int k;
	//k = fun(j, m);
	//printf("%d,", k);
	//k = fun(j, m);
	//printf("%d\n", k);
	/*fun1(10);
	printf("%d",count_one_bits3(5));
	*/
	int n;
	scanf("%d", &n);
	int i = 0;
	for (i = 31; i >= 0; i -- )
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	
	printf("%o\n", n);
	printf("%x\n", n);
	return 0;
}