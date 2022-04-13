#include <iostream>
#include <io.h>
#include <direct.h>
using namespace std;

/*2. Пользователь вводит путь к исходной папке,
	 Программа копирует все файлы из исходной папки в результирующую папку, которую тоже указывает пользователь.
	 + Обрабатывать подпапки исходной папки.*/

	 //Программа полностью копирует файлы и папки сохраняя структуру


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




// функция обхода дерева
void Skan_dir_file(const char* crs_path, const char* dst_path, const char* mask)
{
	//создаю три динам. массива типа char для записи в них пути к файлам
	char* MASKpath = new char[4096];
	char* new_SRCpath = new char[4096];
	char* new_DSTpath = new char[4096];

	//в массив MASKpath записываю полный путь к изначальной папке (вместе с маской)
	strcpy(MASKpath, crs_path);
	strcat(MASKpath, "\\");
	strcat(MASKpath, mask);

	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;
	// адрес списка найденных файлов
	long hFile;
	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(MASKpath, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
		{
			cout << c_file.name << "   " << "<DIR>" << endl;

			strcpy(new_SRCpath, crs_path);
			strcat(new_SRCpath, "\\");
			strcat(new_SRCpath, c_file.name);

			strcpy(new_DSTpath, dst_path);
			strcat(new_DSTpath, "\\");
			strcat(new_DSTpath, c_file.name);

			//если проверяемый файл - это папка, то создаем подпапку, указывая путь назначения в результ. папку
			_mkdir(new_DSTpath);

			//рекурсивно запускаем функцию Skan_dir_file
			Skan_dir_file(new_SRCpath, new_DSTpath, mask);
		}
		else
		{
			cout << crs_path << "\\" << c_file.name << "   " << c_file.size << endl;

			strcpy(new_SRCpath, crs_path);
			strcat(new_SRCpath, "\\");
			strcat(new_SRCpath, c_file.name);

			strcpy(new_DSTpath, dst_path);
			strcat(new_DSTpath, "\\");
			strcat(new_DSTpath, c_file.name);

			//копирование файла
			Copy_file(new_SRCpath, new_DSTpath);
		}

	}
	// цикл для получения информации об остальных найденных файлах
	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
			{
				cout << c_file.name << "   " << "<DIR>" << endl;

				strcpy(new_SRCpath, crs_path);
				strcat(new_SRCpath, "\\");
				strcat(new_SRCpath, c_file.name);

				strcpy(new_DSTpath, dst_path);
				strcat(new_DSTpath, "\\");
				strcat(new_DSTpath, c_file.name);

				//если проверяемый файл - это папка, то создаем подпапку, указывая путь назначения в результ. папку
				_mkdir(new_DSTpath);

				//рекурсивно запускаем функцию Skan_dir_file
				Skan_dir_file(new_SRCpath, new_DSTpath, mask);
			}
			else
			{
				cout << crs_path << "\\" << c_file.name << "   " << c_file.size << endl;

				strcpy(new_SRCpath, crs_path);
				strcat(new_SRCpath, "\\");
				strcat(new_SRCpath, c_file.name);

				strcpy(new_DSTpath, dst_path);
				strcat(new_DSTpath, "\\");
				strcat(new_DSTpath, c_file.name);

				//копирование файла
				Copy_file(new_SRCpath, new_DSTpath);
			}
		}
	}
	// освободить память от списка найденных файлов
	_findclose(hFile);

	delete[] MASKpath;
	delete[] new_SRCpath;
	delete[] new_DSTpath;
}



void main()
{
	char SRCpath[256], DSTpath[256];
	cout << "Enter source folder path: " << endl;
	cin.getline(SRCpath, 256);
	cout << "\nEnter destination folder path: " << endl;
	cin.getline(DSTpath, 256);

	Skan_dir_file(SRCpath, DSTpath, "*.*");

	system("pause");
}