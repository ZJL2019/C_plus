#pragma once
#include<stdio.h>
typedef int STDataType;
#define N 10
typedef struct Stack
{
	STDataType _a[N];
	STDataType* _rear;
	int _top; // Õ»¶¥
}Stack;

bool StackEmpty(Stack* ps)
{
	if (ps->_top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool StackEnough(Stack* ps)
{
	if (ps->_top == N)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StackInit(Stack* ps)
{
	ps->_rear = ps->_a;
	ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	if (!StackEnough(ps))
	{
		*ps->_rear = x;
		ps->_rear++;
		ps->_top++;
	}
	else
	{
		return;
	}
}

void StackPop(Stack* ps)
{
	if (!StackEmpty(ps))
	{
		ps->_rear--;
		ps->_top--;
	}
	else
	{
		return;
	}
}
STDataType StackTop(Stack* ps)
{
	return (ps->_a[ps->_top]);
}


int StackSize(Stack* ps)
{
	return ps->_top;
}

void StackToQueue(Stack* ps1, Stack* ps2)
{
	int tmp = ps1->_top;
	for (int i = 0; i < tmp; i++)
	{
		for (int j = ps1->_top; j > 1; j--)
		{
			StackPop(ps1);
			StackPush(ps2, *ps1->_rear);
		}
		printf("%d ", ps1->_a[0]);
		StackPop(ps1);
		for (int k = ps2->_top; k > 0; k--)
		{
			StackPop(ps2);
			StackPush(ps1,*ps2->_rear);
		}
	}
}

void StackPrint(Stack* ps)
{
	for (int i = ps->_top-1; i >=0; i--)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}