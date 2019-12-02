//完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
//
//它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
//
//例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1 + 2 + 4 + 7 + 14 = 28。
//
//给定函数count(int n), 用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
//
//返回n以内完全数的个数。 异常情况返回 - 1



#include<iostream>
#include<algorithm>
using namespace std;
int count(int n) {
	int cnt = 0;
	if ((n < 0) | (n>500000))
		return -1;
	else {
		for (int i = 2; i <= n; i++) {
			int sum = 0;
			int sq = sqrt(i);
			for (int j = 2; j <= sq; j++) {
				if (i%j == 0) 
				{
					if (i / j == j)
						sum += j;
					else
						sum += j + (i / j);
				}
			}
			if (sum + 1 == i)
				cnt++;
		}
		return cnt;
	}
}
int main() 
{
	int input;
	while (cin >> input)
		cout << count(input) << endl;
	return 0;
}