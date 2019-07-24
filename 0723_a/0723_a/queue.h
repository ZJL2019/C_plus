#ifndef _QUEUE_H_
#define _QUEUE_H_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int QuDataType;

typedef struct QueueNode{
	QuDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue{
	QueueNode*front;
	QueueNode*rear;
}Queue;

void QueueInit(Queue*pq);
QueueNode*BuyQueueNode(QuDataType x);
void QueuePush(Queue*pq, QuDataType x);
void QueuePop(Queue*pq);
QuDataType QueueFront(Queue*pq);
QuDataType QueueBack(Queue*pq);
void QueueToStack(Queue*pq, Queue*pq2);

#endif /*_QUEUE_H_*/