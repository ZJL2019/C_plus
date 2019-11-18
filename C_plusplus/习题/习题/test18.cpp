//36915-求路径总数

//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
//沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
//即：只能往右和往下走，不能往左和往上走。

#include<iostream>
using namespace std;
int retSum(int n, int m)
{
	if (n == 1)
	{
		return m + 1;
	}
	else if (m == 1)
	{
		return n + 1;
	}
	else
	{
		return retSum(n, m - 1) + retSum(n, m - 1);
	}
}
int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		cout << retSum(n, m) << endl;
	}
	return 0;
}