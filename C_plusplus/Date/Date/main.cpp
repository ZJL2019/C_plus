#include"Date.h"
int main()
{
	Date d1(2019, 9, 22);
	Date d2(2019, 11, 4);
	cout << d2 - d1 << endl;
	
	d1 = d1 - 999;
	cout << d1 << endl;
	return 0;
}
