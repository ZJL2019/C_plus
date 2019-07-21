#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void Menu()
{
	printf("#####################");
	printf("#1¡¢Show     2¡¢Add##");
	printf("#3¡¢Find#############");
	printf("#####################");
	printf("#####################");
	printf("#####################");

}

int main()
{
	List list;
	volatile int quit = 0;
	int select = 0;
	ListInit(&list);
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			ShowContact(&list);
			break;
		case 2:
			createData();
			ListPushBack(&list, createData());
			break;
		case 3:
			char find[20] = { 0 };
			scanf("%s", find);
			searchData(&list,find,searchpos);
			printsearch(searchpos);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}