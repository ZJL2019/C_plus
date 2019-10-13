#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>

using namespace std;
#define OK 1;
#define ERROR 0;


typedef int Status;
typedef int ElemType;

typedef struct LNode{
	ElemType _number;
	char _name[10];
	ElemType _grade;
	struct LNode *next;
}LNode, *LinkList;

Status Initial_L(LinkList *L);
void CreatList_F(LinkList *L, int n);
void PrintList(LinkList L);
void  SerachName(LinkList *L);
void RetStudent(LinkList *L);
void InsertStudent(LinkList* L);
void DeleteStudent(LinkList *L);
void CapsOfStudent(LinkList *L);
#endif// LINKLIST_H_INCLUDED