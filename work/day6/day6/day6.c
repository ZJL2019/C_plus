#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int x = 3;
int fun(int a, int b)
{
	if (a > b)
		return (a + b);
	else
		return (a - b);
}

int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return (a);
}

void inc()
{
	static int x = 1;
	x *= (x + 1);
	printf("%d ", x);
	return;
}

int main()
{
	/*int x = 3, y = 8, z = 6, r;
	r = fun(fun(x, y), 2 * z);
	printf("%d\n", r);*/

//**********************************

	/*int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf("%d\n", k);*/
//**********************************
	int i;
	for (i = 1; i < x; i++)
	{
		inc();
	}
	return 0;
}