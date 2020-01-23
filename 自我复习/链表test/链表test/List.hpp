#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
void ListErase(ListNode* pos)
{
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}
void ListInit(List* plist)
{
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = plist->_head->_prev;
	cur->_data = x;
	plist->_head->_prev = cur;
	cur->_next = plist->_head;
	tmp->_next = cur;
	cur->_prev = tmp;
}
void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}
void ListPushFront(List* plist, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = plist->_head->_next;
	cur->_data = x;
	plist->_head->_next = cur;
	cur->_prev = plist->_head;
	tmp->_prev = cur;
	cur->_next = tmp;
}
void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}
ListNode* ListFind(List* plist, LTDataType x)
{
	ListNode* tmp = plist->_head;
	for (tmp = tmp->_next; tmp != plist->_head; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp = pos->_prev;
	cur->_data = x;
	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_next = tmp;
}
// 删除pos位置的节点

void ListRemove(List* plist, LTDataType x)
{
	ListNode* cur=ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}
void ListPrint(List* plist)
{
	ListNode* tmp = plist->_head->_next;
	printf("head----> ");
	for (; tmp != plist->_head; tmp = tmp->_next)
	{
		printf("%d<---> ", tmp->_data);
	}
	printf("head----> \n");
}
void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListErase(plist->_head->_next);
	}
	free(plist->_head);
	plist->_head = NULL;
}
void ListDistinct(List* plist)
{
	ListNode* cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev;)
	{
		if (cur->_data == cur->_next->_data)
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
	ListNode* cur1 = plist1->_head->_next;
	ListNode* cur2 = plist2->_head->_next;
	ListNode* tmp1 = cur1;
	ListNode* tmp2 = cur2;
	while (cur1 != plist1->_head&&cur2 != plist2->_head)
	{
		if (cur1->_data > cur2->_data)
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