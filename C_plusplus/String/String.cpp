#include"String.h"
//Member functions


String::String(const char* str)
{
	if (nullptr == str)
	{
		str = "";
	}
	//当前对象开辟空间
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_size + 1];
	strcpy(_str, str);
}

String::String(size_t n, char ch)
		: _size(n)
		, _capacity(n)
		, _str(new char[_size+1])
{
	memset(_str, ch, n);
	_str[n] = '\0';
}


String::String(char* begin, char* end)
{
	_size = end - begin;
	_capacity = _size;
	_str = new char[_size + 1];
	strncpy(_str, begin, _size);
	_str[_size] = '\0';
}

String::String(const String& s)
		:_size(s._size)
		, _capacity(s._size)
{
	_str = new char[_size + 1];
	strcpy(_str, s._str);
}

String& String::operator=(String s)
{
	if (this != &s)
	{
		swap(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
		return *this;
	}
}

String::~String()
{
	if (_str)
	{
		delete[] _str;
		_str = nullptr;
		_capacity = 0;
		_size = 0;
	}
}

//Capacity:

size_t String::size()const
{
	return _size;
}

size_t String::capacity()const
{
	return _capacity;
}

bool String::empty()const
{
	return 0 == _size;
}

void String::resize(size_t newsize, char ch)
{
	size_t oldsize = size();
	if (newsize > oldsize)
	{
		if (newsize > _capacity)
		{
			reserve(newsize);
		}
		memset(_str + _size, ch, newsize - oldsize);
	}
	_size = newsize;
	_str[_size] = '\0';
}

void String::reserve(size_t newcapacity)
{
	size_t oldcapacity = capacity();
	if (newcapacity > oldcapacity)
	{
		char* temp = new char[newcapacity + 1];
		strcpy(temp, _str);
		delete[] _str;
		_str = temp;
		_capacity = newcapacity;
	}
}

//Element access:
char& String::operator[](size_t index)
{
	assert(index < _size);
	return _str[index];
}

const char& String:: operator[](size_t index)const
{
	assert(index < _size);
	return _str[index];
}

//Modifiers:
void String::push_back(char ch)
{
	if (_size == _capacity)
	{
		reserve(_capacity * 2);
	}
	_str[_size++] = ch;
	_str[_size] = '\0';
}

String& String::operator+=(char ch)
{
	push_back(ch);
	return *this;
}

String& String::operator+=(const char* str)
{
	if (_size == _capacity)
	{
		reserve(_size + strlen(str) + 1);
	}
	strcpy(_str + _size, str);
	return *this;
}

String& String::operator+=(const String& s)
{
	if (_size == _capacity)
	{
		reserve(_size+strlen(s._str)+1);
	}
	strcpy(_str + _size, s._str);
	return *this;
}

bool String::operator==(const String& s)
{
	if (strcmp(_str, s._str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator!=(const String& s)
{
	if (strcmp(_str, s._str) != 0)
	{
		return true;
	}
	else
	{
		false;
	}
}
bool String::operator>(const String& s)
{
	if (strcmp(_str, s._str) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator>=(const String& s)
{
	if (strcmp(_str, s._str) < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool String::operator<(const String& s)
{
	if (strcmp(_str, s._str) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool String::operator<=(const String& s)
{
	if (strcmp(_str, s._str) > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s.c_str();
	return _cout;
}

istream& operator>>(istream& _cin, String& s)
{
	_cin >> s._str;
	return _cin;
}

//String operations:
size_t String::find(char ch, size_t pos=0)
{
	for (size_t i = pos; i < _size; i++)
	{
		if (ch == _str[i])
		{
			return i;
		}
	}
	return npos;
}

size_t String::rfind(char ch, size_t pos=npos)
{
	if (pos == npos)
	{
		pos = _size - 1;
	}
	for (size_t i = pos; i >= 0; i--)
	{
		if (ch == _str[i])
		{
			return i;
		}
	}
	return npos;
}

String String::substr(size_t pos=0, size_t n=npos)
{
	if (n == npos)
	{
		n = _size;
	}
	String temp(_str + pos, _str + pos + n);
	return temp;
}

const char* String:: c_str()const
{
	return _str;
}

//Iterators:
String::iterator String:: begin()
{
	return _str;
}
String::iterator String::end()
{
	return _str + _size;
}

size_t String::npos = -1;

//测试
void TestString1()
{

	String s1;
	String s2("hello");
	String s3(s2);
	String s4(10, '$');
	String s5(s2.begin(), s2.end());
	
	auto it = s4.begin();
	while (it != s4.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
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

	cout << s.substr(pos1, 2) << endl;
	String s2("world!");
	s += s2;
	cout << s << endl;
}
