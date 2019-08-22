#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Mypow(int x, int y)
{
	int i = 0;
	int sum = 1;
	for (i = 0; i < y; i++)
	{
		sum *= x;
	}
	return sum;
}

int main()
{
	/*int arr[] = { 1, 2, 3, 4, 5 };
	int *ptr = (int *)(&arr + 1);
	printf("%d %d", *(arr + 1), *(ptr - 1));*/

//*******************************************
	//unsigned short sht = 0;
	//sht--;
	//printf("%d", sht);//2^16-1

//*******************************************
	/*printf("%c", 'B' + '8' - '3');*/

//*******************************************
	printf("%d", Mypow(2, 10));
	return 0;
}