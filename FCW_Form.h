#pragma once

#include "Blockchain.h"
#include <msclr/marshal_cppstd.h>
#include "MyForm.h"
#include <iostream>
#include <Windows.h>
#include <fstream>


namespace FinalCourseWork
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FCW_Form
	/// </summary>
	public ref class FCW_Form : public System::Windows::Forms::Form
	{
	public:
		FCW_Form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FCW_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ view_block_file;
	protected:

	private: System::Windows::Forms::TextBox^ receiverKey;
	protected:

	private: System::Windows::Forms::TextBox^ senderKey;

	private: System::Windows::Forms::TextBox^ block_file;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ load_block_file;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->view_block_file = (gcnew System::Windows::Forms::Button());
			this->receiverKey = (gcnew System::Windows::Forms::TextBox());
			this->senderKey = (gcnew System::Windows::Forms::TextBox());
			this->block_file = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->load_block_file = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// view_block_file
			// 
			this->view_block_file->Location = System::Drawing::Point(55, 108);
			this->view_block_file->Name = L"view_block_file";
			this->view_block_file->Size = System::Drawing::Size(75, 23);
			this->view_block_file->TabIndex = 0;
			this->view_block_file->Text = L"Обзор...";
			this->view_block_file->UseVisualStyleBackColor = true;
			this->view_block_file->Click += gcnew System::EventHandler(this, &FCW_Form::View_block_file_Click);
			// 
			// receiverKey
			// 
			this->receiverKey->Location = System::Drawing::Point(145, 205);
			this->receiverKey->Name = L"receiverKey";
			this->receiverKey->Size = System::Drawing::Size(337, 20);
			this->receiverKey->TabIndex = 1;
			// 
			// senderKey
			// 
			this->senderKey->Location = System::Drawing::Point(145, 157);
			this->senderKey->Name = L"senderKey";
			this->senderKey->Size = System::Drawing::Size(337, 20);
			this->senderKey->TabIndex = 2;
			// 
			// block_file
			// 
			this->block_file->Location = System::Drawing::Point(145, 110);
			this->block_file->Name = L"block_file";
			this->block_file->Size = System::Drawing::Size(337, 20);
			this->block_file->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 208);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Получатель";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(57, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Отправитель";
			// 
			// load_block_file
			// 
			this->load_block_file->Location = System::Drawing::Point(232, 283);
			this->load_block_file->Name = L"load_block_file";
			this->load_block_file->Size = System::Drawing::Size(75, 23);
			this->load_block_file->TabIndex = 6;
			this->load_block_file->Text = L"Загрузить";
			this->load_block_file->UseVisualStyleBackColor = true;
			this->load_block_file->Click += gcnew System::EventHandler(this, &FCW_Form::Load_block_file_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(229, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 7;
			// 
			// FCW_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 375);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->load_block_file);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->block_file);
			this->Controls->Add(this->senderKey);
			this->Controls->Add(this->receiverKey);
			this->Controls->Add(this->view_block_file);
			this->Name = L"FCW_Form";
			this->Text = L"FCW_Form";
			this->Load += gcnew System::EventHandler(this, &FCW_Form::FCW_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void View_block_file_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			block_file->Text = openFileDialog1->FileName;
		}
	}

	private: System::Void FCW_Form_Load(System::Object^ sender, System::EventArgs^ e)
	{
		/*
		vector<string> nameFiles;

		WIN32_FIND_DATAA findData;
		HANDLE hf;
		hf = FindFirstFileA("C:\\Users\\Абдураимовы\\source\\repos\\Final_Course_Work\\Final_Course_Work\\blockchain\\*", &findData);

		do
		{
			nameFiles.push_back(findData.cFileName);
		} while (FindNextFileA(hf, &findData));

		FindClose(hf);

		nameFiles.erase(nameFiles.begin());
		nameFiles.erase(nameFiles.begin());

		if (nameFiles.size() == 0)
		{
			time_t current;

			academicPerformance d("Genesis.txt", "Genesis", "Genesis", time(&current));

			Block genesis(0, d, "0");
		}*/
	}

	private: System::Void Load_block_file_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (block_file->Text != "" && receiverKey->Text != "" && senderKey->Text != "")
		{
			vector<string> nameFiles;
			string blockHash;
			string blockPrevHash;
			int blockIndex;
			bool flag = true;

			WIN32_FIND_DATAA findData;
			HANDLE hf;
			hf = FindFirstFileA("C:\\Users\\Абдураимовы\\source\\repos\\Final_Course_Work\\Final_Course_Work\\blockchain\\*", &findData);

			do
			{
				nameFiles.push_back(findData.cFileName);
			} while (FindNextFileA(hf, &findData));

			FindClose(hf);

			nameFiles.erase(nameFiles.begin());
			nameFiles.erase(nameFiles.begin());


			time_t data1Time;
			academicPerformance data1(msclr::interop::marshal_as<string>(block_file->Text), msclr::interop::marshal_as<string>(senderKey->Text), msclr::interop::marshal_as<string>(receiverKey->Text), time(&data1Time));

			blockIndex = nameFiles.size();

			for (int i = 0; i < nameFiles.size(); i++)
			{
				if (nameFiles[i] == "Genesis.txt")
				{
					ifstream blockFile("blockchain/" + nameFiles[i], ios::in);
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);
					blockHash.clear();
					getline(blockFile, blockHash);

					nameFiles.erase(nameFiles.begin() + i);
					blockFile.close();
					break;
				}
			}

			while (nameFiles.size() > 0)
			{
				for (int i = 0; i < nameFiles.size(); i++)
				{
					string tmp;
					ifstream blockFile("blockchain/" + nameFiles[i], ios::in | ios::binary);

					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					getline(blockFile, blockPrevHash);
					blockPrevHash.clear();
					blockFile >> tmp;
					blockFile >> blockPrevHash;
					

					if (blockHash == blockPrevHash)
					{
						blockHash.clear();
						blockHash = tmp;
						blockPrevHash.clear();
						tmp.clear();
						nameFiles.erase(nameFiles.begin() + i);
						break;
					}
					else
					{
						if (i == nameFiles.size()) flag = false;

						blockPrevHash.clear();
						tmp.clear();
						continue;
					}

					if (!flag) break;
				}
			}

			if (!flag)
			{
				label3->Text = "Произошла ошибка! Нарушена целостность цепочки! Блок не добавлен!";
			}
			else
			{
				Block* newBlock = new Block(blockIndex, data1, blockHash);
				label3->Text = "Блок добавлен!";
				delete newBlock;
			}

			block_file->Text = "";
			senderKey->Text = "";
			receiverKey->Text = "";
		}
	}
	};
};