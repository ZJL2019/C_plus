#include"List.h"
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}

void ListPushFront(List* plist, LTDataType x)
{
	ListInsertAfter(plist->_head, x);
}



void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode*cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode*tmp = pos->_next;
	cur->_data = x;
	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListInsertFront(ListNode* pos, LTDataType x)
{
	ListNode*cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode*tmp = pos->_prev;
	cur->_data = x;
	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
}

void ListPrint(List* plist)
{
	ListNode*cur;
	printf("head->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("head");
}

void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}

void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}

void ListRemove(List* plist, LTDataType x)
{
	ListNode*cur=ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (Contactcmp(cur->_data,x)==0)
		{
			return cur;
		}
	}
	return NULL;
}
void ListDestory(List* plist)
{
	while (plist->_head!=plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListDistinct(List*plist)
{
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)
	{
		if (Contactcmp(cur->_data ,cur->_next->_data)==0)
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}

void ListMerge(List*plist1, List*plist2)
{
	ListNode*cur1 = plist1->_head->_next;
	ListNode*cur2 = plist2->_head->_next;
	ListNode*tmp1 = cur1;
	ListNode*tmp2 = cur2;
	while (cur1!=plist1->_head&&cur2!=plist2->_head)
	{
		if (Contactcmp(cur1->_data , cur2->_data)==1)
		{
			tmp1 = cur1->_prev;
			tmp2 = cur2->_next;

			cur1->_prev = cur2;
			cur2->_next = cur1;
			tmp1->_next = cur2;
			cur2->_prev = tmp1;
			cur2 = tmp2;
		}
		else
		{
			cur1 = cur1->_next;
		}
		if (cur1 == plist1->_head)
		{
			tmp2 = plist2->_head->_prev;
			cur2->_prev = cur1->_prev;
			cur1->_prev->_next = cur2;
			tmp2->_next = cur1;
			cur1->_prev = tmp2;
		}
	}
	free(plist2->_head);
}