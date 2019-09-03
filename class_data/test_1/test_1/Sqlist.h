#ifndef _SQLIST_C_

#define _SQLIST_C_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;
	SLDataType length;
}SeqList;

void InitList(SeqList *psl);
void ShowList(SeqList *psl);
SLDataType ListEmpty(SeqList psl);
SLDataType GetELem(SeqList psl, SLDataType i);
SLDataType LocateElem(SeqList psl, SLDataType e);
void ListInsert(SeqList *psl, SLDataType i, SLDataType e);
void ListDelete(SeqList *psl, SLDataType i);
void RemoveList(SeqList *psl, SeqList *psl2);
#endif /*_SQLIST_C_*/
