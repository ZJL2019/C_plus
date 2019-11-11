//读入一个字符串str，输出字符串str中的连续最长的数字串

#include<iostream>
using namespace std;
#include<string>

int main()
{
	string cur, ret,s;
	while (getline(cin, s))
	{
		for (int i = 0; i <= s.length(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				cur += s[i];
			}
			else
			{
				if (ret.length() < cur.length())
				{
					ret = cur;
				}
				cur = "";
			}
		}
		cout << ret << endl;
	}
	return 0;
}
