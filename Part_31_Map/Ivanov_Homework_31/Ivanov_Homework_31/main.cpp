#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <io.h>
#include <algorithm>
#include <ctime>
using namespace std;

/*1. ������������ ������ �������� �����.
	 ��������� ��������� � ���� ����� ��� ��������� ����� 
	 � ������ ��������� ������� ����, ��������� �� ���� �������.
	 C���� ����� �������� ������ �� ����, ����� ��� �� �������� � ��������� �������.
  2. ��������� ������� ��������� � ���� ���������� � ���� ������ ���� � ������, 
	 �������������� ������������ �� �� �������� � ������� �����������*/

void main()
{
	
	//���������� ��� �������� �������� �����
	char* folder = new char[4000];
	char* folder_mask = new char[4000];
	//map ��� �������� � �������������� ���������� ������
	map <string, size_t> dictionary;
	//���������� ��� �������� ��������� ����
	string word;

	cout << "Enter folder path: \n";
	cin.getline(folder, 4000);
	strcpy(folder_mask, folder);
	strcat(folder_mask, "\\*.txt");
	unsigned int start_time = clock();
	//��������� ���������� � ������ �����
	_finddata_t c_file;
	intptr_t hFile;
	hFile = _findfirst(folder_mask, &c_file);
	if (c_file.attrib & _A_SUBDIR)
		cout << c_file.name << "   " << "<DIR>" << endl;
	else
	{
		cout << c_file.name << "   " << c_file.size << endl;

		char* file_path = new char[4000];
		strcpy(file_path, folder);
		strcat(file_path, "\\");
		strcat(file_path, c_file.name);

		//��������� ����� ��� ������ �� ��������� �����
		fstream file_in(file_path, ios::in);

		if (!file_in.fail())
		{
			while (!file_in.eof())
			{
				//��������� ����� � ������
				file_in >> word;

				//������� ��� ����� ���������� � ������ � ������� ������-�������
				auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
				word.erase(it, word.end());
				//������� ��� ����� � ������ � ������� ������-�������
				auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
				word.erase(it_2, word.end());

				//��������� �������� � map, ���� ���� 'word' ��� ����������, �� �������� ���������� �� 1
				dictionary[word]++;

				//2� ������� ����������
				//auto it_3(word);
				//dictionary[it_3]++;
			}
			file_in.close();
		}
		else cout << "Error opening file!" << endl;

		delete[] file_path;
	}

	//���� ��� ��������� ���������� �� ��������� ��������� ������
	while (_findnext(hFile, &c_file) == 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
		{
			cout << c_file.name << "   " << c_file.size << endl;

			char* file_path = new char[4000];
			strcpy(file_path, folder);
			strcat(file_path, "\\");
			strcat(file_path, c_file.name);

			//��������� ����� ��� ������ �� ��������� �����
			fstream file_in(file_path, ios::in);

			if (!file_in.fail())
			{
				while (!file_in.eof())
				{
					//��������� ����� � ������
					file_in >> word;

					//������� ��� ����� ���������� � ������ � ������� ������-�������
					auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
					word.erase(it, word.end());
					//������� ��� ����� � ������ � ������� ������-�������
					auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
					word.erase(it_2, word.end());

					//��������� �������� � map, ���� ���� 'word' ��� ����������, �� �������� ���������� �� 1
					dictionary[word]++;

					//2� ������� ����������
					//auto it_3(word);
					//dictionary[it_3]++;
				}
				file_in.close();
			}
			else cout << "Error opening file!" << endl;

			delete[] file_path;
		}
	}
	cout << "\n";
	// ���������� ������ �� ������ ��������� ������
	_findclose(hFile);

	//������� �� ����� ������ ����
	cout << "Elements from MAP before sorting: \n";
	map <string, size_t>::iterator pos;
	for (pos = dictionary.begin(); pos != dictionary.end(); pos++)
	{
		cout << pos->first << " -> " << pos->second << endl;
	}
	
	//������� ������ ��� � �������� � ���� ���� �� map'a
	vector <pair<string, size_t>> v;
	v.reserve(dictionary.size());
	for (pos = dictionary.begin(); pos != dictionary.end(); pos++)
	{
		v.push_back(pair <string, size_t>(pos->first, pos->second));
	}

	//2� ������� - ����������� �� map'a ��� �������� � ������
	//move(dictionary.begin(), dictionary.end(), back_inserter(v));

	//��������� ������ �� ������� �������� � ���� � ������� ������-�������
	sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

	//������� �� ����� ��������������� ���������
	cout << "\nElements from VECTOR after sorting: \n";
	for (const auto& pair : v)
	{
		cout << pair.second << " -> " << pair.first << endl;
	}

	//��������� ����� ��� ������ � �������������� ����
	fstream file_out("result.txt", ios::out);

	for (const auto& pair : v)
	{
		file_out << pair.second << " -> " << pair.first << endl;
	}

	file_out.close();
	cout << "\nThe file has been successfully written! \n";

	delete[] folder;
	delete[] folder_mask;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time / 1000.0 << endl;
}
