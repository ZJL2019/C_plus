//69390-删除公共字符
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变
//成”Thy r stdnts.”

#include<iostream>
using namespace std;
#include<string>

void RemoveStr(string& s1, string& s2)
{
	char str[255] = { 0 };
	for (int i = 0; i < s2.length(); i++)
	{
		str[s2[i]]++;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (str[s1[i]]==0)
		{
			cout << s1[i];
		}
	}
	cout << endl;
}

int main()
{
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2))
	{
		RemoveStr(str1, str2);
	}
	return 0;
}
