
#include<iostream>
using namespace std;



#if 0
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


//void reserve (size_t n = 0);  扩容
// newcapacity > oldcapacity (string类旧空间大小): 空间增大---->容量改变(最终容量大小>=newcapacity),有效元素个数不变
// newcapacity < oldcapacity (string类旧空间大小): 空间缩小，该函数直接返回 除非newcapacity < 15
// 如果缩小的空间容量小于当前有效元素个数，则不缩小空间，直接返回
// 注意：只改变容量大小，不改变有效元素个数


void TestString4()
{
	string s(4, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


void TestString5()
{

	string s("hello");
	// char& operator[] (size_t pos);
	// const char& operator[] (size_t pos) const;
	
	
	cout << s[0] << endl;
	s[0] = 'H';
	//如果越界----assert触发
	//cout << s[10] << endl;

	// char& at(size_t pos);
	// const char& at(size_t pos) const;


	cout << s.at(2) << endl;
	s.at(2) = 'L';
	//如果越界---抛出out_of_range异常
	//cout << s.at(10) << endl;
}
void TestString6()
{
	string s1;
	s1.push_back('I');//void push_back (char c);


	//string(1)
		//string& operator+= (const string& str);
	//c - string(2)
		//string& operator+= (const char* s);
	//character(3)
		//string& operator+= (char c);*/
	s1 += " Love";

	string s2(" you");
	s1 += s2;
	
	//string& append(size_t n, char c);

	s1.append(1, ',');
	//string& append (const char* s);
	s1.append("china");

	s1.append(3, '!');
}
// 1、string类的扩容机制----vs---PJ  1.5倍
//							Linux---SGI 2倍
// 2、如果提前知道大概要往string类存放多少个元素，可以提前通过reserve将空间提供好

void TestPushBack()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void TestString7()
{
	string s("12345");

	//  int atoi（con​​st char * str）;
	// const char * c_str（）const;
	int ret = atoi(s.c_str());
}

// find  rfind
void TestString8()
{
	//size_t find (const string& str, size_t pos = 0) const;
	//size_t find (const char* s, size_t pos = 0) const;

	string s("hello world");
	size_t pos = s.find(' ');
	if (pos != string::npos)
	{
		cout << ' ' << "is in s " << pos << endl;
	}
	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << " is in s " << pos << endl;
	}

	// 获取文件的后缀 - 20190923.cpp.cpp
	string ss("20190923.cpp.cpp");

	//size_t rfind (const string& str, size_t pos = npos) const;
	//size_t rfind(const char* s, size_t pos = npos) const;

	pos = ss.rfind('.') + 1;

	//string substr (size_t pos = 0, size_t len = npos) const;

	string filepox = ss.substr(pos);
	cout << filepox << endl;

}

void TestString9()
{
	string s("hello");
	for (auto e : s)
		cout << e;
	cout << endl;

	for (size_t i = 0; i < s.size(); i++)
		cout << s[i];
	cout << endl;

	//C++98
	//迭代器
	//string::iterator it = s.begin();

	//C++11
	auto it = s.begin();
	
	
	while (it!=s.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}

void ReverseString(string& s)
{
	/*char* begin = (char*)s.c_str();
	char* end = begin + s.size() - 1;
	while (begin < end)
	{
		swap(*begin, *end);
		begin++;
		end--;
	}*/

	//BidirectionalIterator---->迭代器
	// void reverse (BidirectionalIterator first, BidirectionalIterator last);
	reverse(s.begin(), s.end());

}

int main()
{
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	//TestString9();

	string s("hello");
	cout << s << endl;
	ReverseString(s);
	cout << s << endl;
	return 0;
}
#endif


#if 0
//借助string来解决浅拷贝问题
//string类动态管理字符串
namespace bite
{
	//反例
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";
			
			//申请空间
			_str = new char[strlen(str) + 1];

			//存放str中的字符串
			strcpy(_str, str);
		}

		//浅拷贝：
		//将s对象中内容原封不动的拷贝到新对象中
		//值的拷贝---比特位的拷贝
		string(const string& s)
			:_str(s._str)
		{}
		//编译器生成的默认拷贝构造函数---浅拷贝&资源泄漏

		//赋值运算符重载也是浅拷贝，只拷贝值，针对于开辟的空间不会拷贝
		string& operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}

		//因为类中牵扯拷贝的操作都是浅拷贝，所以在调用析构函数时会对同一片空间释放多次
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

	private:
		char* _str;
	};
}

void TestString()
{
	//浅拷贝：
	//所有对象只是简单的拷贝值，故而使用同一块内存空间
	bite::string s1("hello");
	bite::string s2(nullptr);
	bite::string s3(s1);
	s2 = s1;
	//在调用析构函数时，会对同一块空间释放多次
}

int main()
{
	TestString();
	return 0;
}
#endif


#if 0
namespace bite
{
	//深拷贝---传统版
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		
		//自定义拷贝构造函数，并且在每次调用时，都给其分配一块新的空间
		//从而解决了拷贝构造函数使用同一块空间----(深拷贝)
		string(const string& s)
			: _str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}


		//创建临时指针指向新创建的空间，并进行拷贝赋值，释放其本身的空间
		//使原本的指针指向新创建的空间
		//使每一个对象在调用赋值时，都有一个属于自己的空间---(深拷贝)
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

void TestString()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	bite::string s3(s1);  
	s2 = s1;
}
int main()
{
	TestString();
	return 0;
}
#endif

namespace bite
{
	//深拷贝---简介版
	class string
	{
	public:
		string(char* str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(nullptr)
		{
			string str
		}
	private:
		char* _str;
	};
}