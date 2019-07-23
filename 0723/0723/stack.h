#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int STDataType;
#define N 10
typedef struct stack{
	STDataType a[N];
	STDataType *rear;
	size_t top;
}stack;

void StackInit(stack*pq);
void StackPush(stack*pq, STDataType x);
void StackPop(stack*pq);
void StackToQueue(stack*pq, stack*pq2);
#endif