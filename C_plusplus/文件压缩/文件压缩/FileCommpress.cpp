#include "FileCompress.h"
#include "HuffmanTree.hpp"
#include <assert.h>

//基础初始化256个
FileCompress::FileCompress()
{
	_fileInfo.resize(256);

	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}

}

//压缩文件
void FileCompress::CompressFile(const string& path)
{
	//1、统计源文件中每个字符出现的次数
	
	FILE* fIn = fopen(path.c_str(), "r");
	//if (GetFilePostFix(path) == ".txt")
	//{
	//	fIn = fopen(path.c_str(), "r");
	//}
	//else
	//{
	//	fIn = fopen(path.c_str(), "rb");
	//}

	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	unsigned char* pReadBuff = new unsigned char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (rdSize == 0)
		{
			break;
		}

		for (int i = 0; i < rdSize; i++)
		{
			_fileInfo[pReadBuff[i]]._count++;
		}
	}

	//2、以字符出现的次数为权值创建哈夫曼树
	HuffManTree<CharInfo> t(_fileInfo, CharInfo());


	//3、获取编码
	GenerateHuffManCode(t.GetProot());

	//4、使用编码改写
	FILE* fOut = fopen("2.txt", "wb");
	if (nullptr == fOut)
	{
		assert(false);
		return;
	}
	
	//写入文件头信息，用于解压缩
	WriteHead(fOut, path);

	fseek(fIn, 0, SEEK_SET);
	char ch = 0;
	int bitcount = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (rdSize == 0)
		{
			break;
		}

		//根据字节编码对读取到的内容进行重写
		for (size_t i = 0; i < rdSize; i++)
		{
			string strCode = _fileInfo[pReadBuff[i]]._strcode;

			for (size_t j = 0; j < strCode.size(); j++)
			{
				ch <<= 1;
				if ('1' == strCode[j])
				{
					ch |= 1;
				}
				bitcount++;
				if (8 == bitcount)
				{
					fputc(ch, fOut);
					bitcount = 0;
					ch = 0;
				}
			}
		}
	}

	//最后一次ch中可能不够8个bit位
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);
		fputc(ch, fOut);
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

//获取文件后缀
string FileCompress::GetFilePostFix(const string& fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

void FileCompress::ReadLine(FILE* fIn, string& strInfo)
{
	assert(fIn);

	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
			break;
		strInfo += ch;
	}
}

//获取哈夫曼编码
void FileCompress::GenerateHuffManCode(HuffManTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
	{
		return;
	}

	GenerateHuffManCode(pRoot->_pLeft);
	GenerateHuffManCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)
	{
		string& strCode = _fileInfo[pRoot->_weight._ch]._strcode;
		HuffManTreeNode<CharInfo>* pCur = pRoot;
		HuffManTreeNode<CharInfo>* pParent = pCur->_pParent;

		while (pParent)
		{
			if (pCur == pParent->_pLeft)
			{
				strCode += '0';
			}
			else
			{
				strCode += '1';
			}
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());
		//_fileInfo[pRoot->_weight._ch]._strcode = strCode;
	}
}

//写入头信息
void FileCompress::WriteHead(FILE* fOut, const string& fileName)
{
	assert(fOut);
	//写文件的后缀
	string strHead;
	strHead += GetFilePostFix(fileName);
	strHead += '\n';

	//写行数
	size_t lineCount = 0;
	string strChCount;
	char szValue[32] = { 0 };

	for (int i = 0; i <_fileInfo.size(); i++)
	{
		CharInfo& charInfo = _fileInfo[i];
		if (charInfo._count)
		{
			lineCount++;
			strChCount += charInfo._ch;
			strChCount += ':';
			_itoa(charInfo._count, szValue, 10);
			strChCount += szValue;
			strChCount += '\n';
		}
	}
	
	_itoa(lineCount, szValue, 10);
	strHead += szValue;
	strHead += '\n';
	strHead += strChCount;
	fwrite(strHead.c_str(),1,strHead.size(),fOut);
}


//解压缩

void FileCompress::UnCompressFile(const string& path)
{
	FILE* fIn = fopen(path.c_str(), "rb");
	if (fIn == nullptr)
	{
		assert(false);
		return;
	}
	
	//文件后缀
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);

	//字符信息的总行数

	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());

	//字符信息
	for (int i = 0; i < lineCount; i++)
	{
		string strchCount;
		ReadLine(fIn, strchCount);
		//如果读取到的是\n
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}
		_fileInfo[(unsigned char)strchCount[0]]._count = atoi(strchCount.c_str() + 2);
	}

	//还原Huffman树
	HuffManTree<CharInfo> t(_fileInfo, CharInfo());

	FILE* fOut = fopen("3.txt", "w");

	//解压缩
	char* pReadBuff = new char[1024];
	char ch = 0;

	//压缩数据
	HuffManTreeNode<CharInfo>* pCur = t.GetProot();
	size_t fileSize = pCur->_weight._count;
	size_t unCount = 0;

	while (true)
	{
		size_t rdSize = fread(pReadBuff,1,1024,fIn);

		if (rdSize == 0)
			break;
		unsigned char tmp = 0x80;
		for (size_t i = 0; i < rdSize; i++)
		{
			if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
			{
				//unCount++;
				//fputc(pCur->_weight._ch, fOut);

				if (unCount == fileSize)
					break;

				pCur = t.GetProot();
			}
			//只需要将一个字节中8个bit位单独处理
			ch = pReadBuff[i];
			for (int pos = 0; pos < 8; pos++)
			{
				if (ch&0x80)
				{
					pCur = pCur->_pRight;
				}
				else
				{
					pCur = pCur->_pLeft;
				}
				
				ch <<= 1;

				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					unCount++;
					fputc(pCur->_weight._ch, fOut);

					if (unCount == fileSize)
						break;

					pCur = t.GetProot();
				}
			}
		}
	}
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}
