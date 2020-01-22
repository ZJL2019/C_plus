#include "slist.hpp"
int main()
{
	SList test;
	SListInit(&test);
	
	SListPushFront(&test, 1);
	//SListNode* tail = test._head;
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPushFront(&test, 5);
	//SListPopFront(&test);
	//SListInsertAfter(SListFind(&test, 1), 6);
	//SListEraseAfter(SListFind(&test, 1));
	//SListRemove(&test, 1);
	//SListRemoveAll(&test, 1);
	//SListReverse(&test);
	//SListReverse2(&test);
	//printf("%d\n",SListFindk(&test, 1)->_data);
	//tail->_next = test._head;
	//printf("%d\n",detectCycle(test)->_data);
	//SListPrint(&test);
	SList test2;
	SListPushFront(&test2, 10);
	test2._head->_next = test._head->_next->_next;
	printf("%d\n", getIntersectionNode(test,test2)->_data);
	SListDestory(&test);
	return 0;
}