#pragma once
#include "queue_seq.hpp"
int main()
{
	Queue q1;
	QueueInit(&q1);
	QueuePush(&q1, 1);
	QueuePush(&q1, 2);
	QueuePush(&q1, 3);
	QueuePush(&q1, 4);
	QueuePop(&q1);
	QueuePrint(&q1);
	return 0;
}