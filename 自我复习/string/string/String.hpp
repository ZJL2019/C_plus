#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

class String
{
public:
	typedef char* iterator;
public:
	String(const char* str ="")
	{
		if (nullptr == str)
			str = "";
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}
	String(size_t n, char ch)
		:_size(n)
		,_capacity(n)
		,_str(new char[_size+1])
	{
		memset(_str, ch, n);
		_str[n] = '\0';
	}

	String(char* begin, char*end)
	{
		_size = end - begin;
		_capacity = _size;
		_str = new char[_size + 1];
		strncpy(_str, begin, _size);
		_str[_size] = '\0';
	}

	String(const String& s)
		:_size(s._size)
		,_capacity(s._capacity)
		,_str(nullptr)
	{
		String temp(s._str);
		swap(_str,temp._str);
	}

	String& operator=(String s)
	{
		if (this != &s)
		{
			swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}

	//capacity
	size_t size()const
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	bool empty()const
	{
		return _size == 0;
	}

	void resize(size_t newsize, char ch)
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

	void reserve(size_t newcapacity)
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

	//access
	char& operator [](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	const char& operator [](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	//Modifiers
	void push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	String& operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	String& operator+=(const char* str)
	{
		if (_size+strlen(str) >= _capacity)
		{
			reserve(_size + strlen(str) + 1);
		}
		strcpy(_str + _size, str);
		_size = _size + strlen(str);
		return *this;
	}

	String& operator+=(const String& s)
	{
		if (_size+strlen(s._str) >= _capacity)
		{
			reserve(_size + strlen(s._str) + 1);
		}
		strcpy(_str + _size, s._str);
		_size = _size + strlen(s._str);
		return *this;
	}

	bool operator==(const String& s)
	{
		if (strcmp(_str, s._str) == 0)
			return true;
		else
			return false;
	}

	bool operator!=(const String& s)
	{
		if (strcmp(_str, s._str) != 0)
			return true;
		else
			return false;
	}

	bool operator>(const String& s)
	{
		if (strcmp(_str, s._str) > 0)
			return true;
		else
			return false;
	}

	bool operator>=(const String& s)
	{
		if (strcmp(_str, s._str) < 0)
			return false;
		else
			return true;
	}

	bool operator<(const String& s)
	{
		if (strcmp(_str, s._str) < 0)
			return true;
		else
			return false;
	}

	bool operator<=(const String& s)
	{
		if (strcmp(_str, s._str) > 0)
			return false;
		else
			return true;
	}

	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		_cout << s._str;
		return _cout;
	}

	friend istream& operator>>(istream& _cin, const String& s)
	{
		_cin >> s._str;
		return _cin;
	}

	//operations
	size_t find(char ch, size_t pos = 0)
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

	size_t rfind(char ch, size_t pos = npos)
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

	String substr(size_t pos = 0, size_t n = npos)
	{
		if (n == npos)
		{
			n = _size;
		}
		String temp(_str + pos, _str + pos + n);
		return temp;
	}

	const char* c_str()const
	{
		return _str;
	}

	//iterator
	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

private:
	size_t _size;
	size_t _capacity;
	char* _str;
	static size_t npos;
};
size_t String::npos = -1;