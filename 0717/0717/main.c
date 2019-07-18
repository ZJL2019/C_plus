#include "seqlist.h"

int capacity = 10;
SeqList test;
int main()
{
	SeqListInit(&test, capacity);
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushFront(&test, 8);
	SeqListPushFront(&test, 9);
	SeqListPushFront(&test, 10);
	SeqListPopBack(&test);
	SeqListPopFront(&test);
	SeqListInsert(&test, 2, 5);
	SeqListErase(&test, 2);
	SeqListRemove(&test, 5);
	SeqListModify(&test, 1, 9);
	SeqListPrint(&test);
	SeqListRemoveAll(&test, 9);
	SeqListRemoveAllN(&test, 9);
	SeqListBubbleSort(&test);
	SeqListPrint(&test);
	printf("%d\n", SeqListDiscFind(&test, 2, 0, 5));
	printf("%d\n",SeqListFind(&test, 1));
	system("pause");
	return 0;
}
