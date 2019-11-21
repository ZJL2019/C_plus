//36910 - 求最大连续bit数
//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//
//输入 : 一个byte型的数字
//
// 输出 : 无
//
//返回 : 对应的二进制数字中1的最大连续数


#include<iostream>
using namespace std;
int main()
{
	int a;
	
	while (cin >> a)
	{
		int sum = 0;
		int count = 0;
		for (int i = a; i; i /= 2)
		{
			if (i % 2 == 1)
			{
				sum++;
			}
			else
			{
				sum = 0;
			}
			if (sum > count)
			{
				count = sum;
			}
		}
		cout << count << endl;

	}
	return 0;
}