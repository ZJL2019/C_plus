//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
//如果不存在则输出0。


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		int length = numbers.size() / 2;
		int tmp = 1;
		sort(numbers.begin(), numbers.end());
		auto it = numbers.begin();
		while (it!=numbers.end())
		{
			if (*it == *(it + 1))
			{
				tmp++;
			}
			else
			{
				tmp = 1;
			}
			if (tmp > length)
			{
				return *it;
			}
			it++;
		}
		return 0;
	}
};