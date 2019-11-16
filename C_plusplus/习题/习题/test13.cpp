//45846 --Fibonacci数列
//ibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
//在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，
//每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。


#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int N;
	int f, l = 0, r = 0,f1 = 0, f2 = 1;
	while (cin >> N)
	{
		while (1)
		{
			f = f1 + f2;
			f1 = f2;
			f2 = f;
			if (f < N)
				l = N - f;
			else
			{
				r = f - N;
				break;
			}	
		}
		cout << min(l, r) << endl;
	}
	return 0;
}