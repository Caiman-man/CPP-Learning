#include <iostream>
#include <io.h>
using namespace std;

/*2. ������������ ����� �������� �����,
	 ��������� ������������ ����� ������ ���� ������ � ���� ����� � � ���������,
	 � ����� ������������ ���������� ��������*/

	//2� ������� - ������� ���������� � ������ � ���-�� �� �������

void Dir_Count(const char* dir_path, const char* mask, long long& res_total_size, long& res_dir_count)
{
	char* new_path = new char[4096];
	char* mask_path = new char[4096];

	strcpy(mask_path, dir_path);
	strcat(mask_path, "\\");
	strcat(mask_path, mask);

	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;

	// ����� ������ ��������� ������
	long hFile;

	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
	hFile = _findfirst(mask_path, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
		{
			res_dir_count++;
			cout << c_file.name << "   " << "<DIR>" << endl;

			strcpy(new_path, dir_path);
			strcat(new_path, "\\");
			strcat(new_path, c_file.name);

			Dir_Count(new_path, mask, res_total_size, res_dir_count);
		}
		else
		{
			cout << dir_path << "\\" << c_file.name << "   " << c_file.size << endl;
			res_total_size += c_file.size;
		}

	}


	// ���� ��� ��������� ���������� �� ��������� ��������� ������
	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
			{
				res_dir_count++;
				cout << c_file.name << "   " << "<DIR>" << endl;

				strcpy(new_path, dir_path);
				strcat(new_path, "\\");
				strcat(new_path, c_file.name);

				Dir_Count(new_path, mask, res_total_size, res_dir_count);
			}
			else
			{
				cout << dir_path << "\\" << c_file.name << "   " << c_file.size << endl;
				res_total_size += c_file.size;
			}
		}
	}

	// ���������� ������ �� ������ ��������� ������
	_findclose(hFile);

	delete[] new_path;
	delete[] mask_path;
}

void main()
{
	char path[256];
	cout << "Enter folder path: " << endl;
	cin.getline(path, 256);

	long long size = 0;
	long amount = 0;
	Dir_Count(path, "*.*", size, amount);
	cout << "Total file size = " << size << endl;
	cout << "Amount of subdirectories = " << amount << endl;
}