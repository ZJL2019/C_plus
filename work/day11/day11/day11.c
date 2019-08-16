#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fun(char *s)
{
	char *p = s;
	while (*p != '\0'){
		p++;
	}
	return (p - s);
}
int main()
{
	//printf("%d\n", fun("goodbye!"));

//*******************************************
	//unsigned char a = 0xA5;
	//printf("%0x\n", ~a);//FFFFFF5A
	//unsigned char b = ~a >> 4 + 1;//FA--->-6
	//printf("%d\n", b);//250

//*******************************************
	/*const int i = 0;
	int *j = (int*)&i;
	*j = 1;
	printf("%d,%d", i, *j);*/

//*******************************************
	char a[] = { "qywyer23tdd" };
	char b[127] = { 0 };
	int i, j;
	for (i = 0; i < sizeof(a)-1; i++)
	{
		b[a[i]]++;
		if (b[a[i]] == 2)
		{
			printf("%c", a[i]);
			break;
		}
	}
	return 0;
}