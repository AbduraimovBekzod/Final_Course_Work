#include "FCW_Form.h"
/*
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

int Main()
{
	setlocale(LC_ALL, "Russian");
	ofstream f("LOL.txt");
	f.clear();
	WIN32_FIND_DATAA findData;
	HANDLE hf;
	vector<string> namef;

	hf = FindFirstFileA("C:\\Users\\Абдураимовы\\source\\repos\\Final_Course_Work\\Final_Course_Work\\blockchain\\*", &findData);

	if (hf == INVALID_HANDLE_VALUE)
	{
		f << "Cannot find file" << endl;
		return -1;
	}

	do
	{
		f << findData.cFileName << endl;
	} while (FindNextFileA(hf, &findData));

	FindClose(hf);
	f.close();
	system("pause");
	return 0;
}*/

using namespace FinalCourseWork;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(cli::array<String^>^ args) 
{
	/*
	ofstream outBinFile("out.bin", ios::out | ios::binary);

	int a = 21;
	int b;

	outBinFile.write((char*)&a, sizeof(a));
	outBinFile.write((char*)& a, sizeof(a));
	outBinFile.close();

	ifstream inBinFile("out.bin", ios::in | ios::binary);

	inBinFile.read((char*)&b, sizeof(b));
	*/
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew FCW_Form());
}