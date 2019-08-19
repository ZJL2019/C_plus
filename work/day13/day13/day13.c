#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define sum(a,b,c) a+b+c
int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}

int func()
{
	int i, j,k = 0 ;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	/*int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *p = a;
	printf("%d", a);*/

//*************************************
	/*int a[] = { 0, 2, 4, 6, 8,10 };
	int *p = a + 1;
	printf("%d", (*--p));*/

//*************************************
	/*int c[] = { 1, 3, 5 };
	int *k = c + 1;
	printf("%d", *++k);*/

//*************************************
	/*int i = 3;
	int j = 2;
	printf("%d", i*sum(i, (i + j), j));*/

//*************************************
	//printf("%d", f(1));

//*************************************
	/*printf("%d", (func()));*/

//*************************************
	char a[] = { "They are students." };
	char b[] = { "aeiou" };
	int i = 0;
	int j = 0;
	while (a[j])
	{
		for (i = 0; a[i]; i++)
		{
			if (a[i] == b[j])
			{
				int k = i;
				while (a[k])
				{
					a[k] = a[k + 1];
					k++;
				}
				a[k] = 0;
			}
		}
		j++;
	}
	printf("%s", a);
	return 0;
}