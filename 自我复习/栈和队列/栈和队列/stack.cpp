#include "stack.hpp"
int main()
{
	Stack s1, s2;
	StackInit(&s1);
	StackInit(&s2);
	StackPush(&s1, 1);
	StackPush(&s1, 2);
	StackPush(&s1, 3);
	StackPush(&s1, 4);
	StackPush(&s1, 5);
	StackPush(&s1, 6);
	StackPrint(&s1);
	StackToQueue(&s1, &s2);
	return 0;
}