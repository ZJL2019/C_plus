#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Func(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;//赋值运算优先级大于逗号运算
	return(a);
}
int fun(int x)
{
	int count = 0;
	while (x){
		count++;
		x = x&(x - 1);
	}
	return count;
}
int main()
{
	/*int a = 2,i,k;
	for (i = 0; i < 2; i++)
	{
		k = Func(a++);
	}
	printf("%d", k);*/
//*****************************************

	/*printf("%d", fun(2019));*/
//*****************************************
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
	printf("%d", s);*/

	char str[] = { "*****as****adadq*****" };
	int i = 0;
	int j = 0;
	int flag = 0;
	while (str[i] != '\0')
	{
		if (!flag&&str[i] == '*')
		{
			i++;
		}
		else if (!flag&&str[i] != '*')
		{
			flag = 1;
			str[j++] = str[i++];
		}
		else if (flag&&str[i] == '*')
		{
			flag = 0;
			str[j++] = str[i++];
		}
		else
		{
			str[j++] = str[i++];
			flag = 1;
		}
	}
	if (str[j - 1] == '*')
	{
		str[j - 1] = '\0';
	}
	else
	{
		str[j] = '\0';
	}
	printf("%s", str);
	return 0;
}