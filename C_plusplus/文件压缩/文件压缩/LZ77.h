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
	UCH LongestMatch(USH matchHead, USH& curMatchDist);
private:
	UCH* pWin_;//±£´æ»º³åÇø
	LZHashTable ht_;
};