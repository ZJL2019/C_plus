#include<iostream>
using namespace std;



#if 0
//构造函数只在对象的生命周期中出现一次
//因为对象只有一次初始化
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)//初始化赋值函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()//输出函数
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	
	int a;
	a = 10;

	int b = 10;
	int c = (10);


	Date d3;
	d3.PrintDate();
	//用户在类中定义无参的构造函数，并默认赋值
	//当定义对象没有初始化时，此时对象调用用户自定义的无参构造函数

	Date d2(2019, 9, 14);
	d2.PrintDate();
	//用户在类中定义了构造函数，则类中不再出现默认的无参构造函数
	//而是在定义对象时，调用自定义构造函数

	// 类中如果没有显式(用户是否直接定义)任何构造函数，
	// 编译器将会生成一个默认的构造函数---无参构造函数

	//Date d1;
	//先定义后初始化，类中默认无参构造函数
	//当类中定义了有参数的构造函数，则这种初始化方法不可用，
	//因为其无参与有参的构造函数发生冲突

	/*d1.SetDate(2019, 9, 14);
	d1.PrintDate();*/


	return 0;
}

#endif

#if 0
class Time
{
public:
	//全缺省构造函数
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		cout << "Time(int,int,int):" << endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	//在Date类中有类类型的成员变量_t,虽然在创建对象d1时，
	//Date类中没有用户自定义的构造函数，但Date类中有系统生成的默认构造函数
	//所以_year,_month,_day被随机数初始化，而类类型成员变量_t,在Time类中有
	//用户自定义的构造函数，所以_t在调用构造函数时调用了用户自定义的构造函数

	return 0;
}
#endif


#if  0
#include<assert.h>
#include<malloc.h>


typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		cout << "SeqLIist(size_t)" << endl;

		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
			return;
		}
		capacity = 0;
		_size = 0;
	}
	/*~SeqList()
	{
		cout << "~SeqList()" << endl;
	}*/
	~SeqList()
	{
		cout << "~SeqList()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqList()
{
	SeqList s;
}

int main()
{
	TestSeqList();
	//对象在销毁时会调用析构函数，完成一些类的资源清理工作
	_CrtDumpMemoryLeaks();//检测是否发生内存泄漏
	//函数一旦调用堆，或其他资源需要手动释放时，默认析构函数无法实现
	//此时需要用户自定义析构函数
	return 0;
}
#endif

//关于编译器生成的默认的析构函数


#if 0
class String
{
public:
	String(char* str = "")
	{
		cout << "String(char*)" << endl;
		if (nullptr == str)
		{
			str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String():" << endl;
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	String _gender;
	int _age;
};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();
	return 0;
}
#endif

#if 0
//拷贝构造函数：用户没有显示提供，编译器会生成一个默认的拷贝构造函数
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
	String(const String& d)
	{
		_str = d._str;
		_str = (char*)malloc(strlen(_str) + 1);
		strcpy(_str, d._str);
		*_str = *(d._str);
	}
private:
	char* _str;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
}

void TestString()
{
	String s1("hello");
	String s2(s1);
}

int main()
{
	TestString();
	//在使用默认拷贝函数时，是浅拷贝
	//多个对象共用同一块内存空间，在销毁时，一份空间被释放多次，而导致程序崩溃
	//如果类中管理资源，该类的拷贝构造函数必须由用户显式提供

	TestDate();
	//未使用堆等资源，则不牵扯
	return 0;
}
#endif


#if 0
//用户自定义拷贝函数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)//自定义拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
			_year = year;
			_month = month;
			_day = day;
		}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year || _year == d._year&&_month > d._month || _year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return!(*this == d);
	}

	bool IsGreater(const Date& d)
	{
		if (_year > d._year || _year == d._year&&_month > d._month || _year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}

		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 20;
	if (a > b)
		cout << "a" << endl;
	else
		cout << "b" << endl;

	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2020, 9, 14);

	d3 = d1;

	if (d1 > d2)
	{
		d1.PrintDate();
	}
	else
	{
		d2.PrintDate();
	}
	return 0;
}
#endif


#if 0
//赋值运算符重载：如果用户没有显式提供，编译器将会生成一份默认的赋值运算符重载
//如果一个类中涉及到资源管理，用户必须提供赋值运算符重载
//因为：如果不提供赋值运算符重载，编译器自己生成的默认赋值运算符重载，功能上相当于编译器自己生成的默认拷贝构造函数
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	
	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2("world");

	s1 = s2;
}

int main()
{
	TestString();
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//s3=s2=s1;
	//需要重载赋值运算符
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//前置++
	//未加限制
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++

	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;

		return temp;
	}

	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;

		return temp;
	}

	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	a = b = c;


	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2019, 9, 13);

	d2 = ++d3;//给d3加1之后的结果给d2进行赋值
	d2.operator=(d3.operator++());
	
	d2 = d3++;//加之前的旧值给d2赋值
	d2.operator=(d3.operator++(0));
	//赋值运算符重载后，调用本质是调用当前对象中的operator=函数
	d2 = d1;
	d2.operator=(d1);//operator(&d2,&d1)


	//连续赋值时，是先将d1赋值给d2，再将d2赋值给d3
	d3 = d2 = d1;
	d3.operator=(d2.operator=(d1));

	//创建引用变量引用自身，进行自己给自己赋值，是不允许的
	Date& d4 = d3;
	
	d4 = d3;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date* operator&()//取地址符重载
	{
		_day++;
		return this;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 14);
	cout << &d1 << endl;

	const Date d2(2019, 9, 15);
	cout << &d2 << endl;
	return 0;
}
#endif


#if 0
//被const修饰的成员函数，称作为const类型的成员函数

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date* operator&()
	{
		_day++;
		return this;
	}

	//在const成员函数中，不能修改类的任何成员变量
	//只能修改被mutable修饰的变量
	//const修饰的是this指针
	void PrintDate()const
	{
		_day++;

		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	mutable int _day;
};
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}


	// 	void PrintDate()
	// 	{
	// 		_day++;
	// 		cout << _year << "-" << _month << "-" << _day << endl;
	// 	}

	void PrintDate()/*const*/
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	mutable int _day;
};

int main()
{
	//const类型的对象不能调用普通类型的成员函数
	//原因：const类型对象中的成员不允许被修改
	//		在普通类型成员函数中可以修改成员变量
	//如果编译器允许const类型对象调用普通类型成员，在普通类型成员中可能会修改const类型对象中的内容
	//操作不安全

	const Date d1(2019, 9, 14);
	//d1.PrintDate();

	//普通类型的对象既可以调用普通类型的成员函数，也可以调用const类型的成员函数
	//普通类型对象可读可写
	Date d2(2019, 9, 15);
	d2.PrintDate();
	return;
}

#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	// const类型的成员函数是只读的函数，不能修改对象中的任何成员变量
	// 除非该成员变量被mutable
	// const Date* const
	void TestFunc1()const
	{
		//TestFunc2(/*this*/);
	}

	// 普通类型的成员函数是可读写的函数
	// 可能会在该成员函数中修改成员变量
	// Date* const 
	void TestFunc2()
	{}
	const Date* operator&()const//const修饰的是this指针
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 14);
	const Date d2(2019, 9, 15);

	cout << &d1 << endl;
	cout << &d2 << endl;
	return 0;
}
#endif