#include"Sqlist.h"

void InitList(SeqList *psl)
{
	psl->array = calloc(MAXSIZE, sizeof(SLDataType));
	psl->length = 0;
}

SLDataType ListEmpty(SeqList psl)
{
	if (!psl.length)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

SLDataType GetELem(SeqList psl, SLDataType i)
{
	for (int j = 0; j < psl.length; j++)
	{
		if (j == i - 1)
		{
			return psl.array[j];
		}
	}
	return 0;
}

SLDataType LocateElem(SeqList psl, SLDataType e)
{
	for (int i = 0; i < psl.length; i++)
	{
		if (psl.array[i] == e)
		{
			return i;
		}
	}
	return  0;
}

void ListInsert(SeqList *psl, SLDataType i, SLDataType e)
{
	for (int j = psl->length - 1; j > i; j--)
	{
		psl->array[j] = psl->array[j + 1];
	}
	psl->array[i - 1] = e;
	psl->length++;
}
void ListDelete(SeqList *psl, SLDataType i)
{
	for (int j = i; j < psl->length; j++)
	{
		psl->array[j - 1] = psl->array[j];
	}
	psl->length--;
}

void MergeList(SeqList *psl, SeqList *psl2)
{
	int i,j,tmp;
	i = psl->length;
	psl->length += psl2->length;
	for (i,j=0; i < psl->length; i++,j++)
	{
		psl->array[i] = psl2->array[j];
	}
	for (i = 0; i < psl->length - 1; i++)
	{
		for (j = 0; j < psl->length - 1 - i; j++)
		{
			if (psl->array[j] < psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

void ShowList(SeqList *psl)
{
	int i;
	for (i = 0; i < psl->length; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}