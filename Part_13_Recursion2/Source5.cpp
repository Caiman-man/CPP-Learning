#include <iostream>
#include <io.h>
using namespace std;

/*5. Пользователь вводит путь к папке и маску файлов, 
	 программа подсчитывает общий размер файлов с указанной маской.*/

void main()
{
	char path[256], extension[8];
	printf("Enter file path : \n");
	scanf("%s", &path);
	printf("Enter file extension \n");
	scanf("%s", &extension);
	strcat(path, extension);

	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;
	// адрес списка найденных файлов
	long hFile;
	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(path, &c_file);

	//задаем переменную "sum" типа long, для подсчета суммы размеров файлов
	long sum = 0;
	// если файл является папкой
	if (c_file.attrib & _A_SUBDIR)
		cout << c_file.name << "   " << "<DIR>" << endl;
	else
	{
		cout << c_file.name << "   " << c_file.size << endl;
		sum = c_file.size;
	}

	// цикл для получения информации об остальных найденных файлах
	while (_findnext(hFile, &c_file) == 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else 
		{
			cout << c_file.name << "   " << c_file.size << endl;
			sum += c_file.size;
		}
	}
	cout << "\n";
	cout << "Sum = " << sum << endl;

	// освободить память от списка найденных файлов
	_findclose(hFile);
}