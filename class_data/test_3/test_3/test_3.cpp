#include<iostream>
using namespace std;

#define MAXSIZE 5

typedef int ElemType;
typedef struct
{
	ElemType *base;      //Õ»µ×
	ElemType *top;		//Õ»¶¥
	int capacity;
}Sqstack;

void InitStack(Sqstack &s)
{
	s.base = new ElemType[MAXSIZE];
	if (s.base == nullptr)
	{
		cout << "error" << endl;
		return;
	}
	s.top = s.base;
	s.capacity = MAXSIZE;
}

bool IsEmpty(Sqstack s)
{
	if (s.top == s.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Push(Sqstack &s, ElemType e)
{
	if (s.top - s.base == s.capacity)
	{
		cout << "stack full" << endl;
		return;
	}
	else
	{
		*s.top++ = e;
	}
}

void Pop(Sqstack &s)
{
	if (IsEmpty(s))
	{
		cout << "stack null" << endl;
		return;
	}
	s.top--;
}

ElemType GetTop(Sqstack s)
{
	if (IsEmpty(s))
	{
		cout << "stack null" << endl;
		return NULL;
	}
	return *(s.top - 1);
}


int main()
{
	Sqstack s;
	InitStack(s);
	if (IsEmpty(s))
	{
		cout << "stack null !" << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		Push(s, i);
	}

	auto it1 = s.base;
	while (it1 != s.top)
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	cout << "stack top:" << GetTop(s) << endl;

	Pop(s);

	auto it = s.base;
	while (it != s.top)
	{
		cout << *it << " ";
		it++;
	}
	return 0;
}