#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 1、无头单向非循环链表增删查改实现
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;
void SListInit(SList* plist)
{
	plist->_head = NULL;
}
void SListEraseAfter(SListNode* pos)
{
	SListNode* tmp = pos->_next;
	if (tmp == NULL)
	{
		return;
	}
	pos->_next = tmp->_next;
	free(tmp);
	return;
}
void SListDestory(SList* plist)
{
	if (plist->_head == NULL)
	{
		return;
	}
	while (plist->_head->_next)
	{
		SListEraseAfter(plist->_head);
	}
	free(plist->_head);
	plist->_head = NULL;
}
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	res->_data = x;
	res->_next = NULL;
	return res;
}
void SListPushFront(SList* plist, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->_next = plist->_head;
	plist->_head = tmp;
}
void SListPopFront(SList* plist)
{
	if (plist->_head == NULL)
	{
		return;
	}
	SListNode* tmp = plist->_head->_next;
	free(plist->_head);
	plist->_head = tmp;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	SListNode* tmp = plist->_head;
	for (tmp; tmp != NULL; tmp = tmp->_next)
	{
		if (tmp->_data == x)
		{
			return tmp;
		}
	}
	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* tmp = BuySListNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
}


void SListRemove(SList* plist, SLTDataType x)
{
	SListNode* tmp;
	if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}
	for (tmp = plist->_head; tmp->_next; tmp = tmp->_next)
	{
		if (tmp->_next->_data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListRemoveAll(SList* plist, SLTDataType x)
{
	if (plist->_head == NULL)
	{
		return;
	}
	SListNode* tmp;
	while (plist->_head&&plist->_head->_data == x)
	{
		SListPopFront(plist);
	}
	for (tmp = plist->_head; tmp&&tmp->_next;)
	{
		if (tmp->_next->_data == x)
		{
			SListEraseAfter(tmp);
		}
		else
		{
			tmp = tmp->_next;
		}
	}
}
void SListPrint(SList* plist)
{
	SListNode* tmp = plist->_head;
	for (tmp; tmp != NULL; tmp = tmp->_next)
	{
		printf("%d->", tmp->_data);
	}
	printf("NULL\n");
}
void SListReverse(SList* plist)
{
	SListNode* head = plist->_head;
	SListNode* tmp = head->_next;
	SListNode* old_head = plist->_head;
	while (tmp)
	{
		old_head->_next = tmp->_next;
		tmp->_next = head;
		head = tmp;
		tmp = old_head->_next;
	}
	plist->_head = head;
}
void SListReverse2(SList* plist)
{
	SListNode* pre = plist->_head;
	SListNode* cur = pre->_next;
	SListNode* next = cur;
	pre->_next = NULL;
	while (next)
	{
		next = next->_next;
		cur->_next = pre;
		pre = cur;
		cur = next;
	}
	plist->_head = pre;
}
SListNode *SListFindk(SList* plist, SLTDataType x)
{
	int sum = 0;
	int j = 0;
	SListNode* tmp = plist->_head;
	for (tmp; tmp; tmp = tmp->_next)
	{
		sum++;
	}
	for (tmp = plist->_head; tmp; tmp = tmp->_next,j++)
	{
		if (j == sum - x)
		{
			return tmp;
		}
	}
}

SListNode* getIntersectionNode(SList plistA, SList plistB)
{
	SListNode* longerlist = plistA._head;
	SListNode* shorterlist = plistB._head;
	SListNode* cur=NULL;
	int lenA = 0;
	int lenB = 0;
	int gap = 0;
	for (cur = longerlist; cur; cur = cur->_next)
	{
		lenA++;
	}
	for (cur = shorterlist; cur; cur = cur->_next)
	{
		lenB++;
	}
	gap = abs(lenA - lenB);
	if (lenA < lenB)
	{
		shorterlist = plistA._head;
		longerlist = plistB._head;
	}
	for (int i = 0; i < gap; i++)
	{
		longerlist = longerlist->_next;
	}
	for (; longerlist&&shorterlist; longerlist = longerlist->_next, shorterlist = shorterlist->_next)
	{
		if (longerlist == shorterlist)
		{
			return longerlist;
		}
	}
	return NULL;
}

SListNode* detectCycle(SList plist)
{
	SListNode* slow = plist._head;
	SListNode* fast = plist._head;
	while (plist._head&&slow&&fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast)
		{
			break;
		}
	}
	for (; fast&&fast->_next; fast = fast->_next, plist._head = plist._head->_next)
	{
		if (plist._head == fast)
		{
			return fast;
		}
	}
	return NULL;
}