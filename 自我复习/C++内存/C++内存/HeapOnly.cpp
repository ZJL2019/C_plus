#include <iostream>
using namespace std;
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	//C++98
	/*HeapOnly()
	{}
	HeapOnly(const HeapOnly&);*/

	//C++11

	HeapOnly()
	{}

	HeapOnly(const HeapOnly&) = delete;
};

int main()
{
	HeapOnly* p=HeapOnly::CreateObject();
	return 0;
}