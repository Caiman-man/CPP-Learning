#include <iostream>
#include <io.h>
using namespace std;

/*1. Пользователь вводит путь к исходной папке,
	 Программа копирует все файлы из исходной папки в результирующую папку, которую тоже указывает пользователь.*/


// функция копирования файла
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

	//создаю три динам. массива типа char для записи в них пути к файлам
	char* MASKpath = new char[1024];
	char* new_SRCpath = new char[1024];
	char* new_DSTpath = new char[1024];

	//в массив MASKpath записываю полный путь к изначальной папке (вместе с маской)
	strcpy(MASKpath, SRCpath);
	strcat(MASKpath, "\\");
	strcat(MASKpath, "*.*");

	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;
	// адрес списка найденных файлов
	long hFile;
	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(MASKpath, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
		{
			cout << c_file.name << "   " << c_file.size << endl;

			//что бы функция Copy_file сработала, в неё необходимо передавать полные пути к изначальному и результирующему файлам
			strcpy(new_SRCpath, SRCpath);
			strcat(new_SRCpath, "\\");
			strcat(new_SRCpath, c_file.name);

			strcpy(new_DSTpath, DSTpath);
			strcat(new_DSTpath, "\\");
			strcat(new_DSTpath, c_file.name);

			//копирование файла
			Copy_file(new_SRCpath, new_DSTpath);
		}
	}

	// цикл для обработки остальных найденных файлов
	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
				cout << c_file.name << "   " << "<DIR>" << endl;
			else
			{
				cout << c_file.name << "   " << c_file.size << endl;

				//что бы функция Copy_file сработала, в неё необходимо передавать полные пути к изначальному и результирующему файлам
				strcpy(new_SRCpath, SRCpath);
				strcat(new_SRCpath, "\\");
				strcat(new_SRCpath, c_file.name);

				strcpy(new_DSTpath, DSTpath);
				strcat(new_DSTpath, "\\");
				strcat(new_DSTpath, c_file.name);

				//копирование файла
				Copy_file(new_SRCpath, new_DSTpath);
			}
		}
	}

	_findclose(hFile);

	system("pause");
}