//36886-查找输入整数二进制中1的个数
#include<iostream>
using namespace std;
int main(){
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = n; i; i /= 2)
		{
			if (i % 2 == 1)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}