#include"person.h"
#include<iostream>
using namespace std;
void Student::SetStudentInfo(char* name, char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Student::PrintStudent()
{
	cout << _name << ":" << _gender << ":" << _age << endl;
}
