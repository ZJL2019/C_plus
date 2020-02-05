#include <iostream>
#include<string.h>
class String
{
public:
	String(const char* str = "")
		:_pCount(new int(1))
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(s._str)
		,_pCount(s._pCount)
	{
		++(*_pCount);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (0 == --*_pCount)
			{
				delete[] _str;
				delete _pCount;
			}

			_str = s._str;
			_pCount = s._pCount;
			++(*_pCount);
		}
		return *this;
	}

	~String()
	{
		if (_str && 0 == --*_pCount)
		{
			delete[] _str;
			_str = nullptr;

			delete _pCount;
			_pCount = nullptr;
		}
	}

	char& operator[](size_t index)
	{
		if (GetRef() > 1)
		{
			String strtemp(_str);
			this->swap(strtemp);
		}
		return _str[index];
	}

	void swap(String& s)
	{
		std::swap(_str, s._str);
		std::swap(_pCount, s._pCount);
	}
private:
	int GetRef()
	{
		return *_pCount;
	}

private:
	char* _str;
	int* _pCount;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3("hello");
	String s4;
	s4 = s2;
	s4[2] = 'O';
	return 0;
}