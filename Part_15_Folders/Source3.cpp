#include <iostream>
#include <io.h>
#include <direct.h>
using namespace std;

/*3. ����������� ��������� ������������� (�� ���� cmd), ������� �������� ��������� �������:
	 - cls - ������� ������
	 - dir - �������� ���������� ������� �����
	 - type - �������� ���������� ����� (������: type c:\temp\text.txt)
	 - exit - ����� �� ��������� */


//������� ����������� ����������� ����������
void show_dir()
{
	//������ char ��� �������� � ��� ������� ���� � ������� �����
	char* current_dir = new char[4096];

	//������� _getcwd ���������� � current_dir ������ ���� � �����, ��� ��������� ����������� ����
	if (_getcwd(current_dir, 4096) != 0)
		cout << "Current directory is: " << current_dir << endl;
	else
		cout << "Error! Path not found!" << endl;
	strcat(current_dir, "\\");
	strcat(current_dir, "*.*");

	//������� � ����� �� ����� ����������� �����
	_finddata_t c_file;
	long hFile;
	hFile = _findfirst(current_dir, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
			cout << c_file.name << "   " << c_file.size << endl;
	}

	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
				cout << c_file.name << "   " << "<DIR>" << endl;
			else
				cout << c_file.name << "   " << c_file.size << endl;
		}
	}
	_findclose(hFile);
	delete[] current_dir;
	cout << "\n";
}



//������� ����������� ����������� �����
void show_file()
{
	cout << "Enter file path:" << endl;
	//������ char ��� �������� � ��� ���� � �����
	char* FILEpath = new char[4096];
	cin.getline(FILEpath, 4096);

	// ������ ������ �� ��������� ����� � ��������� �� � ����� (���������� �����. ������)
	FILE* f = fopen(FILEpath, "rb");
	if (f != nullptr)
	{
		fseek(f, 0, SEEK_END);
		size_t FileSize = ftell(f);
		fseek(f, 0, SEEK_SET);

		char* buffer = new char [FileSize];

		fread(buffer, sizeof(char), FileSize, f);
		fclose(f);

		//����� ������ �� ������
		for (size_t i = 0; i < FileSize; i++)
		{
			cout << buffer[i];
		}
		cout << "\n\n";

		delete[] buffer;
	}
	else
		cout << "Error opening file!" << endl;

	delete[] FILEpath;
}



void main()
{
	while (true)
	{
		cout << "Test commander [V1.0]" << endl;
		cout << "cls   - Clear screen" << "\n";
		cout << "dir   - Show the contents of the current folder" "\n";
		cout << "type  - Show file content" << "\n";
		cout << "exit  - Exit" << "\n";

		cout << "Enter a command:" << endl;
		char* str = new char[128];
		cin.getline(str, 128);

		if (strcmp(str, "cls") == 0)
			system("cls");
		else if (strcmp(str, "dir") == 0)
			show_dir();
		else if (strcmp(str, "type") == 0)
			show_file();
		else if (strcmp(str, "exit") == 0)
		{
			cout << "Exit successful!" << endl;
			exit(0);
		}
		else
			cout << "Error command!\n" << endl;
	}
}

