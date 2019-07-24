#include"queue.h"
int main()
{
	Queue queue;
	Queue queue2;
	QueueInit(&queue);
	QueueInit(&queue2);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	//QueueNode*cur=&queue;
	QueueToStack(&queue, &queue2);
	/*for (cur = queue.front; cur; cur = cur->next)
	{
		printf("%d ", cur->data);
	}*/
	system("pause");
	return 0;
}