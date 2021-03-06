#ifndef _CONTACT_H_
#define _CONTACT_H_
#include"List.h"
typedef struct {
	char name[32];
	char sex;
	char age;
	char phonenum[13];
	char address[256];
}Contact;
Contact *searchpos[20];


void searchData(List*plist, char*find, Contact *searchpos);
void printsearch(Contact *searchpos);
Contact createData();
void ShowContact(List* plist);
void fillData(Contact *src, char*name, char sex, char age, char pn, char addr);
#endif /*_CONTACT_H_*/