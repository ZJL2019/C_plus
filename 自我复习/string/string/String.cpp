#include "String.hpp"

void TestString1()
{
	char str[] = { "world" };
	String s1;
	String s2("hello");
	String s3(s2);
	String s4(10, '$');
	String s5(s2.begin(), s2.end());
	String s6 = s5;

	auto it = s4.begin();
	while (it != s4.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	cout << s6.empty() << endl;
	cout << s6[1] << endl;
	s6 += 'c';
	s6 += "hhh";
	s6 += s5;
	cout << s6 << endl;
	if (s6 != s5)
	{
		cout << 1 << endl;
	}
}

void TestString2()
{
	String s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.push_back('!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(15, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '&');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void TestString3()
{
	String s("hello");
	size_t pos1 = s.find('l');
	cout << pos1 << endl;

	size_t pos2 = s.rfind('l');
	cout << pos2 << endl;

	cout << s.substr(pos1) << endl;
}

int main()
{
	TestString1();
	TestString2();
	TestString3();
	return 0;
}