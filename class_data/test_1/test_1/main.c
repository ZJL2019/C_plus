#include"Sqlist.h"

SeqList test;
SeqList test2;
int main()
{
	InitList(&test);
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
	ShowList(&test);


	InitList(&test);
	ListInsert(&test, 1, 29);
	ListInsert(&test, 2, 18);
	ListInsert(&test, 3, 12);
	ListInsert(&test, 4, 7);
	ListInsert(&test, 5, 6);
	InitList(&test2);
	ListInsert(&test2, 1, 33);
	ListInsert(&test2, 2, 22);
	ListInsert(&test2, 3, 17);
	ListInsert(&test2, 4, 12);
	ListInsert(&test2, 5, 5);
	MergeList(&test, &test2);
	ShowList(&test);
	return 0;
}