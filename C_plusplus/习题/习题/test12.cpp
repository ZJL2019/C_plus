//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
	int StrToInt(string& str)
	{
		long ret = 0;
		int flag = 1;
		int i = 0;
		if (str[0] == '0')
			return 0;
		if (str[0] == '-')
		{
			flag = -1;
			i = 1;
		}
		if (str[0] == '+')
		{
			i = 1;
		}
		for (i; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				ret = ret * 10 + (str[i] - '0');
			}
			else
			{
				return 0;
			}
		}
		ret = ret*flag;
		if (ret >= pow(-2, 31) && ret < pow(2, 31))
		{
			return ret;
		}
		return 0;
	}
};
