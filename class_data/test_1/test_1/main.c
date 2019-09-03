#include"Sqlist.h"

SeqList test;
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
	return 0;
}