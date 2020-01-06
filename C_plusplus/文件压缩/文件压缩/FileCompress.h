#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HuffmanTree.hpp"
using namespace std;

//字符信息
struct CharInfo
{
	
	unsigned char _ch;//具体字符，unsigned用于解决汉字字符
	size_t _count;		//字符次数
	string _strcode;	//字符编码

	CharInfo(size_t count = 0)
		:_count(count)
	{}

	CharInfo operator +(const CharInfo& c)
	{
		return CharInfo(_count + c._count);
	}

	bool operator > (const CharInfo& c)const
	{
		return _count > c._count;
	}

	bool operator == (const CharInfo& c)
	{
		return _count == c._count;
	}
};

class FileCompress
{
public:
	FileCompress();
	//压缩
	void CompressFile(const string& path);
	//解压缩
	void UnCompressFile(const string& path);

private:
	//哈夫曼编码
	void GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot);

	//头文件信息
	void WriteHead(FILE* fOut, const string& fileName);

	//获取压缩文件后缀
	string GetFilePostFix(const string& filename);

	//读取一行信息
	void ReadLine(FILE* fIn, string& strInfo);
private:
	vector<CharInfo> _fileInfo;
};




