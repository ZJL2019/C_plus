#include "List.hpp"

int main()
{
	List test;
	List test2;
	ListInit(&test);
	ListInit(&test2);

	ListPushBack(&test, 1);
	ListPushBack(&test, 3);
	ListPushBack(&test, 5);
	ListPushBack(&test, 7);
	ListPushBack(&test, 9);
	ListPushBack(&test2, 2);
	ListPushBack(&test2, 4);
	ListPushBack(&test2, 6);
	ListPushBack(&test2, 8);
	ListPushBack(&test2, 10);

	//ListPopBack(&test);
	//ListRemove(&test, 1);
	ListMerge(&test, &test2);
	ListPrint(&test);
	return 0;
}