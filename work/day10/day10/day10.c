#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* myString()
{
	char buffer[6] = { 0 };
	char *s = "Hello world!" ;
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}


int main()
{
	/*char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
		i++;
	}*/

//***********************************************
	/*int x[] = { 1, 2, 3, 4, 5, 6 };
	int *p = x;
	p += 2;
	printf("%d", *p);*/
//***********************************************
	/*char *s = "Hello world!";
	char buffer[6] = { 0 };
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	printf("%s", myString());*/
	
//***********************************************
	//int i = 1;
	//printf("%d ", sizeof(i++)); //如果sizeof的操作数是一个表达式的话，这个表达式时不会被计算的。
	//printf("%d ", i);

//***********************************************
	/*char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d", strlen(a));*/
//***********************************************
	char arr[] = { "abaccdeff" };
	char arr1[127] = { 0 };
	int i = 0;
	for (i = 0; i < sizeof(arr); i++)
	{
		arr1[arr[i]]++;
	}
	for (i = 1; i < 127; i++)
	{
		if (arr1[i] == 1)
		{
			printf("%c", i);
			break;
		}
	}
	return 0;
}