#include <iostream>
using namespace std;

#if 0
#include <queue>

/*
template < class T, class Container = vector<T>,
class Compare = less<typename Container::value_type> > class priority_queue;
T: 代表优先级队列中存储元素类型
Container: 优先级队列中元素的底层存储结构，默认vector
Compare: 优先级中元素的比较规则：默认按照Less(小于)--->大堆
*/
#include <vector>
#include <functional>

int main()
{
	// 优先级队列默认情况下是大堆
	priority_queue<int> q1;
	q1.push(4);
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;


	// 小堆
	// 在实例化时，必须将堆中的元素按照大于方式比较--->大堆
	// 
	vector<int> v{ 3, 8, 2, 6, 0, 1, 9, 5, 7, 4 };
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
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	// 	bool operator<(const Date& d)const
	// 	{
	// 		return _day < d._day;
	// 	}

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
			return true;

		return false;
	}
};

#include <queue>

int main()
{
	Date d1(2019, 10, 18);
	Date d2(2019, 10, 16);
	Date d3(2019, 10, 17);
#if 0
	// 比较方式：默认的less
	priority_queue<Date> q1;

	// 如果优先级队列中插入自定义类型的元素，
	// 在插入元素期间，优先级队列必须进行元素的比较(less: < greater: >)
	// 相当于需要对存储的自定义类型元素进行大于或者小于的比较
	// 类中：必须重载>或者<的符号
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

#include <deque>

namespace bite
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}
	private:
		Container _con;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_front();
		}

		T& front()
		{
			return _con.front();
		}

		const T& front()const
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back()const
		{
			return _con.back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}

#if 0
#include <vector>

void TestStack()
{
	bite::stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	s1.pop();
	s1.pop();
	cout << s1.size() << endl;
	cout << s1.top() << endl;

	bite::stack<int, vector<int>> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	cout << s2.size() << endl;
	cout << s2.top() << endl;
}

#include <list>
void Testqueue()
{
	bite::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	cout << q1.back() << endl;

	q1.pop();
	q1.pop();
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	cout << q1.back() << endl;

	bite::queue<int, list<int>> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;

	q2.pop();
	q2.pop();
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;
}

int main()
{
	// TestStack();
	Testqueue();
	return 0;
}
#endif

#include <vector>
// priority_queue--->堆
namespace bite
{
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue()
			: c()
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: c(first, last)
		{
			// 将c中的元素调整成堆的结构
			int count = c.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; root--)
				AdjustDown(root);
		}

		void push(const T& data)
		{
			c.push_back(data);
			AdjustUP(c.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;

			swap(c.front(), c.back());
			c.pop_back();
			AdjustDown(0);
		}

		size_t size()const
		{
			return c.size();
		}

		bool empty()const
		{
			return c.empty();
		}

		// 堆顶元素不允许修改，因为：堆顶元素修改可以会破坏堆的特性
		const T& top()const
		{
			return c.front();
		}
	private:
		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			while (child < c.size())
			{
				// 找以parent为根的较大的孩子
				if (child + 1 < c.size() && com(c[child], c[child + 1]))
					child += 1;

				// 检测双亲是否满足情况
				if (com(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}

		void AdjustUP(int child)
		{
			int parent = ((child - 1) >> 1);
			while (child)
			{
				if (com(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
				{
					return;
				}
			}
		}
	private:
		Container c;
		Compare com;  // 堆中元素比较规则
	};
}

#include <functional>

int main()
{
	// 8  1  9  3  6  4  5  0  2  7
	int array[] = { 8,1,9,3,6,4,5,0,2,7 };
	bite::priority_queue<int> q(array, array + sizeof(array) / sizeof(array[0]));
	cout << q.top() << endl;

	q.pop();
	cout << q.top() << endl;

	bite::priority_queue<int, vector<int>, less<int>> q2;
	q2.push(5);
	q2.push(0);
	q2.push(9);
	q2.push(3);
	q2.push(4);
	return 0;
}