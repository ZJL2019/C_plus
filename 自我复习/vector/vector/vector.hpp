#include <iostream>
using namespace std;
#include <assert.h>

template<typename T>
class Vector
{
public:
	typedef T* iterator;
public:
	Vector()
		:_start(nullptr)
		,_end(nullptr)
		,_endofstorage(nullptr)
	{}

	Vector(int n,const T& data)
		:_start(new T[n])
	{
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = data;
		}
		_end = _start + n;
		_endofstorage = _end;
	}

	template<class Iterator>
	Vector(Iterator first, Iterator last)
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
		_end = _start + n;
		_endofstorage = _start + n;
	}

	Vector(const Vector<T>& v)
	{
		_start = new T[v.size()];
		memcpy(_start, v._start, v.size() * sizeof(T));
		_end = _start + v.size();
		_endofstorage = _start + v.size();
	}

	Vector<T>& operator=(const Vector<T> v)
	{
		swap(_start, v._start);
		_end = _start + v.size();
		_endofstorage = _start + v.size();
		return *this;
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _end = _endofstorage = nullptr;
		}
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _end;
	}

	size_t size()const
	{
		return _end - _start;
	}

	size_t capacity()const
	{
		return _endofstorage - _start;
	}

	bool empty()const
	{
		return _start == _end;
	}

	void resize(size_t newsize, const T& data = T())
	{
		size_t oldsize = size();
		if (newsize > oldsize)
		{
			size_t cap = capacity();
			if (newsize > capacity())
			{
				reserve(newsize);
			}
			for (; oldsize < newsize; oldsize++)
			{
				_start[oldsize] = data;
			}
		}
		_end = _start + newsize;
	}

	void reserve(size_t newCapacity)
	{
		size_t oldCapacity = capacity();
		if (newCapacity > oldCapacity)
		{
			T* temp = new T[newCapacity];
			size_t n = size();
			if (_start)
			{
				for (size_t i = 0; i < n; i++)
				{
					temp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = temp;
			_end = _start + n;
			_endofstorage = _start + newCapacity;
		}
	}

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
		return *(_end - 1);
	}

	const T& back()const
	{
		return *(_end - 1);
	}

	void push_back(const T& data)
	{
		if (_end == _endofstorage)
		{
			reserve(capacity() * 2 + 3);
		}
		*_end++ = data;
	}

	void pop_back()
	{
		_end--;
	}

	iterator insert(iterator pos, const T& data)
	{
		if (_end == _endofstorage)
		{
			reserve(capacity() * 2 + 3);
		}
		auto it = _end;
		while (it>pos)
		{
			*it = *(it - 1);
			it--;
		}
		*pos = data;
		_end++;
		return pos;
	}

	iterator erase(iterator pos)
	{
		if (pos == end())
		{
			return pos;
		}
		auto it = pos + 1;
		while (it != _end)
		{
			*(it - 1) = *it;
			++it;
		}
		_end--;
		return pos;
	}

	void clear()
	{
		_end = _start;
	}

private:
	T* _start;
	T* _end;
	T* _endofstorage;
};