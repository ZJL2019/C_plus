#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void searchData(List*plist, char*find, Contact*searchpos)
{
	int count=0,flag,cap=0;
	char age[4] = { 0 };
	char*ret;
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		do
		{
			flag = 1;
			ret = strstr(cur->_data.name, find);
			if (ret)
			{
				break;
			}
			ret = strstr(cur->_data.sex, find);
			if (ret)
			{
				break;
			}
			sprintf(age, "%d", cur->_data.age);
			if (!strcmp(age, find))
			{
				break;
			}
			ret = strstr(cur->_data.phonenum, find);
			if (ret)
			{
				break;
			}
			ret = strstr(cur->_data.address, find);
			if (ret)
			{
				break;
			}
			flag = 0;
		} while (0);
		if (flag)
		{
			count++;
			searchpos[count++] = cur->_data;
		}
	}

}



void fillData(Contact *src, char*name, char sex, char age, char pn, char addr)
{
	if (src==NULL)
	{
		return;
	}
	strcpy(src->name, name);
	src->sex = sex;
	src->age = age;
	strcpy(src->phonenum, pn);
	strcpy(src->address, addr);
}

int Contactcmp(Contact c1, Contact c2)
{
	return strcmp(c1.name, c2.name);
}



Contact createData()
{
	Contact ret;
	printf("name:");
	scanf("%[^\n]", ret.name);
	printf("sex:");
	scanf("%c", ret.sex);
	printf("age:");
	scanf("%d", ret.age);
	printf("phonenum:");
	scanf("%s",ret.phonenum);
	getchar();
	printf("address:");
	scanf("%[^\n]", ret.address);
	getchar();
	return ret;
}

void ShowContact(List* plist)
{
	ListNode*cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printData(cur->_data);
	}
}

void printsearch(Contact *searchpos)
{
	int i;
	for (i = 1; searchpos[i].name; i++)
	{
		printData(searchpos[i]);
	}
}

void printData(Contact data)
{
	printf("%15s %c %2d %12s %s\n", 
		data.name, 
		data.sex, 
		data.age, 
		data.phonenum, 
		data.address);
}