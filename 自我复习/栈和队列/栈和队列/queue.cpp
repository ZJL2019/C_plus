#include"queue.hpp"
int main()
{
	Queue pq1, pq2;
	QueueInit(&pq1);
	QueueInit(&pq2);
	QueuePush(&pq1, 1);
	QueuePush(&pq1, 2);
	QueuePush(&pq1, 3);
	QueuePush(&pq1, 4);
	//QueuePop(&pq1);
	QueuePrint(&pq1);
	printf("%d\n", QueueBack(&pq1));
	printf("%d\n", QueueFront(&pq1));
	QueueToStack(&pq1, &pq2);
	return 0;
}