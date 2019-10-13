#include"String.h"
//Member functions


String::String(const char* str="")
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
	memset(_str, ch, _size);
	_str[_size] = '\0';
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

