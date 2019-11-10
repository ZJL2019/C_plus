//【排序子序列】牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 他现在有一个任
//务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出2

#include<iostream>
using namespace std;

bool IfChangNow(int pre, int cur, int next)
{
	if ((cur > pre&&cur > next) || (cur < pre&&cur < next))
	{
		return true;
	}
	return false;
}

int main()
{
	int n, arr[100000];
	while (cin >> n)
	{
		int num = 1;
		int pre = 0;
		if (n < 3)
		{
			cout << num << endl;
		}
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i] == arr[i + 1])
			{
				continue;
			}
			else
			{
				if (IfChangNow(arr[pre], arr[i], arr[i + 1]))
				{
					num++;
					pre = ++i;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}