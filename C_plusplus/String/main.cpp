#include"String.h"
int main()
{
	String s1();
	String s2("hello");
	String s3(s2);
	String s4(10, '$');
	String s5(s2.begin(), s2.end());
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	return 0;
}