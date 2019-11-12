//69389-倒置字符串
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I


#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				string str_r = str.substr(i + 1);
				cout << str_r << " ";
				str.resize(i);
			}
		}
		cout << str;
	}
	return 0;
}
