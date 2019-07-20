#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void ListInit(ListNode**pphead)
{
	*pphead = NULL;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* res = (ListNode*)malloc(sizeof(ListNode));
	res->data = x;
	res->next = NULL;
	return res;
}
void ListPushFront(ListNode**pphead, LTDataType x)
{
	ListNode*tmp = BuyListNode(x);
	tmp->next = *pphead;
	*pphead = tmp;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode*longerlist=headA;
	ListNode*shorterlist=headB;
	ListNode*cur;
	int gap = 0;
	int lenA = 0;
	int lenB = 0;
	int i;
	for (cur = headA; cur; cur = cur->next)
	{
		lenA++;
	}
	for (cur = headB; cur; cur = cur->next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		longerlist = headB;
		shorterlist = headA;
	}
	for (i = 0; i < gap; i++)
	{
		longerlist = longerlist->next;
	}

	for (; longerlist&&shorterlist; longerlist = longerlist->next, shorterlist = shorterlist->next)
	{
		if (longerlist ==shorterlist)
		{
			return longerlist;
		}
	}
	return NULL;
}

ListNode *detectCycle(ListNode *head)
{
	ListNode*fast=head;
	ListNode*slow=head;
	while (slow&&head&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			break;
		}
	}
	for (; fast&&fast->next; fast = fast->next, head = head->next)
	{
		if ( head== fast)
		{
			return fast;
		}
	}
	return NULL;
}





//********************************************************************
