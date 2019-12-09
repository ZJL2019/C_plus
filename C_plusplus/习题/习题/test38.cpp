//36889 - 查找两个字符串a, b中的最长公共子串
//查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。

#include<iostream>
using namespace std;

#include<string>
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size()>b.size())
			swap(a, b);
		string str;
		for (int i = 0; i<a.size(); i++)
		{
			for (int j = i; j<a.size(); j++)
			{
				string tmp = a.substr(i, j - i + 1);
				if (int(b.find(tmp))<0)
				{
					break;
				}
				else if (str.size()<tmp.size())
				{
					str = tmp;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}