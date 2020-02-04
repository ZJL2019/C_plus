#include <algorithm>
#include <string.h>
#include <vector>
class String
{
public:
	String(const char* str="\0")
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}

	String(const String& s)
		:_data(new char[s.size()+1])
	{
		strcpy(_data, s._data);
	}

	~String()
	{
		delete[] _data;
	}
	const char* c_str()const
	{
		return _data;
	}
	String& operator =(String s)
	{
		swap(s);
		return *this;
	}
	size_t size() const
	{
		return strlen(_data);
	}

	void swap(String s)
	{
		std::swap(_data, s._data);
	}
private:
	char* _data;
};

int main()
{
	String s1;
	String s2 = "hhh";
	String s3(s2);
	String s4 = s3;
	std::vector<String> v1;
	v1.push_back(s1);
	v1.push_back(s2);
	return 0;
}