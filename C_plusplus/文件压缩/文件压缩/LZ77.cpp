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
	size_t lookAhead = fread(pWin_, 1, 2 * WSIZE, fIn);

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
		if (lookAhead <= MIN_LOOKAHEAD)
		{
			FillWindow(fIn, lookAhead,start);
		}
	}
	//标记位数不够8bit
	if (bitCount > 0 && bitCount < 8)
	{
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}
	fclose(fOutF);
	fclose(fIn);

	//将标记信息和压缩数据合并
	MergeFile(fOut, fileSize);
	fclose(fOut);
}

void LZ77::FillWindow(FILE* fIn, size_t& lookAhead,USH& start)
{
	//start已经进入右窗
	if (start >= WSIZE)
	{
		//1.将右窗数据搬移至左窗
		memcpy(pWin_, pWin_ + WSIZE, WSIZE);
		start -= WSIZE;
		//2.更新哈希表
		ht_.Update();

		//3.向右窗中补充数据
		if (!feof(fIn))
		{
			lookAhead += fread(pWin_ + WSIZE, 1, WSIZE, fIn);
		}
	}
}



void LZ77::MergeFile(FILE* fOut,size_t fileSize)
{
	FILE* fInF = fopen("3.txt", "rb");
	size_t flagSize = 0;
	UCH* pReadbuff = new UCH[1024];
	while (true)
	{
		size_t rdSize = fread(pReadbuff, 1, 1024, fInF);
		if (rdSize == 0)
		{
			break;
		}
		fwrite(pReadbuff, 1, rdSize, fOut);
		flagSize += rdSize;
	}
	fwrite(&flagSize, sizeof(flagSize), 1, fOut);
	fwrite(&fileSize, sizeof(fileSize), 1, fOut);
	delete[] pReadbuff;
	fclose(fInF);
	if (remove("3.txt") != 0)
	{
		std::cout << "Remove File failed!" << std::endl;
	}
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
	FILE* unfIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr==unfIn)
	{
		std::cout << "Open Compare File Failed!" << std::endl;
		return;
	}

	//操作标记数据的文件指针
	FILE* unfInF = fopen(strFilePath.c_str(), "rb");
	if (nullptr == unfInF)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}
	
	//获取源文件的大小
	ULL fileSize = 0;
	fseek(unfInF, 0 - sizeof(fileSize), SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, unfInF);
	//获取标记信息的大小
	size_t flagSize = 0;
	fseek(unfInF, 0 - sizeof(fileSize) - sizeof(flagSize), SEEK_END);
	fread(&flagSize, sizeof(flagSize), 1, unfInF);

	//将读取标记信息的文件指针移动到保存标记数据的位置
	fseek(unfInF, 0 - 0 - sizeof(fileSize) - sizeof(flagSize)-flagSize, SEEK_END);


	//解压缩文件
	FILE* unfOut = fopen("4.txt", "wb");
	if (nullptr == unfOut)
	{
		std::cout << "Open UnCompare File Failed!" << std::endl;
		return;
	}

	//还原匹配串
	FILE* fR = fopen("4.txt", "rb");

	UCH bitCount = 0;
	UCH chFlag = 0;
	ULL encodeCount = 0;
	while (encodeCount<fileSize)
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
			//更新解码大小
			encodeCount += matchLen;
			//定位前文的匹配位置
			fseek(fR, 0 - matchDist, SEEK_END);
			UCH ch;
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, unfOut);
				matchLen--;
				fflush(unfOut);
			}
		}
		else
		{
			//原字符
			UCH ch = fgetc(unfIn);
			fputc(ch, unfOut);
			encodeCount += 1;
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
