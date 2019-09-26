#include<iostream>
using namespace std;

#include<string>

void TestString1()
{
	string s1;
	string s2("hello");//以str为初值 (长度任意),
	string s3(10, '$');//以length为长度的ch的拷贝（即length个ch）
	string s4(s3);//将一个对象拷贝赋值给另一个对象
	
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

int main()
{
	return 0;
}