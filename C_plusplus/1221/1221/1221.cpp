#include<iostream>
using namespace std;

//C/C++

//bool Test1()
//{
//	//�ɹ�����true ��ʧ�ܷ���false
//	return false;
//}
//
//void Test2()
//{
//	// .....
//	//����˴������Ƿ����
//	throw 1;
//}
//
//// �������ԭ��ָ̬��(T*)������Դ�����������Դй©�ķ��վͱȽϴ�
//
//void TestFunc()
//{
//	int *p = new int[10];
//	FILE *pf = fopen("2223.txt", "rb");
//	if (nullptr == pf)
//	{
//		delete[] p;
//		return;
//	}
//
//	// ...
//	if (!Test1())
//	{
//		delete[] p;
//		fclose(pf);
//		return;
//	}
//
//	try
//	{
//		Test2();
//	}
//	catch (...)
//	{
//		delete[] p;
//		fclose(pf);
//		throw;
//	}
//	delete[] p;
//	fclose(pf);
//}


//�ܷ��ó������Ҹ�֪������������ʱ�Զ��ͷ���Դ


// RAII---��Դ��ȡ����ʼ��
// �ڹ��캯���з���Դ
// �������������ͷ���Դ


//����ָ��ļ�ģ��ʵ��
template<class T>
class SmartPtr
{
public:
	//RAII: ����--->�û����ÿ���ʲôʱ����ͷ���Դ
	//				���ͷ���Դ�Ĺ�������������
	SmartPtr(T* ptr = nullptr)
	:_ptr(ptr)
	{
		cout << "SmartPtr(T*)" << endl;
	}

	~SmartPtr()
	{
		cout << "~SmartPtr(T*)" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	//�ø���Ķ���߱�ָ�����Ƶ���Ϊ
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestSmartPtr()
{
	SmartPtr<int> spl(new int);
	*spl = 10;

	SmartPtr<A> sp2(new A);
	sp2->a = 1;
	sp2->b = 2;
	sp2->c = 3;
}

int main()
{
	TestSmartPtr();
	return 0;
}