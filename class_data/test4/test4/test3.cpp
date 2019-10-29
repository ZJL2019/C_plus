#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int Status;
//类型定义
typedef struct
{
	char name[20];//姓名
	char sex;//性别，'F'表示女性，'M'表示男性
}Person;

typedef struct
{
	Person *base;
	int fronter;
	int rear;
}SqQueue;

Status InitQueue(SqQueue & Q)
{
	Q.base = new Person[MAXQSIZE];
	if (!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.fronter = Q.rear = 0;
	return OK;
}

//入队
Status EnQueue(SqQueue& Q, Person e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.fronter)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

//出队
Status DeQueue(SqQueue& Q, Person& e)
{
	if ((Q.rear + 1) % MAXQSIZE==Q.fronter)
		return ERROR;
	e = Q.base[Q.fronter];
	Q.fronter=(Q.fronter+1)%MAXQSIZE;
	return OK;
}
//判空
int QueueEmpty(SqQueue Q)
{
	if (Q.rear==Q.fronter)
		return 1;
	else
		return 0;
}

//取队头元素
Person GetHead(SqQueue Q)
{
	if (Q.fronter != Q.rear)
		return Q.base[Q.fronter];
}

//舞者配对
void DancePartner(Person dancer[], int num)
{
	SqQueue Mdancers, Fdancers;//分别存放男士和女士入队者队列
	Person p;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p);//插入女队
		else
		{
			EnQueue(Mdancers, p);//插入男队
		}
	}
	cout << "The Dancing partner are:";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		//依次输出男女舞伴的姓名
		DeQueue(Fdancers, p);
		cout << p.name << "  ";
		DeQueue(Mdancers, p);
		cout << p.name << endl;
	}
	if (!QueueEmpty(Fdancers))
	{
		p = GetHead(Fdancers);
		cout << "The first woman to get a partner is:" << p.name << endl;

	}
	else if (!QueueEmpty(Mdancers))
	{
		p = GetHead(Mdancers);
		cout << "The first man to get a partner is:" << p.name << endl;
	}
}
//main函数
int main()
{
	Person dancer[5] = { { "a", 'F' }, { "b", 'M' }, { "c", 'M' }, { "d", 'F' }, { "e", 'M' } };
	DancePartner(dancer, 5);
	return 0;
}
