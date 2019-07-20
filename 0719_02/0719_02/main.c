#include"List.h"


int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushBack(&list, 7);
	ListPushBack(&list, 9);
	ListPushBack(&list, 11);
	List*list2;
	ListInit(&list2);
	ListPushBack(&list2, 3);
	ListPushBack(&list2, 5);
	ListPushBack(&list2, 8);
	ListPushBack(&list2, 9);
	ListMerge(&list, &list2);
	//ListDistinct(&list);
	/*ListPopBack(&list);
	ListPopFront(&list);
	ListInsertAfter(ListFind(&list, 1), 5);
	ListInsertFront(ListFind(&list, 5), 9);
	ListErase(ListFind(&list, 9));
	ListErase(ListFind(&list, 9));
	ListRemove(&list, 7);*/
	ListPrint(&list);
	system("pause");
	return 0;
}