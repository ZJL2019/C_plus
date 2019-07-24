#ifndef _QUEUE_H_
#define _QUEUE_H_
#define _CRT_SECURE_NO_WARNINGS 1
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

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);

#endif /*_QUEUE_H_*/