#pragma once
#include "LZHashTable.h"
#include <string>

class LZ77
{
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string& strFilePath);
	void UnCompressFile(const std::string& strFilePath);

private:
	USH LongestMatch(USH matchHead, USH& curMatchDist,USH start);
	void WriteFlag(FILE* fOutF, UCH& chFalg, UCH& bitCount, bool isLen);
	void MergeFile(FILE* fOut,size_t fileSize);
	void FillWindow(FILE* fIn, size_t& lookAhead,USH& start);
private:
	UCH* pWin_;//±£´æ»º³åÇø
	LZHashTable ht_;
};