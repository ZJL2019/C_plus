#pragma once
#include "Command.h"

class LZHashTable
{
public:
	LZHashTable(USH size);
	~LZHashTable();
	void HashFunc(USH& hashAddr, UCH ch);
	USH H_SHIFT();
	void Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr);

private:
	USH* prev_;
	USH* head_;
};