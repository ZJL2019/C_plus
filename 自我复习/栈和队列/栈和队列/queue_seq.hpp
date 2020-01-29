#include<stdio.h>
#define QueueMax 5
typedef int QuDataType;

typedef struct  Queue
{
	QuDataType data[QueueMax];
	QuDataType*front;
	QuDataType*rear;
	size_t size;
}Queue;

void QueueInit(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}
void QueueDestory(Queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(Queue* pq, QuDataType x)
{
	if (pq->size + 1 == QueueMax)
	{
		return;
	}
	*pq->rear = x;
	pq->rear++;
	pq->size++;
	if (pq->rear - pq->data == QueueMax)
	{
		pq->rear = pq->data;
	}
}
void QueuePop(Queue* pq)
{
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;
	pq->size--;
	if (pq->front - pq->data == QueueMax)
	{
		pq->front = pq->data;
	}
}

QuDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return (QuDataType)-1;
	}
	return *pq->front;
}
QuDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return (QuDataType)-1;
	}
	else if (pq->rear == pq->data)
	{
		return pq->data[QueueMax];
	}
	return *(pq->rear - 1);
}
void QueuePrint(Queue* pq)
{
	QuDataType* tmp=pq->front;
	while(tmp!=pq->rear)
	{
		printf("%d ", *tmp);
		if (tmp - pq->data == QueueMax)
		{
			tmp = pq->data;
		}
		else
		{
			tmp++;

		}
	}
	printf("\n");
}