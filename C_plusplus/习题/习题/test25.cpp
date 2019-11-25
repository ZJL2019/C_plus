//36898-参数解析
//在命令行输入如下命令：
//
//xcopy / s c : \ d : \，
//
//各个参数如下：
//
//参数1：命令字xcopy
//
//参数2：字符串 / s
//
//参数3：字符串c : \
//
//参数4 : 字符串d : \
//
// 请编写一个参数解析程序，实现将命令行各个参数解析出来。
//
//
//
// 解析规则：
//
// 1.参数分隔符为空格
// 2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
// 3.参数不定长
// 4.输入由用例保证，不会出现不符合要求的输入

#include<iostream>
using namespace std;
#include<vector>
#include<string>
int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> vs;
		string temp = "";
		int flag = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if ('"' == s[i])
			{
				flag = ~flag;
			}
			else if (s[i] == ' '&&flag == 0)
			{
				vs.push_back(temp);
				temp = "";
			}
			else
			{
				temp += s[i];
			}
		}
		vs.push_back(temp);
		cout << vs.size() << endl;
		for (int i = 0; i<vs.size(); i++)
		{
			cout << vs[i] << endl;
		}
	}
	return 0;
}