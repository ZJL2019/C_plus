//45844 --两种排序方法

//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//
//如果根据长度排列而不是字典序排列输出"lengths",
//
//如果两种方式都符合输出"both"，否则输出"none"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<string.h>
void IsSortString(vector<string>& vs)
{
	int size = vs.size();
	int flag1 = 0,flag2=0;
	for (int i = 0; i < size-1; i++)
	{
		if (strcmp(vs[i].c_str(), vs[i + 1].c_str()) <= 0)
		{
			flag1++;
		}
		if (vs[i].length() <= vs[i + 1].length())
		{
			flag2++;
		}
	}
	if (flag1==size-1&&flag2==size-1)
	{
		cout << "both" << endl;
	}
	else if (flag1==size-1)
	{
		cout << "lexicographically" << endl;
	}
	else if (flag2==size-1)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
}
int main()
{
	vector<string> vs;
	string temp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vs.push_back(temp);
	}
	IsSortString(vs);
	return 0;
}