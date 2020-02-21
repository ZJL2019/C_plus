#include "LZ77.h"
#include <iostream>

const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;


LZ77::LZ77()
	:pWin_(new UCH[WSIZE*2])
	,ht_(WSIZE)
{}

LZ77::~LZ77()
{
	delete[] pWin_;
	pWin_ = nullptr;
}

void LZ77::CompressFile(const std::string& strFilePath)
{
	//打开待压缩文件
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		std::cout << "Open File Failed!" << std::endl;
		return;
	}

	//获取文件大小
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);

	//待压缩文件过小，不压缩
	if (fileSize <= MIN_MATCH)
	{
		std::cout << "FileSize Is Too Little!" << std::endl;
		return;
	}

	//调整文件指针
	fseek(fIn, 0, SEEK_SET);
	
	//读取数据至缓冲区
	USH lookAhead = fread(pWin_, 1, 2 * WSIZE, fIn);

	USH hashAddr = 0;

	//保证开始时是三个字符进行查找
	for (USH i = 0; i < MIN_MATCH - 1; i++)
	{
		ht_.HashFunc(hashAddr,pWin_[i]);
	}

	//压缩
	//压缩文件
	FILE* fOut = fopen("2.lzp", "wb");
	if (nullptr == fOut)
	{
		std::cout << "Open File Failed!" << std::endl;
		return;
	}

	USH start = 0;
	
	//与查找最长匹配相关变量
	USH matchHead = 0;
	USH curMatchLength = 0;
	USH curMatchDist = 0;

	//与标记相关变量
	UCH chFlag = 0;
	UCH bitCount = 0;
	
	//写标记的文件
	FILE* fOutF = fopen("3.txt", "wb");

	//lookHead表示先行缓冲区中剩余的元素
	while (lookAhead)
	{
		ht_.Insert(matchHead, pWin_[start + 2], start, hashAddr);
		curMatchLength = 0;
		curMatchDist = 0;  
		if (matchHead)
		{
			curMatchLength= LongestMatch(matchHead, curMatchDist,start);
		}
		 //是原字符
		if (curMatchLength < MIN_MATCH)
		{
			fputc(pWin_[start], fOut);
			WriteFlag(fOutF, chFlag, bitCount, false);
			++start;
			lookAhead--;
		}

		//是长度对
		else
		{
			//写长度
			UCH chlen = curMatchLength - 3;
			fputc(chlen, fOut);

			//写距离
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOut);

			//写标记
			WriteFlag(fOutF, chFlag, bitCount, true);

			//更新先行缓冲区
			lookAhead -= curMatchLength;
			
			--curMatchLength;
			while (curMatchLength)
			{
				start++;
				ht_.Insert(matchHead, pWin_[start+2], start, hashAddr);
				curMatchLength--;
			}
			start++;
		}
	}
	//标记位数不够8bit
	if (bitCount > 0 && bitCount < 8)
	{
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}
	fclose(fIn);
	fclose(fOut);
	fclose(fOutF);
}

USH LZ77::LongestMatch(USH matchHead, USH& MatchDist,USH start)
{
	UCH curMathchLen = 0;//一次匹配长度
	UCH maxMatchLen = 0;//最大匹配长度
	UCH maxMatchCount = 255;//最大的匹配次数
	USH curMatchStart = 0;//当前匹配在查找缓冲区中的起始位置
	
	//保证查找范围在查找缓冲区大小内
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;
	do
	{
		//匹配范围
		UCH* pstart = pWin_ + start;
		UCH* pend = pstart + MAX_MATCH;

		//查找缓冲区中的匹配串起始
		UCH* pMatchStart = pWin_ + matchHead;
		curMathchLen = 0;

		while (pstart < pend&&*pstart == *pMatchStart)
		{
			curMathchLen++;
			pstart++;
			pMatchStart++;
		}

		if (curMathchLen > maxMatchLen)
		{
			maxMatchLen = curMathchLen;
			curMatchStart = matchHead;
		}

	} while ((matchHead = ht_.GetNext(matchHead))> limit&&maxMatchCount--);

	MatchDist = start - curMatchStart;
	return maxMatchLen;
}

void LZ77::UnCompressFile(const std::string& strFilePath)
{
	//打开压缩文件和标记文件
	FILE* unfIn = fopen("2.lzp", "rb");
	if (nullptr==unfIn)
	{
		std::cout << "Open Compare File Failed!" << std::endl;
		return;
	}

	FILE* unfInF = fopen("3.txt", "rb");
	if (nullptr == unfIn)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}

	//解压缩文件
	FILE* unfOut = fopen("4.txt", "wb");
	if (nullptr == unfIn)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}

	//还原匹配串
	FILE* fR = fopen("4.txt", "rb");

	UCH bitCount = 0;
	UCH chFlag = 0;
	while (!feof(unfIn))
	{
		if (0 == bitCount)
		{
			chFlag=fgetc(unfInF);
			bitCount = 8;
		}

		if (chFlag & 0x80)
		{
			//距离长度对
			USH matchLen = fgetc(unfIn) + 3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, unfIn);
			
			//清空缓冲区
			fflush(unfOut);

			//定位前文的匹配位置
			fseek(fR, 0 - matchDist, SEEK_END);
			UCH ch;
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, unfOut);
				matchLen--;
			}
		}
		else
		{
			//原字符
			UCH ch = fgetc(unfIn);
			fputc(ch, unfOut);
		}
		chFlag <<= 1;
		bitCount--;
	}
	fclose(unfIn);
	fclose(unfInF);
	fclose(unfOut);
	fclose(fR);
}

void LZ77::WriteFlag(FILE* fOutF, UCH& chFalg, UCH& bitCount, bool isLen)
{
	chFalg <<= 1;
	if (isLen)
	{
		chFalg |= 1;
	}
	bitCount++;
	if (bitCount == 8)
	{
		fputc(chFalg, fOutF);
		chFalg = 0;
		bitCount = 0;
	}
}
