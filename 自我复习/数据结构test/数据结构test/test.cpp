#include"seqlist.hpp"
#include<iostream>
using namespace std;
int main()
{
	SeqList test;
	SeqListInit(&test, 6);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 0);
	SeqListPushBack(&test, 3);
	SeqListPrint(&test);
	//SeqListPopBack(&test);
	/*SeqListPushFront(&test,9);
	SeqListPopFront(&test);*/
	//printf("%d\n",SeqListFind(&test, 4));
	/*SeqListInsert(&test, 5, 10);
	SeqListErase(&test, 5);*/
	//SeqListRemove(&test, 3);
	//SeqListModify(&test, 5, 0);
	//SeqListBubbleSort(&test);
	//printf("%d\n",SeqListBinaryFind(&test, 3));
	SeqListRemoveAll(&test, 3);
	SeqListPrint(&test);
	SeqListDestory(&test);

	
	return 0;
}