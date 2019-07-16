#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int __main()
{
	int m = 1;
	int n = 7;
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;

}


#include<stdint.h>
int ___main()//回文
{
	int n;
	int sum = 0;
	int m;
	int i;
	scanf("%d%d", &n, &m);
	for (i = n; i; i /= m)
	{
		sum = sum * 10 + i % m;
	}
	printf("%d在%d进制下是%d\n", n, m, sum);

	if (sum == n)
	{
		printf("%d在%d进制下是回文数\n", n, m);
	}
	else
		printf("%d在%d进制下不是回文数\n", n, m);
	system("pause");
	return 0;
}


int main()
{
	int line, pos, count = 0;//目标查找数前一行的元素个数
	int n = 1;
	scanf("%d", &n);
	for (line = 1; count + line < n; line++)//count+line包括目标数所在行数一共有多少个元素
	{
		count += line;
	}
	pos = n - count;//这一行的第几个
	if (line % 2 == 0)
	{
		printf("第%d个数是%d/%d,在第%d行，第%d个。\n", n, pos, (line + 1 - pos), line, pos);
	}
	else
		printf("第%d个数是%d/%d,在第%d行，第%d个。\n", n, (line + 1 - pos), pos, line, pos);

	system("pause");
	return 0;
}