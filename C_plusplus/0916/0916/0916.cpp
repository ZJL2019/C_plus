#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
//初始化列表作用：初始化类中的成员变量，并且每个成员变量只能在初始化列表中出现一次
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day()//初始化列表
		, a(10)
		, b(_year)//避免使用变量初始化变量
		//每一个变量都需要在初始化列表中出现，如果未在初始化列表中初始化
		//则编译器调用默认构造函数初始化随机值
	{
		// 构造函数体中：赋初值
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

	const int a;
	int & b;
};
int main()
{
	Date d1(2019, 5, 15);
	const int a = 10;
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour=0 , int minute =0, int second=0 )
		//全缺省参数的初始化列表
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year, int month,int day)
		//如果类中有类类型的变量，则需要在类中存在其默认的构造函数
		//如果没有默认构造函数，则需要在此初始化列表中初始化
		: _year(year)
		, _month(month)
		, _day(day)
		//, _t(10,43,34)
	{
		cout << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1(2019, 9, 16);
	return 0;
}
#endif


#if 0
//建议：尽量不要使用成员初始化成员
//		初始化列表中成员出现次序最好与其在类中声明的次序保持一致
class Date
{
public:
	Date(int year, int day)
		: _year(year)
		//按变量定义顺序
		/*, _month(day)
		, _day(_day)*/
		//不按变量定义顺序
		, _day(day)
		, _month(_day)
		//因为初始化列表在初始化时，是根据变量定义顺序初始化
		//所以这样定义在_day未被初始化时，就用来初始化_month
	{
		cout << this << endl;
	}

	//拷贝构造函数使用初始化列表(本质：构造函数重载)
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 15);
	return 0;
}

#endif

#if 0
//单参类型的构造函数具有类型转化的作用，会调用构造函数生成无名对象
//explicit:修饰单参构造函数，意思是禁止单参构造函数类型转化的作用
class Date
{
public:
	explicit Date(int year)
		:_year(year)
	{
		cout << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = (d._month);
			_day = (d._day);
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018);
	//d1 = 2019;//单参类型，会调用类中的构造函数用2019生成一个无名对象，从而赋值
	return 0;
}
#endif


#if 0

//Date 总共创建了多少个有效对象？
//构造函数  拷贝构造函数  析构函数
//最终需要结果： 对象的个数----计数---int

int _count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}


	~Date()
	{
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << _count << endl;
}

int main()
{
	//统计创建多少个对象，可以根据调用多少次构造函数和拷贝构造函数以及析构函数来判断

	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << _count << endl;

	_count = 0;
	TestDate();
	//使用全局变量来保存对象个数
	//全局变量可以被修改，不安全
	_count = 100;
	cout << _count << endl;
	return 0;
}

#endif


#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}


	~Date()
	{
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;

public:
	static int _count;
};
//被静态修饰的成员变量只能在类外进行初始化
//如果被静态修饰的成员变量权限为私有，则类外无法访问，需使用接口访问

int Date::_count = 0;
void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::_count << endl;
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);

	//静态成员变量是所有类对象共享的成员变量
	//在静态存储区上
	//不属于某个具体的对象
	cout << &d1._count << "  " << &d2._count << endl;
	cout << sizeof(Date) << endl;

	cout << Date::_count << endl;
	TestDate();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		//普通成员函数既可以访问普通成员也可以访问静态成员
		_day++;
		cout << _count << endl;
		GetCount();
	}

	static int GetCount()
	{
		//静态成员函数没有this指针，所有无法访问非静态成员
		/*cout << this << endl;
		TestFunc();
		_day++;*/
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::GetCount() << endl;
}

int main()
{
	cout << Date::GetCount() << endl;
	Date d1(2019, 9, 16);
	Date d2(d1);

	cout << Date::GetCount() << endl;
	TestDate();
	cout << Date::GetCount() << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year,int month,int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		_count--;
	}

	static int GetCount()
	{
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

int main()
{
	int sum = 0;
	Date d1(2019, 9, 16);
	sum += Date::GetCount();

	Date d2(d1);
	sum += Date::GetCount();

	Date d3(d1);
	sum += Date::GetCount();

	return 0;
}
#endif


#if 0
//友元函数，不会将函数置于类中，而是给予一种可以调用类中成员变量的权限
class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
	
	friend void Print();
};


class Date
{
private:
	friend ostream& operator <<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// 将<<运算符如果重载成类的成员函数，其第一个参数为this
	// 因此调用方式与常规的打印方式反的
	/*void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
	}*/

	void TestFunc()
	{
		_t._hour = 1;
		_t._minute = 1;
		_t._second = 1;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	friend void Print();
};

//说明：必须重载成为全局函数
//		第一个参数必须是ostream&，第二个参数为要输出的内容(自定义类型的对象const)
//		必须要有返回值-----连续输出
//		尽量不要在该函数中做一些格式操作----比如换行
//		将输出运算符重载设置成类的友元函数

ostream& operator <<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void Print()
{
	Date d(2019, 9, 18);
	cout << d._year<< endl;


	Time t;
	cout << t._hour << endl;


}

int main()
{
	Date d(2019, 9, 18);
	//void operator<<(const Date this*,ostream &count)
	//正常重载<<,将其设为类内函数，在其参数列表第一个参数是this指针
	//导致重载后，<<指向相反
	/*d.operator<<(cout);
	d << cout;*/

	cout << d << endl;
	return 0;
}

#endif

#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{}

	class B
	{
	public:
		B(int b)
			: _b(b)
		{}

		void TestFunc()
		{
			A a(1);
			a._a = 10;
			A::_c = 10;
		}

	private:
		int _b;
	};

private:
	int _a;
	static int _c;
};

int A::_c = 0;


int main()
{
	A::B b(10);
	//注意：内部类是一个独立的类，没有包含在外部类中
	//只有在创建对应的对象时，需要加上作用域限定符
	cout << sizeof(A) << endl;
	return 0;
}
#endif


