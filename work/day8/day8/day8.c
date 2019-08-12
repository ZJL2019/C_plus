#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define SIZE(A) sizeof(arr)/sizeof(arr[0])
int main()
{
	//char acX[] = { "abcdefg" };
	//char acY[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };//无'\0'所以返回值不确定
	//printf("%d，%d", strlen(acX), strlen(acY));

	//******************************************************************************
	//char s[] = { "\\123456\123456\t" };//转义字符\xxx,代表3位八进制
	//printf("%d\n", strlen(s));
	//printf("%d", '\123');

	//******************************************************************************
	/*int s = 0, n;
	for (n = 0; n < 4; n++)
	{
	switch (n)
	{
	default:s += 4;
	case 1:s += 1;
	case 2:s += 2;
	case 3:s += 3;
	}
	}
	printf("%d\n", s);*/

	//******************************************************************************
	/*char *pcColor = "blue1";
	char acColor[] = "blue1";
	printf("%d\n", strlen(pcColor));
	printf("%d\n", strlen(acColor));
	printf("%d\n", sizeof(pcColor));
	printf("%d\n", sizeof(acColor));*/

	//******************************************************************************
	/*unsigned long  ulA = 0x11000000;
	printf("%x\n", *(unsigned char*)&ulA);*/

	//******************************************************************************
	int arr[] = { 1, 2, 2, 2, 2, 2, 2, 4, 2,0 };
	int tmp = SIZE(A) / 2;
	int arr2[10] = { 0 };
	int i;
	for (i = 0; i < SIZE(A); i++)
	{
		arr2[arr[i]]++;
	}
	for (i = 0; i < 10; i++)
	{
		if (arr2[i]>tmp)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (i == 10)
	{
		printf("No find\n");
	}
	return 0;
}