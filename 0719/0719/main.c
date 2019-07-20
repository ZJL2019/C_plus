#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

int main()
{
	ListNode*pheadA;
	ListNode*pheadB;
	ListNode*tmp;
	ListNode*tail;
	ListInit(&pheadA);
	ListInit(&pheadB);
	ListPushFront(&pheadA, 9);
	tail = pheadA;
	ListPushFront(&pheadA, 8);
	ListPushFront(&pheadA, 7);
	ListPushFront(&pheadA, 6);
	ListPushFront(&pheadA, 5);
	ListPushFront(&pheadA, 4);
	ListPushFront(&pheadA, 3);
	ListPushFront(&pheadA, 2);
	ListPushFront(&pheadA, 1);
	tail->next=pheadA;
	ListPushFront(&pheadA, 11);
	ListPushFront(&pheadA, 10);
	ListPushFront(&pheadA, 9);
	tmp = detectCycle(pheadA);
	if (tmp == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n", tmp->data);
	}

	//ListPushFront(&pheadB, 2);
	/*pheadB->next = pheadA->next->next;
	if (getIntersectionNode(pheadA, pheadB) == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",getIntersectionNode(pheadA, pheadB));
	}*/
	system("pause");
	return 0;
}
