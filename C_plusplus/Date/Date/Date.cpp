#include"Date.h"

Date::Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
{
	if (!(_year > 0 &&
		_month > 0 && _month < 13 &&
		_day > 0 && _day <= _GetDaysOfMonth(year, month)))
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
}


Date::Date(const Date& d)
			: _year(d._year)
			, _month(d._month)
			, _day(d._day)
{}


Date& Date:: operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

Date Date:: operator+(int days)
{
	if (days<0)
	{
		return *this - (0 - days);
	}
	Date temp(*this);
	temp._day += days;

	int daysofMonth = 0;
	while (temp._day > (daysofMonth = temp._GetDaysOfMonth(temp._year, temp._month)))
	{
		temp._day -= daysofMonth;
		temp._month++;
		if (temp._month > 12)
		{
			temp._year++;
			temp._month = 1;
		}
	}
	return temp;
}


Date Date:: operator-(int days)
{
	if (days < 0)
	{
		return *this + (0 - days);
	}
	Date temp(*this);
	temp._day -= days;

	while (temp._day <= 0)
	{
		temp._month--;
		if (temp._month < 0)
		{
			temp._year -= 1;
			temp._month = 12;
		}
		temp._day += temp._GetDaysOfMonth(temp._year, temp._month);
	}

	return temp;
}

int Date::operator-(const Date& d)
{
	Date minDate(*this);
	Date maxDate(d);
	if (*this > d)
	{
		swap(minDate, maxDate);
	}
	size_t count = 0;
	while (minDate != maxDate)
	{
		count++;
		minDate++;
	}
	return count;
}


Date& Date:: operator++()
{
	*this = *this + 1;
	return *this;
}

Date Date:: operator++(int)
{
	Date temp(*this);
	*this = *this + 1;
	return temp;
}

Date& Date:: operator--()
{
	*this = *this - 1;
	return *this;
}

Date Date:: operator--(int)
{
	Date temp = (*this);
	*this = *this + 1;
	return temp;
}

bool Date:: operator>(const Date& d)const
{
	if (_year > d._year ||
		_year == d._year&&_month > d._month ||
		_year == d._year&&_month == d._month&&_day > d._day)
	{
		return true;
	}
	return false;
}

bool Date::operator==(const Date& d)const
{
	return _year == d._year&&
		   _month == d._month&&
		   _day == d._day;
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}






int Date::_GetDaysOfMonth(int year, int month)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && IsLeapYear(year))
	{
		days[2] + 1;
	}
	return days[month];
}

bool Date::IsLeapYear(int year)
{
	if (0 == year % 4 && 0 != year % 100 || (0 == year % 400))
	{
		return true;
	}

	return false;
}

