#include<iostream>
using namespace std;

#include<string>


//(constructor)
void TestString1()
{
	string s1; //string();
	string s2("hello");//string (const char* s);
	string s3(10, '$');//string (size_t n, char c);
	string s4(s3);//string (const string& str);

	cin >> s1; //istream& operator>> (istream& is, string& str);
	cout << s1 << endl;//ostream& operator<< (ostream& os, const string& str);
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//Capacity
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;//size_t size（）const;
	cout << s.length() << endl;//size_t length() const;
	cout << s.capacity() << endl;//size_t capacity() const;

	if (s.empty())//bool empty() const;
	{
		cout << "NULL String" << endl;
	}
	else
	{
		cout << "Not NULL string" << endl;
	}
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
	{
		cout << "NULL String" << endl;
	}
	else
	{
		cout << "Not NULL Stirng" << endl;
	}
}
//resize / reserve
//void resize (size_t n);
//void resize (size_t n, char c);
//		功能：将string类中的有效字符改变到n个
//			1、如果n大于原来的长度，则多出的部分使用c来填充
//			2、如果n小于原来的长度，则多余的将被删除
//		注意：
//			1、如果是将string类中的有效元素缩小，只改变有效元素的个数，不会改变底层空间大小
//			2、如果是将string类中的有效元素增多，可能需要扩容

void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	return 0;
}