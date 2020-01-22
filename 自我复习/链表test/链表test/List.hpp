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