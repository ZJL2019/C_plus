//36932 - 求最小公倍数

////正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		int temp = 0;
//		if (a < b)
//		{
//			int temp = a;
//			a = b;
//			b = temp;
//		}
//		if (a%b == 0)
//		{
//			cout << a << endl;
//			return 0;
//		}
//		else
//		{
//			temp = a;
//			while (a%b != 0)
//			{
//				a = a + temp;
//			}
//		}
//		cout << a << endl;
//		return 0;
//	}
//}



#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r = 0;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}