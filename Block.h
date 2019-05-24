#pragma once

#ifndef Block_struct_h
#define Block_struct_h

#include "academicPerformance.h"

class Block
{
private:
	int index;
	string blockHash;
	string previousHash;
	string generateHash();
public:
	Block(int idx, academicPerformance d, string prevHash);

	int getIndex();

	string getHash();

	string getPreviousHash();

	academicPerformance data;

	bool isHashValid();
};

#endif /* Block_h */
