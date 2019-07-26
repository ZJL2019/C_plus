#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#include"BTree.h"

typedef BTNode* QuDataType;

typedef struct QueueNode{
	QuDataType data;
	struct QueueNode*next;
}QueueNode;

typedef struct Queue{
	QueueNode*front;
	QueueNode*rear;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode * BuyQueueNode(QuDataType x);
void QueuePop(Queue* pq);
void QueuePush(Queue* pq, QuDataType x);
QuDataType QueueFront(Queue* pq);
int QueueIsEmpty(Queue* pq);

#endif /*_QUEUE_H_*/