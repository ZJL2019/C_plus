#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
void StackInit(stack*pq)
{
	pq->rear = pq->a;
	pq->top = 0;
}


void StackPush(stack*pq, STDataType x)
{
	*pq->rear = x;
	pq->rear++;
	pq->top++;
	return *(pq->rear);
}

void StackPop(stack*pq)
{
	pq->rear--;
	pq->top--;
}

STDataType StackBack(stack*pq)
{
	return *(pq->rear);
}

void StackToQueue(stack*pq, stack*pq2)
{
	int m = pq->top;
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < m; i++)
	{
		for (j = pq->top; j>1;j--)
		{
			StackPop(pq);
			StackPush(pq2, StackBack(pq));
		}
		printf("%d ", *(pq->rear-1));
		StackPop(pq);
		for (k = pq2->top; k > 0;k--)
		{
			StackPop(pq2);
			StackPush(pq, StackBack(pq2));
		}
	}
}