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

SeqList* RemoveList(SeqList *psl, SeqList *psl2)
{
	int i, j,k;
	SeqList *tmp;
	for (i = 0,j=0,k=0; i < psl->length;k++ )
	{
		if (psl->array[i]>psl2->array[j])
		{
			tmp->array[k] = psl->array[i];
			i++;
		}
		else if (psl->array[i] < psl2->array[j])
		{
			tmp->array[k] = psl2->array[j];
			j++;
		}
	}
	return tmp;
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