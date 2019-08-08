#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


int main()
{
	SListNode *head;
	SListInit(&head);

	SListPushFront(&head, 9);
	SListPushFront(&head, 8);
	SListPushFront(&head, 7);
	SListPushFront(&head, 6);
	SListPushFront(&head, 5);
	SListPushFront(&head, 4);
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	printf("%d\n", SListFindk(head, 1)->data);
	//SListRemoveAll(&head, 1);
	//SListReverse(&head);
	//SListReverse2(&head);
	//SListInsertAfter(SListFind(head,2), 1);
	/*SListEraseAfter(SListFind(head, 5));*/
	/*SListPopFront(&head);
	SListPopFront(&head);*/
	//SListDestory(&head);
	SListPrint(head);
	system("pause");
	return 0;
}

int __main()
{
	SListNode*phead;
	SListNode*plast;
	SListNode*cur;
	int m = 6, n = 5;
	SListInit(&phead);
	SListPushFront(&phead, m);
	plast = phead;
	int i;
	for (i = m - 1; i>=1; i--)
	{
		SListPushFront(&phead, i);
	}
	plast->next = phead;

	cur = plast;
	for (m = 6; m > 1; m--)
	{
		for (i = 1; i < n; i++)
		{
			cur = cur->next;
		}
		SListEraseAfter(cur);
	}
	printf("%d\n", cur->data);
	free(cur);
	system("pause");
	return 0;

}