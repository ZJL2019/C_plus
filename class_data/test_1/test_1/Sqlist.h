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

void InitList(SeqList *psl);//初始化线性表
void ShowList(SeqList *psl);//输出线性表
SLDataType ListEmpty(SeqList psl);//判断线性表是否为空
SLDataType GetELem(SeqList psl, SLDataType i);//获取线性表中的第i个元素
SLDataType LocateElem(SeqList psl, SLDataType e);//查找数值为e的元素
void ListInsert(SeqList *psl, SLDataType i, SLDataType e);//在第i个元素后插入数值为e的元素
void ListDelete(SeqList *psl, SLDataType i);//删除线性表中的第i个元素
void MergeList(SeqList *psl, SeqList *psl2);//合并两个有序线性表为降序序列
#endif /*_SQLIST_C_*/
