#include "seqlist.h"


void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SeqList*)calloc(capacity, sizeof(SLDataType));
	psl->capacity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	if (!psl->capacity)
	{
		free(psl->array);
		psl->capacity = NULL;
		psl->size = 0;
	}
}
void CheckCapacity(SeqList* psl)
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
	}
	psl->array = (SeqList*)realloc(psl->array, psl->capacity*sizeof(SLDataType));
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size-1; i>=0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)
{
	int i;
	for (i = 0; i<psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	CheckCapacity(psl);
	int i;
	for (i = psl->size - 1; i < pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	int i;
	for (i =pos; i<psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemove(SeqList* psl, SLDataType x)
{
	int i;
	for (i = SeqListFind(psl, x); i<psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	int i;
	int gap = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i + gap] == x)
		{
			gap++;
		}
		else
		{
			psl->array[i - gap] = psl->array[i];
		}
	}
	psl->size -= gap;
}

void SeqListRemoveAllN(SeqList* psl, SLDataType x)
{
	int capacity = psl->capacity;
	SLDataType*arry1 = (SLDataType*)calloc(capacity, sizeof(SLDataType));
	int i, j;
	for (i = 0, j = 0; i <psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			arry1[j] = psl->array[i];
			j++;
		}
	}
	free(psl->array);
	psl->array = arry1;
	psl->size = j ;
}

void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	int tmp = 0;
	for (i = 0; i < psl->size-1; i++)
	{
		for (j = 0; j < psl->size - i-1; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

int SeqListDiscFind(SeqList* psl, SLDataType x,SLDataType left,SLDataType right)
{
	int mid = 0;
	while (left<=right)
	{
		int mid = left + (right + left) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid]>x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	psl->array[pos] = x;
}
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}