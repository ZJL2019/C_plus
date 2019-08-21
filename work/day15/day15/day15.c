#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	/*char str[] =  "ABCDEFG" ;
	char *p1, *p2;
	p1 = "abcd";
	p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s", str);*/

//************************************
	/*unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char*)&a;
	printf("%08x,%08x", i, *b);*/

//************************************
	/*int j = 4;
	int i = j;
	for (; i <= 2*j; i++)
	{
		switch (i/j)
		{
		case 0:
		case 1:
			printf("*");
			break;
		case 2:
			printf("#");
			break;
		}
	}*/

//************************************
	int x = 1, y = 012;
	printf("%d", y*x++);
	return 0;
}