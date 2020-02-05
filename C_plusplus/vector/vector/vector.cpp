#include<iostream>
using namespace std;
#include<assert.h>

namespace bite
{
	template<class T>
	class vector
	{
	public:
		//vector的迭代器实际就是原生态指针
		typedef T* iterator;
	public:
		//构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		vector(int n, const T& data)
			:_start(new T[n])
		{
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = data;
			}
			_finish = _start + n;
			_endofstorage = _finish;
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			size_t n = 0;
			auto it = first;
			while (it != last)
			{
				it++;
				n++;
			}
			_start = new T[n];
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = *first++;
			}
			_finish = _start + n;
			_endofstorage = _start + n;
		}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, v.size()*sizeof(T));
			_finish = _start+v.size();
			_endofstorage = _start + v.size();
		}
		vector<T>& operator=(const vector<T> v)
		{
			swap(_start, v._start);
			_finish = _start + v.size();
			_endofstorage = _start + v.size();
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		//迭代器
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		//容量
		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		bool empty()const
		{
			return _start == _finish;
		}

		//T():
		//如果T代表内置类型，T()--->0
		//如果T代表自定义类型，T()--->调用该类的无参构造函数
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				size_t cap = capacity();
				if (newsize > cap)
				{
					reserve(newsize);
				}
				for (; oldsize < newsize; oldsize++)
				{
					_start[oldsize] = data;
				}
			}
			_finish = _start + newsize;
		}

		void reserve(size_t newCapacity)
		{
			size_t oldCapacity = capacity();
			if (newCapacity > oldCapacity)
			{
				//1、申请新空间
				T* temp = new T[newCapacity];
				//2、拷贝元素
				//memcpy(temp, _start, size()*sizeof(T));
				// 如果_start指向的空间存在
				size_t n = size();
				if (_start)
				{
					for (size_t i = 0; i < n; i++)
					{
						temp[i] = _start[i];
					}
					//3、释放旧空间
					delete[] _start;
				}
				_start = temp;
				_finish = _start + n;
				_endofstorage = _start + newCapacity;
			}
		}

		//访问
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return _start[index];
		}

		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}

		//修改
		void push_back(const T& data)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}
			*_finish++ = data;
		}

		void pop_back()
		{
			_finish--;
		}

		//返回值含义：返回新插入元素的位置

		iterator insert(iterator pos, const T& data)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() * 2 + 3);
			}
			auto it = _finish;
			while (it > pos)
			{
				*it = *(it - 1);
				it--;
			}
			*pos = data;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			if (pos == end())
			{
				return pos;
			}
			auto it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
}

void TestVector1()
{
	bite::vector<int> v1;
	bite::vector<int> v2(10, 5);

	int array[] = { 1, 2, 3, 4, 5 };
	bite::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	bite::vector<int>v4(v3);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.front() << endl;
	cout << v3.back() << endl;

	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;

	//C++98
	//bite::vector<int>::iterator it = v3.begin();
	auto it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;
}
void TestVector2()
{
	bite::vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.back() << endl;

	v.pop_back();
	cout << v.back() << endl;
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << v.front() << endl;
	v.insert(v.begin(), 0);
	cout << v.front() << endl;
	cout << v.size() << endl;
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

#include <vector>

void TestVector3()
{
	vector<int> vv;
	bite::vector<int> v(10, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
int main()
{
	//TestVector1();
	//TestVector2();
	TestVector3();
	return 0;
}
