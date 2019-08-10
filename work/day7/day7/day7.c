#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MOD(X,Y) X%Y
int a = 1;

void test()
{
	int a = 2;
	a += 1;
}

int FindMin(int a[],int k)
{
	int i;
	int tmp = a[0];
	for (i = 0; i < k; i++)
	{
		if (a[i] < tmp)
		{
			tmp = a[i];
		}
	}
	return tmp;
}

int main()
{
	/*test();
	printf("%d\n", a);*/
//*******************************

	/*int i = 0;
	int j = 0;
	if ((++i > 0) || (++j > 0))
	{
		printf("i=%d;j=%d\n", i, j);
	}*/
//*******************************

	/*int a = 13, b = 94;
	printf("%d\n", MOD(b, a + 4));*/
//*******************************

	/*int x = 0;
	switch (++x)
	{
	case 0:++x;
	case 1:++x;
	case 2:++x;
	}
	printf("%d\n", x);*/
//*******************************
	int a[8] = { 9, 8, 9, 3, 4, 6, 7, 2 };
	int k;
	scanf("%d", &k);
	printf("%d\n", FindMin(a, k));
	return 0;
}