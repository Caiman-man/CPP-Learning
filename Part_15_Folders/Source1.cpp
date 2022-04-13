#include <iostream>
#include <io.h>
using namespace std;

/*1. ������������ ������ ���� � �������� �����,
	 ��������� �������� ��� ����� �� �������� ����� � �������������� �����, ������� ���� ��������� ������������.*/


// ������� ����������� �����
void Copy_file(char* SRCname, char* DSTname)											
{
	FILE* srcFile = fopen(SRCname, "rb");
	if (srcFile != nullptr)
	{
		fseek(srcFile, 0, SEEK_END);
		size_t fileSize = ftell(srcFile);
		fseek(srcFile, 0, SEEK_SET);
		char* buffer = new char[fileSize];

		if (buffer != nullptr)
		{
			fread(buffer, sizeof(char), fileSize, srcFile);

			FILE* dstFile = fopen(DSTname, "wb");
			if (dstFile != nullptr)
			{
				fwrite(buffer, sizeof(char), fileSize, dstFile);
				fclose(dstFile);
			}

			delete[] buffer;
		}
		fclose(srcFile);
		cout << "File copied successfully!" << endl;
	}
	else
		cout << "Error opening file!" << endl;
}



void main()
{
	char SRCpath[256], DSTpath[256];
	cout << "Enter source folder path: " << endl;
	cin.getline(SRCpath, 256);
	cout << "\nEnter destination folder path: " << endl;
	cin.getline(DSTpath, 256);

	//������ ��� �����. ������� ���� char ��� ������ � ��� ���� � ������
	char* MASKpath = new char[1024];
	char* new_SRCpath = new char[1024];
	char* new_DSTpath = new char[1024];

	//� ������ MASKpath ��������� ������ ���� � ����������� ����� (������ � ������)
	strcpy(MASKpath, SRCpath);
	strcat(MASKpath, "\\");
	strcat(MASKpath, "*.*");

	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;
	// ����� ������ ��������� ������
	long hFile;
	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
	hFile = _findfirst(MASKpath, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
		{
			cout << c_file.name << "   " << c_file.size << endl;

			//��� �� ������� Copy_file ���������, � �� ���������� ���������� ������ ���� � ������������ � ��������������� ������
			strcpy(new_SRCpath, SRCpath);
			strcat(new_SRCpath, "\\");
			strcat(new_SRCpath, c_file.name);

			strcpy(new_DSTpath, DSTpath);
			strcat(new_DSTpath, "\\");
			strcat(new_DSTpath, c_file.name);

			//����������� �����
			Copy_file(new_SRCpath, new_DSTpath);
		}
	}

	// ���� ��� ��������� ��������� ��������� ������
	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
				cout << c_file.name << "   " << "<DIR>" << endl;
			else
			{
				cout << c_file.name << "   " << c_file.size << endl;

				//��� �� ������� Copy_file ���������, � �� ���������� ���������� ������ ���� � ������������ � ��������������� ������
				strcpy(new_SRCpath, SRCpath);
				strcat(new_SRCpath, "\\");
				strcat(new_SRCpath, c_file.name);

				strcpy(new_DSTpath, DSTpath);
				strcat(new_DSTpath, "\\");
				strcat(new_DSTpath, c_file.name);

				//����������� �����
				Copy_file(new_SRCpath, new_DSTpath);
			}
		}
	}

	_findclose(hFile);

	system("pause");
}