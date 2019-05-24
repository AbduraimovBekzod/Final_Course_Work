#pragma once

#ifndef academicPerformance_h
#define academicPerformance_h

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>


using namespace std;

struct academicPerformance
{
	int ms;
	int amount; //количество
	string senderKey; //отправитель
	string receiverKey; //получатель
	time_t timestamp;
	string creatTime; //дата создания
	string discipline; //название предмета
	vector<string> studentList; //список студентов
	vector<int> performanceNumber; //номер зачётки
	vector<int> assessments; //оценки

	academicPerformance() {};

	academicPerformance(string file, string sender, string receiver, time_t time)
	{
		SYSTEMTIME st;
		GetSystemTime(&st);

		ms = st.wMilliseconds;
		ifstream statement;
		statement.open(file, ios_base::in);

		statement >> amount;
		senderKey = sender;
		receiverKey = receiver;
		timestamp = time;
		creatTime = to_string(st.wDay) + "/" + to_string(st.wMonth) + "/" + to_string(st.wYear);

		getline(statement, discipline);
		getline(statement, discipline);

		for (int i = 0; i < amount; ++i)
		{
			string tmp;
			statement >> tmp;
			studentList.push_back(tmp);

			int _tmp;

			statement >> _tmp;
			performanceNumber.push_back(_tmp);

			statement >> _tmp;
			assessments.push_back(_tmp);
		}
	};

	~academicPerformance()
	{
		string().swap(senderKey);
		string().swap(receiverKey);
		string().swap(creatTime);
		string().swap(discipline);
		studentList.swap(studentList);
		performanceNumber.swap(performanceNumber);
		assessments.swap(assessments);
		ms = 0;
		amount = 0;
		timestamp = 0;
	};
};

#endif /* academicPerformance_h */