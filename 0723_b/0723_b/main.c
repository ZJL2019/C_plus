#include"queue.h"
int main()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePop(&pq);
	QueuePush(&pq, 5);
	QueuePop(&pq);
	QueuePush(&pq, 9);

	printf("%d\n", QueueBack(&pq));
	/*QueuePush(&pq, 5);

	QueuePush(&pq, 6);
	QueuePush(&pq, 7);
	QueuePush(&pq, 8);
	QueuePush(&pq, 9);*/

	system("pause");
	return 0;
}