#include<iostream>
using namespace std;

#include<queue>
#include<vector>
#include<functional>

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