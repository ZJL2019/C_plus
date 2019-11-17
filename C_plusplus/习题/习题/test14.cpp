//36939 - 合法括号序列判断

//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
#include<iostream>
using namespace std;
#include<string>
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
				if (sc.empty() || sc.top() != '(')
				{
					return false;
				}

				else
				{
					sc.pop();
				}
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};