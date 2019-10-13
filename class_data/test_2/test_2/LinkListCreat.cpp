#include"LinkListCreat.h"

Status Initial_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
}

void CreatList_F(LinkList *L, int n)
{
	int i;
	LNode *p;
	LNode *tmp=*L;
	for (i = 1; i <= n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		cout << "Please enter number:" << endl;
		cin >> p->_number;
		cout << "Please enter name:" << endl;
		cin >> p->_name;
		cout << "Please enter grade:" << endl;
		cin >> p->_grade;
		
		tmp->next = p;
		p->next = NULL;
		tmp = p;
	}
}

void  SerachName(LinkList *L)
{
	char n[10];
	cout << "Serach -> please enter a name of students:" << endl;
	cin >> n;
	LinkList tmp = *L;
	for (; tmp; tmp = tmp->next)
	{
		if (!strcmp(tmp->_name, n))
		{
			cout << tmp->_number << "-" << tmp->_name << "-" << tmp->_grade << endl;
		}
	}
}

void RetStudent(LinkList *L)
{
	int k;
	cout << "RetPos -> please enter a number of students:"<<endl;
	cin >> k;
	LinkList tmp = *L;
	int i = 0;
	for (tmp=tmp->next; tmp; tmp = tmp->next)
	{
		if (i == k)
		{
			cout << tmp->_number << "-" << tmp->_name << "-" << tmp->_grade << endl;
		}
		i++;
	}
}

void InsertStudent(LinkList* L)
{
	int k;
	cout << "Insert -> please enter a number of student's pos:" << endl;
	cin >> k;
	int i = 0;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	LinkList tmp = *L;
	cout << "Please enter number:" << endl;
	cin >> p->_number;
	cout << "Please enter name:" << endl;
	cin >> p->_name;
	cout << "Please enter grade:" << endl;
	cin >> p->_grade;
	for (; tmp; tmp = tmp->next)
	{
		
		if (i == k)
		{
			p->next = tmp->next;
			tmp->next = p;
			break;
		}
		i++;
	}
}

void DeleteStudent(LinkList *L)
{
	int k;
	cout << "Delete -> please enter a number of delete student's pos:" << endl;
	cin >> k;
	int i = 0;
	LinkList tmp = *L;
	for (; tmp; tmp = tmp->next)
	{
		
		if (i == k)
		{
			LinkList temp = tmp->next;

			tmp->next = tmp->next->next;
			free(temp);
			break;
		}
		i++;
	}
}
void CapsOfStudent(LinkList *L)
{
	int i = 0;
	LinkList tmp = *L;
	for (tmp=tmp->next; tmp; tmp = tmp->next)
	{
		i++;
	}
	cout << "Student caps:" << i << endl;
}
void PrintList(LinkList L)
{
	LNode *p;
	p = L->next;
	while (p)
	{
		cout <<p->_number << "-" << p->_name << "-" << p->_grade << endl;
		p = p->next;
	}
	printf("\n");
}
