#pragma once

#include<string>

class StrToInt1
{
public:
	size_t operator()(const std::string& s)
	{
		return BKDRHash(s.c_str());
	}
private:
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


class StrToInt2
{
public:
	size_t operator()(const std::string& s)
	{
		return SDBMHash(s.c_str());
	}
private:
	size_t SDBMHash(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}
};


class StrToInt3
{
public:
	size_t operator()(const std::string& s)
	{
		return RSHash(s.c_str());
	}
private:
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};


class StrToInt4
{
public:
	size_t operator()(const std::string& s)
	{
		return APHash(s.c_str());
	}
private:
	size_t APHash(const char *str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


class StrToInt5
{
public:
	size_t operator()(const std::string& s)
	{
		return JSHash(s.c_str());
	}
private:
	size_t JSHash(const char *str)
	{
		if (!*str)
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}
};