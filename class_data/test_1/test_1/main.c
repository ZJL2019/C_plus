#include"Sqlist.h"

SeqList test;
SeqList test2;
int main()
{
	/*InitList(&test);
	ListInsert(&test, 1, 3);
	ListInsert(&test, 2, 6);
	ListInsert(&test, 3, 9);
	ListInsert(&test, 4, 0);
	ListInsert(&test, 5, -2);
	ListInsert(&test, 6, 89);
	ListInsert(&test, 7, 77);
	ShowList(&test);
	printf("%d\n", ListEmpty(test));
	printf("%d\n",GetELem(test, 2));
	printf("%d\n", LocateElem(test, 9));
	ListDelete(&test, 3);
	ShowList(&test);*/
	InitList(&test);
	ListInsert(&test, 1, 10);
	ListInsert(&test, 2, 8);
	ListInsert(&test, 3, 6);
	ListInsert(&test, 4, 4);
	ListInsert(&test, 5, 2);
	InitList(&test2);
	ListInsert(&test2, 1, 9);
	ListInsert(&test2, 2, 7);
	ListInsert(&test2, 3, 5);
	ListInsert(&test2, 4, 3);
	ListInsert(&test2, 5, 1);
	MergeList(&test, &test2);
	ShowList(&test);
	return 0;
}