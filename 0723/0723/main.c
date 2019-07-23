#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include<stdio.h>
int main()
{
	stack stack1;
	StackInit(&stack1);
	stack stack2;
	StackInit(&stack2);
	StackPush(&stack1, 1);
	StackPush(&stack1, 2);
	StackPush(&stack1, 3);
	StackPush(&stack1, 4);
	StackPush(&stack1, 5);
	StackPush(&stack1, 6);
	//StackPop(&stack1);
	//printf("%d\n", StackBack(&stack1));
	/*for (int i = 0; i < stack1.top; i++)
	{
		printf("%d ", stack1.a[i]);
	}*/
	StackToQueue(&stack1, &stack2);

	system("pause");
	return 0;
}