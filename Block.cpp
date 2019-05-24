#include "Block.h"
#include "academicPerformance.h"
#include "SHA256.h"
#include <fstream>

Block::Block(int idx, academicPerformance d, string prevHash)
{
	index = idx;
	data = d;
	previousHash = prevHash;
	blockHash = generateHash();
	while (blockHash[62] != '0' || blockHash[63] != '0')
	{
		SYSTEMTIME st;
		GetSystemTime(&st);

		data.ms = st.wMilliseconds;

		blockHash.clear();
		blockHash = generateHash();
	}

	string filename = "blockchain/" + d.discipline + "_" + d.creatTime + ".txt";

	for (int i = 11; i < filename.length() - 4; i++)
	{
		if (filename[i] == ' ') filename[i] = '_';
		if (filename[i] == '/') filename[i] = '.';
	}

	ofstream outBinFile(filename, ios::out);

	outBinFile << index << endl;
	outBinFile << d.amount << endl;
	outBinFile << d.senderKey << endl;
	outBinFile << d.receiverKey << endl;
	outBinFile << d.timestamp << endl;
	outBinFile << d.creatTime << endl;
	outBinFile << this->getHash() << endl;
	outBinFile << this->getPreviousHash() << endl;
	outBinFile << d.discipline << endl;


	for (int i = 0; i < d.amount; i++)
	{
		outBinFile << d.studentList[i] << endl;
		outBinFile << d.performanceNumber[i] << endl;
		outBinFile << d.assessments[i] << endl;
	}

	outBinFile.close();
}

int Block::getIndex()
{
	return index;
}

string Block::generateHash()
{
	string toHashS = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp) + to_string(data.ms) + data.discipline;

	for (int i = 0; i < data.studentList.size(); ++i)
	{
		toHashS += data.studentList[i] + to_string(data.performanceNumber[i]) + to_string(data.assessments[i]);
	}

	string hash = sha256(toHashS);
	return hash;
}

string Block::getHash()
{
	return blockHash;
}

string Block::getPreviousHash()
{
	return previousHash;
}

bool Block::isHashValid()
{
	return generateHash() == getHash();
}