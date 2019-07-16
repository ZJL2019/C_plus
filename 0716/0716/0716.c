#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int prime(int n)
{
	int i = 2;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}


void d1p1()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (prime(i))
		{
			printf("%d\n", i);
		}
	}
}

//*****************************************

void d1p2(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("  %d*%d=%2d", j, i, j*i);
			//printf("*");
		}
		printf("\n");
	}
}

//*****************************************

void d1p3()
{
	int i;
	for (i = 1000; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			printf("%d ", i);
	}
}

//*****************************************

int Max(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

void d2p4(int a, int b)
{
	int i, max, smaller;
	smaller = Max(a, b);
	for (i = 1; i < smaller; i++)
	{
		if (a%i == 0 && b%i == 0)
		{
			max = i;
		}
	}
	printf("%d\n", max);
}

//*****************************************

void d3p2()
{
	int i, flag = 1;
	double sum = 0;
	for (i = 1; i < 100; i++)
	{
		sum += flag*1.0 / i;
		flag *= -1;
	}
	printf("%f\n", sum);
}

//*****************************************

void d4p1(int n)
{
	int i,j;
	for (i = 1; i <= n; i++)
	{
#if 0
		for (j = 1; j <= n - i; j++)
		{
			putchar(' ');
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
#else
		for (j = 1; j<n + i; j++)
		{
			putchar(j <= n - i ? ' ' : '*');
		}
#endif
		putchar('\n');
	}
	for (i = n - 1; i > 0; i--)
	{
		for (j = 1; j<n + i; j++)
		{
			putchar(j <= n - i ? ' ' : '*');
		}
		putchar('\n');
	}
}

//*****************************************

int d7p6(int n)
{
	if (1== n)
		return 1;
	return n*d7p6(n - 1);
}

//*****************************************

int d7p2(int n,int m)
{
	if (1 == m)
	{
		return n;
	}
	return n*d7p2(n, m - 1);
}

//*****************************************

int d7p3(int n)
{
	if (1 == n)
		return 1;
	return n % 10 + d7p3(n / 10);
}

//*****************************************

void printnum(int n, int m) //进制转换
{
	if (n == 0)
		return;
	printnum(n / m, m);
	putchar("0123456789ABCDEF"[n%m]);
}
//*****************************************
void d4p2()
{
	int i, j;
	int num = 0;
	int modflag = 1;
	int sum = 0;
	for (i = 0; i < 100000000; i++)
	{
		if (i%modflag == 0)
		{
			num++;
			modflag *= 10;
		}
		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, num);
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
		sum = 0;
	}
}
//*****************************************
int fib(int n)//非递归
{
	int i;
	int j;
	if (n <= 2)
	{
		return 1;
	}
	int an, an_1=1, an_2=1;
	for (i = 3; i <= n; i++)
	{
		an = an_1 + an_2;
		an_1=an_2;
		an_2 = an;
	}
	return an;
}
//*****************************************
int fib2(int n)//递归
{
	if (n <= 2)
		return 1;
	return fib2(n - 1) + fib2(n - 2);
}

//*****************************************

int mul(int n)
{
	if (n == 1)
		return 1;
	return n*mul(n - 1);
}
//*****************************************

int mpow(int n, int m)
{
	if (m == 1)
		return n;
	return n*mpow(n, m - 1);
}
//*****************************************
int sum(int n)//1729->1+7+2+9
{
	if (n == 1)
		return 1;
	return n % 10 + sum(n / 10);
}

//*****************************************
void reverse_string(char * string)
{
	if (!*string)
	{
		return;
	}
	char tmp;
	int len = strlen(string);

	tmp = string[0];
	string[0] = string[len - 1];
	string[len - 1] = 0;
	reverse_string(string + 1);
	string[len - 1] = tmp;
}
//*****************************************
void wordReverse(char * start, char * end)
{
	int length = end - start;
	int i;
	int tmp;
	for (i = 0; i < length / 2; i++)
	{
		tmp = start[i];
		start[i] = start[length - 1 - i];
		start[length - 1 - i] = tmp;
	}
}
void reverseString(char * str)
{
	int i;
	char*start = str;
	char*end;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			end = str + i;
			wordReverse(start, end);
			start = end + 1;
		}

	}
	wordReverse(start, str + i);
	wordReverse(str, str + i);
}

void reverseStringN(char * str)
{
	char *tmp = str;
	char *res = (char*)calloc(strlen(str) + 1,sizeof(char));
	while (tmp = strrchr(str, ' '))
	{
		strcat(res, tmp + 1);
		strcat(res, " ");
		*tmp = 0;
	}
	strcat(res, str);
	strcpy(str, res);
}

//*****************************************


int main()
{
	//d1p1();
	//d1p2(5);
	//d1p3();
	//d2p4(4,8);
	//d3p2();
	//d4p1(5);
	//d4p2();
	//printf("%d\n", d7p6(5));
	//printf("%d\n", d7p2(5,3));
	//printf("%d\n", d7p3(1729));
	//printnum(15461065, 16);
	//printf("%d\n", fib(5));
	//printf("%d\n", fib2(5));
	//printf("%d\n", mul(5));
	//printf("%d\n", mpow(5,3));
	//printf("%d\n", sum(1729));
	//char str[] = "abcdef";
	//reverse_string(str);
	//puts(str);
	char str[] = "i am a student";
	//reverseString(str);
	reverseStringN(str);

	puts(str);

	system("pause");
	return 0;
}