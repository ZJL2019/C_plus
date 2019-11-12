//进制转换
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数


#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str = "0123456789ABCDEF";
	string s = "";
	int a, n;
	while (cin >> a >> n)
	{
		if (a < 0)
		{
			a = -a;
			cout << '-';
		}
		for (int i = a; i; i /= n)
		{
			s = str[i%n] + s;
		}
		cout << s << endl;
	}
	return 0;
}