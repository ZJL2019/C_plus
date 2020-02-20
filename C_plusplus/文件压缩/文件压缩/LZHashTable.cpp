#include "LZHashTable.h"
#include <string.h>

LZHashTable::LZHashTable(USH size)
	:prev_(new USH[2*size])
	,head_(prev_+size)
{
	memset(prev_, 0, size * 2 * sizeof(USH));
}

LZHashTable::~LZHashTable()
{
	delete[] prev_;
	prev_ = nullptr;
}

void LZHashTable::HashFunc(USH& hashAddr, UCH ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

USH LZHashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}


void LZHashTable::Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr)
{
	HashFunc(hashAddr, ch);
	
	//保存当前哈希地址的内容
	matchHead = head_[hashAddr];

	//与MASK的目的是为了保证不越界
	prev_[pos&HASH_MASK] = head_[hashAddr];
	head_[hashAddr] = pos;


}