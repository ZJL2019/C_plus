#include <iostream>
using namespace std;
//auto_ptr
#if 0
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		,_owner(false)
	{
		if (_ptr)
		{
			_owner = true;
		}
	}

	~Auto_ptr()
	{
		if (_ptr&&_owner)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Auto_ptr(Auto_ptr<T>& ap)
		:_ptr(ap._ptr)
		,_owner(ap._owner)
	{
		ap._owner = false;
	}

	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
	{
		if (this!=&ap)
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
			}
			_ptr = ap._ptr;
			_owner = ap._owner;
			ap._owner = false;
		}
		return *this;
	}

private:
	T* _ptr;
	mutable bool _owner;
};
#endif

//unique_ptr
#if 0
template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr=nullptr)
		:_ptr(ptr)
	{}

	~Unique_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T*operator->()
	{
		return _ptr;
	}

	//c++98
//private:
//	Unique_ptr(const Unique_ptr<T>& up);
//	Unique_ptr<T>& operator=(const Unique_ptr<T>&);
//

	//c++11
	Unique_ptr(const Unique_ptr<T>&) = delete;
	Unique_ptr<T>& operator=(const Unique_ptr<T>&) = delete;

private:
	T* _ptr;
};
#endif

//析构函数改进
#if 0
template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

template <class T,class DF=DFDef<T>>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~Unique_ptr()
	{
		if (_ptr)
		{
			DF df;
			df(_ptr);
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Unique_ptr(const Unique_ptr<T>&) = delete;
	Unique_ptr<T>&  operator=(const Unique_ptr<T>&) = delete;

private:
	T* _ptr;
};
#endif

//shared_ptr
#if 0
template<class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		,_pCount(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
		}
	}

	~Shared_ptr()
	{
		if (_ptr && 0 == --*_pCount)
		{
			delete _ptr;
			delete _pCount;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._ptr)
	{
		if (_ptr)
		{
			++*_pCount;
		}
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		if (this != &sp)
		{
			if(_ptr&&0==--*_pCount)
			{
				delete _ptr;
				delete _pCount;
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (_ptr)
			{
				++*_pCount;
			}
		}
		return *this;
	}

	int use_count()
	{
		return *_pCount;
	}

private:
	T* _ptr;
	int* _pCount;
};
#endif

//shared_ptr 加锁
#include<mutex>

template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template <class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

class FClose
{
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

template<class T,class DF=DFDef<T>>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr=nullptr)
		:_ptr(ptr)
		,_pCount(nullptr)
		,_pMutex(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
			_pMutex = new mutex;
		}
	}

	~Shared_ptr()
	{
		Release();
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pCount(sp._pCount)
		,_pMutex(sp._pMutex)
	{
		AddRef();
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		if (this != &sp)
		{
			Release();
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (_ptr)
			{
				AddRef();
			}
		}
		return *this;
	}

	int use_count()
	{
		return *_pCount;
	}

private:
	int AddRef()
	{
		if (_pCount)
		{
			_pMutex->lock();
			++*_pCount;
			_pMutex->unlock();
		}
	}

	int SubRef()
	{
		if (_pCount)
		{
			_pMutex->lock();
			--*_pCount;
			_pMutex->unlock();
		}
		return *_pCount;
	}

	void Release()
	{
		if (_ptr && 0 == SubRef())
		{
			DF() (_ptr);
			delete _pCount;
		}
	}
private:
	T* _ptr;
	int* _pCount;
	mutex* _pMutex;
};