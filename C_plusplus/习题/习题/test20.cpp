#include<iostream>
using namespace std;
#include<string>
void GetPwdSecurityLevel(string pPasswordStr)
{
	int SumGrades = 0;
	int size = pPasswordStr.size();
	string& s = pPasswordStr;
	int Sch = 0;
	int Bch = 0;
	int Nch = 0;
	int Cch = 0;
	//ÅÐ¶Ï³¤¶È
	if (size <= 4)
	{
		SumGrades += 5;
	}
	else if (size >= 5 && size <= 7)
	{
		SumGrades += 10;
	}
	else
	{
		SumGrades += 25;
	}
	//ÅÐ¶Ï×ÖÄ¸
	for (int i = 0; i<size; i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
		{
			Sch++;
		}
		if (s[i]>+'A'&&s[i] <= 'Z')
		{
			Bch++;
		}
	}
	if (Sch == 0 && Bch == 0)
	{
		SumGrades += 0;
	}
	else if (Sch == 0 || Bch == 0)
	{
		SumGrades += 10;
	}
	else
	{
		SumGrades += 20;
	}
	//ÅÐ¶ÏÊý×Ö
	for (int i = 0; i<size; i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			Nch++;
		}
	}
	if (Nch == 0)
	{
		SumGrades += 0;
	}
	else if (Nch == 1)
	{
		SumGrades += 10;
	}
	else
	{
		SumGrades += 25;
	}
	//ÅÐ¶Ï·ûºÅ
	for (int i = 0; i<size; i++)
	{
		if ((s[i] >= '!'&&s[i] <= '/') || (s[i] >= ':'&&s[i] <= '@') || (s[i] >= '{'&&s[i] <= '~'))
		{
			Cch++;
		}
	}
	if (Cch == 0)
	{
		SumGrades += 0;
	}
	else if (Cch == 1)
	{
		SumGrades += 10;
	}
	else
	{
		SumGrades += 25;
	}
	//ÅÐ¶Ï½±Àø
	if ((Sch != 0 || Bch != 0) && Nch != 0)
	{
		SumGrades += 2;
	}
	else if ((Sch != 0 || Bch != 0) && Nch != 0 && Cch != 0)
	{
		SumGrades += 3;
	}
	else if (Sch != 0 && Bch != 0 && Nch != 0 && Cch != 0)
	{
		SumGrades += 5;
	}
	if (SumGrades >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	else if (SumGrades >= 80)
	{
		cout << "SECURE" << endl;
	}
	else if (SumGrades >= 70)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (SumGrades >= 60)
	{
		cout << "STRONG" << endl;
	}
	else if (SumGrades >= 50)
	{
		cout << "AVERAGE" << endl;
	}
	else if (SumGrades >= 25)
	{
		cout << "WEAK" << endl;
	}
	else if (SumGrades >= 0)
	{
		cout << "VERY_WEAK" << endl;
	}
}
int main()
{
	string passwordStr;
	while (cin >> passwordStr)
	{
		GetPwdSecurityLevel(passwordStr);
	}
	return 0;
}