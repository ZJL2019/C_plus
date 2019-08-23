#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}

int main()
{
	/*unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	unsigned long *pulPtr;
	pulPtr = pulArray;
	*(pulPtr + 2) += 2;
	printf("%d,%d", *pulPtr, *(pulPtr + 2));*/

//*********************************************
	/*char *szStr = "abcde";
	szStr += 2;
	printf("%lu", szStr);*/

//*********************************************
	/*int i;
	char acNew[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 00, 0, 0, 0, 0 };
	for (i = 0; i < 10; i++)
	{
		acNew[i] = '0';
	}
	printf("%d", strlen(acNew));*/

//*********************************************
	/*int a[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	foo(a);
	printf("%d", a[2][1]);*/

//*********************************************
	/*int x = 0, y = 0, z = 0;
	z = (x == 1) && (y = 2);
	printf("%d", y);*/

//*********************************************
	/*int i = 10;
	long long t = sizeof(i++);
	printf("%d", i);*/

//*********************************************
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 0;
	scanf("%d", &k);
	int front = 0;
	int behind = sizeof(arr) / sizeof(arr[0]) - 1;
	while (front <= behind)
	{
		if (arr[front] + arr[behind] == k)
		{
			printf("%d,%d", front, behind);
			break;
		}
		else if (arr[front] + arr[behind] < k)
		{
			front++;
		}
		else
		{
			behind--;
		}
	}
	return 0;
}