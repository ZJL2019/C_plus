#ifndef _HEAP_H_
#define _HEAP_H_

#define MAXSIZE 100

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int HPDataType;

typedef struct Heap
{

	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp, HPDataType *a, int n);
void DownAdjust(Heap *hp, int n);

void HeapDestory(Heap *hp);
void HeapPush(Heap *hp, HPDataType x);
void HeapPop(Heap *hp);
HPDataType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);
// ∂—≈≈–Ú
void HeapSort(Heap *hp);
void HeapPrint(Heap *hp);


#endif /*_HEAP_H_*/