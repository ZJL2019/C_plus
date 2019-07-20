#ifndef _SLIST_H_
#define _SLIST_H_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef int LTDataType;

typedef struct ListNode{
	LTDataType data;
	struct ListNode* next;
}ListNode;


void ListInit(ListNode**pphead);
ListNode* BuyListNode(ListNode**pphead, LTDataType x);
void ListPushFront(ListNode**pphead, LTDataType x);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
ListNode *detectCycle(ListNode *head);

#endif
