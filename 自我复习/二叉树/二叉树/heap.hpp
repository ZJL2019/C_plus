#pragma once
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef int HPDataType;

typedef struct Heap
{

	HPDataType* _data;
	int _size;
	int _capacity;
}Heap;



void DownAdjust(Heap *hp, int n)
{
	int cur = n;
	while (cur * 2 + 1 < hp->_size)
	{
		if (hp->_data[cur] < hp->_data[cur * 2 + 1])
		{
			if (cur * 2 + 2 >= hp->_size || hp->_data[cur * 2 + 1] > hp->_data[cur * 2 + 2])
			{
				std::swap(hp->_data[cur * 2 + 1], hp->_data[cur]);
				cur = cur * 2 + 1;
			}
			else
			{
				std::swap(hp->_data[cur], hp->_data[cur * 2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if (cur * 2 + 2 < hp->_size&&hp->_data[cur] < hp->_data[cur * 2 + 2])
		{
			std::swap(hp->_data[cur], hp->_data[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else
			break;
	}
}
void HeapInit(Heap *hp, HPDataType *a, int n)
{
	hp->_capacity = MAXSIZE > n ? MAXSIZE : n;
	hp->_size = n;
	hp->_data = (HPDataType*)malloc(sizeof(HPDataType)*hp->_capacity);
	memcpy(hp->_data, a, sizeof(HPDataType)*n);
	for (int i = n / 2 - 1; i >=0 ; i--)
	{
		DownAdjust(hp, i);
	}
}

void HeapDestory(Heap *hp)
{
	if (hp->_data)
	{
		free(hp->_data);
		hp->_data = NULL;
		hp->_size =hp->_capacity= 0;
		printf("NULL\n");
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->_size;
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity * 2;
		hp->_data = (HPDataType*)realloc(hp->_data, sizeof(HPDataType)*hp->_capacity);
	}
	hp->_data[hp->_size] = x;
	hp->_size++;

	while (cur)
	{
		if (hp->_data[cur] > hp->_data[(cur - 1) / 2])
		{
			std::swap(hp->_data[cur], hp->_data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap *hp)
{
	std::swap(hp->_data[0], hp->_data[ hp->_size - 1]);
	hp->_size--;
	DownAdjust(hp, 0);
}
bool HeapEmpty(Heap *hp)
{
	if (hp->_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
HPDataType HeapTop(Heap *hp)
{
	if (HeapEmpty(hp))
	{
		return (HPDataType)0;
	}
	return hp->_data[0];
}
int HeapSize(Heap *hp)
{
	return hp->_size;
}

// ¶ÑÅÅÐò
void HeapSort(Heap *hp)
{
	int tmp = hp->_size;
	while (hp->_size >= 1)
	{
		HeapPop(hp);
	}
	hp->_size=tmp;
}
void HeapPrint(Heap *hp)
{
	int i;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_data[i]);
		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
	putchar('\n');
}