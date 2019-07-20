#include"List.h"


int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 9);
	ListPushBack(&list, 8);
	ListPushBack(&list, 7);
	ListPushBack(&list, 6);
	ListPushBack(&list, 5);

	ListPushFront(&list, 1);
	ListPushFront(&list, 2);
	ListPushFront(&list, 3);
	ListPopBack(&list);
	ListPopFront(&list);
	ListInsertAfter(ListFind(&list, 1), 5);
	ListInsertFront(ListFind(&list, 5), 9);
	ListErase(ListFind(&list, 9));
	ListErase(ListFind(&list, 9));
	ListRemove(&list, 7);
	ListPrint(&list);
	system("pause");
	return 0;
}