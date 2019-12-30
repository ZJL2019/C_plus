#include "FileCompress.h"
#include "HuffmanTree.hpp"
#include <assert.h>

FileCompress::FileCompress()
{
	_fileInfo.resize(256);

	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}

}

void FileCompress::CompressFile(const string& path)
{
	//1、统计源文件中每个字符出现的次数
	FILE* fIn = fopen(path.c_str(), "r");
		if (nullptr == fIn)
		{
			assert(false);
			return;
		}

		char *pReadBuff = new char[1024];
		int rdSize = 0;
		while (true)
		{
			rdSize=fread(pReadBuff, 1, 1024, fIn);
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
		HuffManTree<CharInfo> t(_fileInfo,CharInfo());

	//3、获取编码
		//GenerateHuffManCode(t);

	//4、使用编码改写
		delete[] pReadBuff;
		fclose(fIn);
}

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
		string strCode;
		Node *pCur = pRoot;
		Node* pParent = pCur->_pParent;
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
		_fileInfo[pRoot->_weight._ch] = strCode;
	}
}