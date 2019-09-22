#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);

	Date(const Date& d);

	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	friend ostream& operator<<(ostream& _cout, const Date& d);

private:
	int _GetDaysOfMonth(int year, int month);
	bool IsLeapYear(int year);
private:
	int _year;
	int _month;
	int _day;
};