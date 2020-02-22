#pragma once
#include "Command.h"

class LZHashTable
{
public:
	LZHashTable(USH size);
	~LZHashTable();
	void HashFunc(USH& hashAddr, UCH ch);
	void Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr);
	USH GetNext(USH matchHead);
	void Update();
private:
	USH H_SHIFT();

private:
	USH* prev_;
	USH* head_;
};