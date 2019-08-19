#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
void fun(int x, int y, int *c, int *d)
{
	*c = x + y;
	*d = x - y;
}

void Find_num(int *arr, int len)
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("x=%d,y=%d\n", x, y);
}

int main()
{
	/*int result = f(2, 4);
	printf("%d", result);*/

//*********************************
	/*int a = 4, b = 3, c = 0, d = 0;
	fun(a, b, &c, &d);
	printf("%d %d\n", c, d);*/

//*********************************
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find_num(arr, sz);
	return 0;
}