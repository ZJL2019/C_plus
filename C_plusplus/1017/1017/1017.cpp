#include<iostream>
using namespace std;



#include<queue>
#include<vector>
#include<functional>

#if 0
/*
template<class T,class Container=vector<T>,class Compare=less<typename Container::value_type>>
class priority_queue;
T: 代表优先级队列中存储元素的类型
Container: 优先级队列中元素的底层存储结构，默认为vector
Compare: 优先级中元素的比较规则：默认按照Less(小于)--->大堆
*/

int main()
{
	//优先级队列默认情况下是大堆
	priority_queue<int> q1;
	q1.push(4);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	//小堆
	//在实例化时，必须将堆中的元素按照大于方式比较----小堆

	vector<int> v{ 5, 4, 3, 9, 6, 7, 2, 8, 1, 0 };
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.size() << endl;
	cout << q2.top() << endl;
	q2.pop();
	cout << q2.top() << endl;
	return 0;
}
#endif

#if 0
class Date
{
	friend class Compare;
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)

	{}

private:
	int _year;
	int _month;
	int _day;
};

class Compare
{
public:
	bool operator()(Date* pLeft, Date* pRight)
	{
		if (pLeft->_day < pRight->_day)
		{
			return true;
		}
		return false;
	}
};

#include<queue>

int main()
{
	Date d1(2019, 10, 18);
	Date d2(2019, 10, 16);
	Date d3(2019, 10, 17);
	
#if 0
	//比较方式：默认的less
	priority_queue<Date> q1;

	//如果优先级队列中插入自定义类型的元素，
	//在插入元素期间，优先级队列必须进行元素的比较（less: <  greater: > )
	//相当于需要对存储的自定义类型元素进行大于或者小于的比较
	//类中： 必须重载> 或者 <的符号
	q1.push(d1);
	q1.push(d2);
	q1.push(d3);
#endif
	priority_queue<Date*, vector<Date*>, Compare> q2;
	q2.push(&d1);
	q2.push(&d2);
	q2.push(&d3);
	return 0;
}
#endif