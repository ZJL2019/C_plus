#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define SIZE_A(arr) sizeof(arr)/sizeof(arr[0])
#define SIZE_B(brr) sizeof(brr)/sizeof(brr[0])
void Func(char str_arg[2])
{
	int m = sizeof(str_arg);
	int n = strlen(str_arg);
	printf("%d ", m);
	printf("%d ", n); 
}

int main()
{
	/*char str[] = { "hello" };
	Func(str);*/

//*************************************
	/*int a, x;
	for (a = 0, x = 0; a <= 1 && !x++; a++)
	{
		a++;
	}
	printf("%d %d", a, x);*/

//*************************************
	/*int a[5] = { 1, 2, 3, 4, 5 };
	int *p1=(int*)(&a + 1);
	int *p2 = (int*)((int)a + 1);
	int *p3 = (int*)(a + 1);
	printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);*/
//*************************************
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int brr[] = { 3, 10, -4, 7, 2 };
	int size_a = SIZE_A(arr);
	int size_b = SIZE_B(brr);
	int tmp = 0;
	int sum = 0;
	int i;
	for (i = 0; i < size_a; i++)
	{
		if (arr[i] == brr[0])
		{
			for (tmp = 0; tmp < size_b; tmp++)
			{
				sum += brr[tmp];
			}
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}