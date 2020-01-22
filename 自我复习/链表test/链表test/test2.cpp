#include "List.hpp"

int main()
{
	List test;
	ListInit(&test);
	ListPushBack(&test, 1);
	ListPushBack(&test, 1);
	ListPushBack(&test, 3);
	ListPushBack(&test, 4);
	ListPushBack(&test, 5);
	ListPushBack(&test, 6);
	//ListPopBack(&test);
	ListRemove(&test, 1);
	ListPrint(&test);
	return 0;
}