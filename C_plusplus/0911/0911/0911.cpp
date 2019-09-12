#include<iostream>
using namespace std;

#if 0
//类   结构体在c++中被称为类但不是类的定义，只是惯上称为类
struct Student
{
	//成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

	//成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s;//用类创建对象，必须要定义对象名
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();
	//可以使用  .  来调用类中的函数和变量

	return 0;
}
#endif



#if 0
//面向对象程序：封装   继承  多态
//封装：将一个事物的内部实现细节隐藏起来，提供一个公有接口让对象之间进行交互

//C++实现封装：类(通过类将对象的属性和行为包装在一起)
//				访问权限：private  protected  public
//				public: 被public修饰的成员，可以直接在类外被访问
//				protected/private：不能直接在类外进行访问


//int _age = 10;
//void SetStudentInfo(char* name)
//{}

class Student
{
public:
	//成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	//成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};

int g_a = 10;

int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();

	//s._age = 30;//类外无法调用类内的私有成员
	cout << g_a << endl;//可以正常调用全局变量
	return 0;
}

#endif

#if 0
// 在C++中类大小的计算和struct大小计算的方法完全一样
class Student
{
public:
	//成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	//成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s1, s2, s3;
	cout << sizeof(s1) << endl;

	s1.SetStudentInfo("Peter", "男",29);
	s2.SetStudentInfo("静静", "女", 30);
	s3.SetStudentInfo("summer", "公", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


#if 0
class A
{
public:
	void TestFun()
	{}
};

//空类的大小？主流编译器中空类的大小是1
class B
{};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	B b1,b2,b3;
	//空类可以定义对象
	return 0;
}

#endif


#if 0
//在C语言中想要实现类中定义函数的功能需要定义结构体指针
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}


void PrintStudent(Student* ps)
{
	printf("%s %s %s", ps->_name, ps->_gender, ps->_age);
}

#endif



#if 0
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		//Student* const  为this指针的类型
		//this=nullptr;  this指针无法赋空
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this->_name << ":" << this->_gender << ":" << this->_age << endl;
	}

	//不定参数
	void TestFunc(...)
	{
		cout << this << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};
//在类中定义的函数，其参数列表隐藏   类名* const  类型的this指针，指向类的地址。
//故而其函数并没有存储在类中，而是通过this指针访问类中的成员变量

#endif



#if 0
//1. 先识别类名
//2. 识别类中的成员变量
//3. 识别类中的成员函数并且对类中的成员函数进行改写


class Student
{
public:
	/*void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}*/

	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
	cout << this->_name << ":" << this->_age << endl;
	}
	*/

	void PrintStudent()
	{
		cout << _name << ":" << _age << endl;
	}
	//在预处理阶段，编译器会对类中的函数进行更改，从而显示出参数列表中隐藏的this指针
private:
	//成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	//cout << this << endl;
	//“this”: 只能在非静态成员函数或非静态数据成员初始值设定项的内部引用
	Student s1, s2, s3;
	//s1.TestFunc(10);//不定参数

	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "男", 29);

	cout << &s2 << endl;
	s2.SetStudentInfo("静静", "女", 30);

	cout << &s3 << endl;
	s3.SetStudentInfo("summer", "公", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


#if 0
class A
{
public:
	void PrintA()
	{
		cout << this << endl;
		cout << this->_a << endl;
	}

	void Show()
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}

private:
	int _a;
};

int main()
{
	A* p = NULL;//将A类的指针对象p设置为NULL
	p->Show();//调用时，导致其A* const this指针所存放的地址也为空，故可以调用
	p->PrintA();//调用时，因为this此时已经为空，故无法访问A，也无法访问A类中的变量，故程序崩溃


	return 0;
}
#endif