//36897 - 计算日期到天数转换
//根据输入的日期，计算是这一年的第几天。。
//
//详细描述：
//
//输入某年某月某日，判断这一天是这一年的第几天？。

#include <iostream>
using namespace std;
int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		if (month == 1)
		{
			cout << day << endl;
			continue;
		}
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}