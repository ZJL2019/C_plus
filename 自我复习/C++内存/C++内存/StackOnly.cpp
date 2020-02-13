#include <iostream>
using namespace std;

class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

int main()
{
	StackOnly* p = new StackOnly;
	return 0;
}