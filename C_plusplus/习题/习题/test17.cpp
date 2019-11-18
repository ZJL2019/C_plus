//25083 --另类加法
//请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。
//
//给定两个int A和B。请返回A＋B的值

#include<iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, carry = 0;
		while (B != 0)
		{
			sum = A^B;
			carry = (A&B) <<1;
			A = sum;
			B = carry;
		}
		return sum;

	}
};