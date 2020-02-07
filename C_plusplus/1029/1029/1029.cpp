#include <iostream>
using namespace std;

#if 0
// 非类型模板参数
// C++11: array

namespace bite
{
	template<class T, size_t N>
	class array
	{
	public:
		void push_back(const T& data)
		{
			// N = 10;
			_array[_size++] = data;
		}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		bool empty()const
		{
			return 0 == _size;
		}

		size_t size()const
		{
			return _size;
		}
	private:
		T _array[N];
		size_t _size;
	};
}



int main()
{
	int a = 10;
	int b = 20;

	// 非类型模板参数必须在编译其确认其结果
	//bite::array<int, a+b> arr;
	bite::array<int, 10 + 20> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	return 0;
}
#endif

#if 0
template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}

// 函数模板的特化
// template<>
// char*& Max<char*>(char*& left, char*& right)
// {
// 	if (strcmp(left, right) > 0)
// 		return left;
// 
// 	return right;
// }

// 函数模板一般不需要特化，直接将不能处理类型的具体函数给出
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "/" << d._month << "/" << d._day;
		return _cout;
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

	cout << Max(a, b) << endl;  //Max<int>
	cout << Max(b, a) << endl;

	Date d1(2019, 10, 22);
	Date d2(2019, 10, 23);

	cout << Max(d1, d2) << endl;
	cout << Max(d2, d1) << endl;

	char* p1 = "world";
	char* p2 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

template<>
const char*& Max<const char*&>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}


int main()
{
	int a = 10;
	int b = 20;

	Max(a, b);
	Max(10, 20);

	char* p1 = "world";
	char* p2 = "hello";
	cout << Max(p1, p2) << endl;
	cout << Max(p2, p1) << endl;
	return 0;
}
#endif

#if 0
template<class T>
void Test(const T& p) // const int*& p<---错误 int*& const p
{
	*p = 100;

	int b = 20;
	p = &b;
}

int main()
{
	int a = 10;
	int* pa = &a;

	const int b1 = 10;
	int const b2 = 20;

	Test(pa); // int*
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


// 全特化---对所有类型参数进行特化
template<>
class Data<int, int>
{
public:
	Data()
	{
		cout << "Data<int, int>" << endl;
	}
private:
	int _d1;
	int _d2;
};


int main()
{
	Data<int, double> d1;
	Data<int, int> d2;
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};


// 偏特化：部分特化--->将模板参数列表中部分参数类型化
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>" << endl;
	}

private:
	T1 _d1;
	int _d2;
};


int main()
{
	Data<int, double> d1;
	Data<int, int> d2;
	Data<double, int> d3;
	return 0;
}
#endif

#if 0
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 偏特化：让模板参数列表中的类型限制更加严格
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1* _d1;
	T2* _d2;
};


int main()
{
	Data<int*, int> d1;
	Data<int, int*> d2;
	Data<int*, int*> d3;
	Data<int*, double*> d4;
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}


	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}

		return *this;
	}

	~String()
	{
		delete[] _str;
	}

private:
	char* _str;
};

// 写一个通用的拷贝函数，要求：效率尽可能高
// 对于内置类型-->O(1)
// 缺陷：浅拷贝
template<class T>
void Copy1(T* dst, T* src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

// 优点：一定不会出错
// 缺陷：O(N)
template<class T>
void Copy2(T* dst, T* src, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}


bool IsPODType(const char* strType)
{
	// 此处可以将所有的内置类型枚举出来
	const char* strTypes[] = { "char", "short", "int", "long", "long long", "float", "double" };
	for (auto e : strTypes)
	{
		if (strcmp(strType, e) == 0)
			return true;
	}

	return false;
}


bool IsPODType(const char* strType)
{
	//此处可以将所有的内置类型枚举出来
	const char* strTypes[] = { "char", "short", "int", "long", "long long", "float", "double" };
	for (auto e : strTypes)
	{
		if (strcmp(strType, e) == 0)
		{
			return true;
		}
	}
	return false;
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// 通过typeid可以将T的实际类型按照字符串的方式返回
	if (IsPODType(typeid(T).name()))
	{
		// T的类型：内置类型
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}



void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy(array2, array1, 10);

	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);
}

int main()
{
	TestCopy();
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}


	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}

		return *this;
	}

	~String()
	{
		delete[] _str;
	}

private:
	char* _str;
};


// 确认T到底是否为内置类型？
// 是
// 不是
// 对应内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

// 对应自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;  // plain old data
};


template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

// ...

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	// 通过typeid可以将T的实际类型按照字符串的方式返回
	if (TypeTraits<T>::PODTYPE::Get())
	{
		// T的类型：内置类型
		memcpy(dst, src, sizeof(T)*size);
	}
	else
	{
		// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}


void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy(array2, array1, 10);

	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);
}

int main()
{
	TestCopy();
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}


	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* str = new char[strlen(s._str) + 1];
			strcpy(str, s._str);
			delete[] _str;
			_str = str;
		}

		return *this;
	}

	~String()
	{
		delete[] _str;
	}

private:
	char* _str;
};


// 确认T到底是否为内置类型？
// 是
// 不是
// 对应内置类型
struct TrueType
{};

// 对应自定义类型
struct FalseType
{};

template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;  // plain old data
};


template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

// ...

template<class T>
void Copy(T* dst, T* src, size_t size, TrueType)
{
	// T的类型：内置类型
	memcpy(dst, src, sizeof(T)*size);
}

template<class T>
void Copy(T* dst, T* src, size_t size, FalseType)
{
	// T的类型：自定义类型---原因：自定义类型中可能会存在浅拷贝
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODTYPE());
}


void TestCopy()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[10];
	Copy(array2, array1, 10);

	String s1[3] = { "1111", "2222", "3333" };
	String s2[3];
	Copy(s2, s1, 3);
}

int main()
{
	TestCopy();
	return 0;
}
#endif

#include "aaa.h"
// 15  

//int Add(int left, int right);
/*
template<class T>
T Sub(const T& left, const T& right);
*/

#if 0
// 7:50  
#include "aaa.hpp"

int main()
{
	//Add(10, 20);
	Sub(10, 20);
	Sub(10.0, 20.0);
	return 0;
}
#endif

#if 0
int main()
{
	printf("%d, %d", "hello", 12.34);
	int a = 0;
	scanf("%d", &a);
	return 0;
}
#endif

#if 0
#include <string>

int main()
{
	cerr << "error1";
	cerr << "error2" << endl;

	clog << "2019-10-27";
	clog << "2019-10-27" << endl;

	int a;
	double b;
	string s;

	cin >> a;
	cin >> b >> s;

	cout << a << endl;
	cout << b << " " << s << endl;

	// IO类型算法
	// 循环输入
	// 整行接受 while(getline(cin, s)){}
	// while(cin>>a>>b>>c)
	// {}
	// while(cin>>s)
	return 0;
}
#endif

#if 0
int main()
{
	char c;
	//cin >> c;
	c = getchar();
	return 0;
}
#endif

#include <fstream>


// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};


struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}

	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}

	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}

	void ReadText(ServerInfo& info)
	{
		// 这里会发现IO流读整形比C语言那套就简单多了，
		// C 语言得先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}

private:
	string _configfile; // 配置文件
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}