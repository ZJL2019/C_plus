#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _SLIST_C_
#define _SLIST_C_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType data;
	struct SListNode*next;
}SListNode;


void SListInit(SListNode** pphead);
void SListDestory(SListNode* phead);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopFront(SListNode** pphead);
SListNode* SListFind(SListNode* phead, SLTDataType x);
void SListRemove(SListNode** pphead, SLTDataType x); 
void SListRemoveAll(SListNode** pphead, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListReverse(SListNode** pphead);
void SListReverse2(SListNode** pphead);
void SListPrint(SListNode* phead);
SListNode *SListFindk(SListNode* phead, SLTDataType x);

#endif /*_SLIST_C_*/