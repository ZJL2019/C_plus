#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int QuDataType;

typedef struct QueueNode {
	QuDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode*front;
	QueueNode*rear;
}Queue;

void QueueInit(Queue*pq)
{
	pq->front = pq->rear=NULL;
}

QueueNode*BuyQueueNode(QuDataType x)
{
	QueueNode* ret = (QueueNode*)malloc(sizeof(QueueNode));
	ret->data = x;
	ret->next = NULL;
	return ret;
}

void QueuePush(Queue*pq, QuDataType x)
{
	if (pq->front == NULL)
	{
		QueueNode* tmp = BuyQueueNode(x);
		pq->front = pq->rear = tmp;
	}
	else
	{
		QueueNode* tmp = BuyQueueNode(x);
		pq->rear->next = tmp;
		pq->rear = tmp;
	}
}
void QueuePop(Queue*pq)
{
	if (pq->front == NULL)
	{
		return;
	}
	QueueNode* tmp = pq->front->next;
	free(pq->front);
	pq->front = tmp;
}
QuDataType QueueFront(Queue*pq)
{
	return pq->front->data;
}
QuDataType QueueBack(Queue*pq)
{
	return pq->rear->data;
}
void QueueToStack(Queue*pq, Queue*pq2)
{
	QuDataType size = 0;
	QueueNode* tmp;
	QuDataType cur;
	for (tmp = pq->front; tmp; tmp = tmp->next)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		for (tmp = pq->front; tmp != pq->rear;)
		{
			cur = QueueFront(pq);
			tmp = tmp->next;
			QueuePop(pq);
			QueuePush(pq2, cur);
		}
		printf("%d ", tmp->data);
		QuDataType cur2;
		QueueNode* tmp2;
		for (tmp2 = pq2->front; tmp2;)
		{
			cur2 = QueueFront(pq2);
			tmp2 = tmp2->next;
			QueuePop(pq2);
			QueuePush(pq, cur2);
		}
		QueuePop(pq);
	}
}

void QueuePrint(Queue* pq)
{
	QueueNode* tmp = pq->front;
	for (; tmp; tmp = tmp->next)
	{
		printf("%d ", tmp->data);
	}
	printf("\n");
}
