#include"LinkListCreat.h"
int main()
{
	LinkList L;
	Initial_L(&L);
	CreatList_F(&L, 3);
	PrintList(L);
	CapsOfStudent(&L);

	SerachName(&L);
	RetStudent(&L);
	InsertStudent(&L);
	PrintList(L);
	CapsOfStudent(&L);

	DeleteStudent(&L);
	PrintList(L);
	CapsOfStudent(&L);
	return 0;
}