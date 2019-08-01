#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void replace(char *a, int size, int count)
{
	int length = size + 2 * count;
	int right = length - 1;
	int cur = size - 1;
	while (cur < right)
	{
		if (a[cur] != ' ')
		{
			a[right--] = a[cur];
		}
		else
		{
			a[right--] = '0';
			a[right--] = '2';
			a[right--] = '%';
		}
		cur--;
	}
}
int main()
{
	/*typedef struct{
		int a;
		char b;
		short c;
		short d;
		}AA_t;
		printf("%d", sizeof(AA_t));*/
	/**************************************************************/
	//char str[6] = { '\0' };
	//char str[7] = { "string" };
	/*char str[10];
	str = "string";*/ //¸³³õÖµ´íÎó
	/**************************************************************/
	/*const char *p = "hello!";
	printf("%c\n", *p);*/
	/**************************************************************/
	//int a = 10;
	//a -= a / 3;//7
	//a *= a;//49
	//a += a;//98
	//printf("%d\n", a += a *= a -= a / 3);
	/**************************************************************/
	/*int i = 0;
	while (i<10)
	{
	if (i < 1)
	continue;
	if (i == 5)
	break;
	i++;
	}*/
	/**************************************************************/
	char a[30] = { "abc defgx yz" };
	int count = 0;
	int size = strlen(a);
	for (int i = 0; i < size; i++)
	{
		if (a[i] == ' ')
		{
			count++;
		}
	}
	replace(a, size, count);
	puts(a);
	return 0;
}