
//36884 - 查找组成一个偶数最接近的两个素数
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
//本题目要求输出组成指定偶数的两个素数差值最小的素数对


#include<iostream>
using namespace std;
#include<algorithm>
bool IsPir(int n)
{
	int tmp = sqrt(n);
	for (int i = 2; i <= tmp; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int k1 = n / 2;
		int i = 0;
		for (i = k1; i>0; i--)
		{
			if (IsPir(i) && IsPir(n - i))
			{
				break;
			}
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}