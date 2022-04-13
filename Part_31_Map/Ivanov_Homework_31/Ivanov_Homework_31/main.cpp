#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <io.h>
#include <algorithm>
#include <ctime>
using namespace std;

/*1. Пользователь вводит название папки.
	 Программа сканирует в этой папке все текстовые файлы 
	 и создаёт частотный словарь слов, найденных во всех текстах.
	 Cлова могут состоять только из букв, иначе они не попадают в частотный словарь.
  2. Частотный словарь сохранить в файл результата в виде списка слов и частот, 
	 предварительно отсортировав их по частотам в порядке возрастания*/

void main()
{
	
	//переменная для хранения названия папки
	char* folder = new char[4000];
	char* folder_mask = new char[4000];
	//map для хранения и автоматической сортировки ключей
	map <string, size_t> dictionary;
	//переменная для хранения считанных слов
	string word;

	cout << "Enter folder path: \n";
	cin.getline(folder, 4000);
	strcpy(folder_mask, folder);
	strcat(folder_mask, "\\*.txt");
	unsigned int start_time = clock();
	//Получения информации о первом файле
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

		//открываем поток для чтения из исходного файла
		fstream file_in(file_path, ios::in);

		if (!file_in.fail())
		{
			while (!file_in.eof())
			{
				//считываем слова в строку
				file_in >> word;

				//удаляем все знаки препинания в словах с помощью лямбда-функции
				auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
				word.erase(it, word.end());
				//удаляем все цифры в словах с помощью лямбда-функции
				auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
				word.erase(it_2, word.end());

				//добавляем значение в map, если ключ 'word' уже существует, то значение увеличится на 1
				dictionary[word]++;

				//2й вариант добавления
				//auto it_3(word);
				//dictionary[it_3]++;
			}
			file_in.close();
		}
		else cout << "Error opening file!" << endl;

		delete[] file_path;
	}

	//цикл для получения информации об остальных найденных файлах
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

			//открываем поток для чтения из исходного файла
			fstream file_in(file_path, ios::in);

			if (!file_in.fail())
			{
				while (!file_in.eof())
				{
					//считываем слова в строку
					file_in >> word;

					//удаляем все знаки препинания в словах с помощью лямбда-функции
					auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
					word.erase(it, word.end());
					//удаляем все цифры в словах с помощью лямбда-функции
					auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
					word.erase(it_2, word.end());

					//добавляем значение в map, если ключ 'word' уже существует, то значение увеличится на 1
					dictionary[word]++;

					//2й вариант добавления
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
	// освободить память от списка найденных файлов
	_findclose(hFile);

	//выводим на экран список слов
	cout << "Elements from MAP before sorting: \n";
	map <string, size_t>::iterator pos;
	for (pos = dictionary.begin(); pos != dictionary.end(); pos++)
	{
		cout << pos->first << " -> " << pos->second << endl;
	}
	
	//создаем вектор пар и копируем в него пары из map'a
	vector <pair<string, size_t>> v;
	v.reserve(dictionary.size());
	for (pos = dictionary.begin(); pos != dictionary.end(); pos++)
	{
		v.push_back(pair <string, size_t>(pos->first, pos->second));
	}

	//2й вариант - переместить из map'a все значения в вектор
	//move(dictionary.begin(), dictionary.end(), back_inserter(v));

	//сортируем вектор по второму значению в паре с помощью лямбда-функции
	sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second < b.second; });

	//выводим на экран отсортированный результат
	cout << "\nElements from VECTOR after sorting: \n";
	for (const auto& pair : v)
	{
		cout << pair.second << " -> " << pair.first << endl;
	}

	//открываем поток для записи в результирующий файл
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
