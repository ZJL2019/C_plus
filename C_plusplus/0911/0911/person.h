#pragma once

class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age);
	void PrintStudent();
private:
	char _name[20];
	char _gender[3];
	int _age;
};