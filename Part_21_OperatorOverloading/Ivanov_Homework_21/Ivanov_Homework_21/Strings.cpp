#include "Strings.h"
#include "StringsException.h"
#include <iostream>
#include <fstream>
using namespace std;

//Инициализация статического поля класса
int Strings::count = 0;

//Конструктор по умолчанию
Strings::Strings()
{
	cout << "constr" << "\n";
	max_lines_count = 10;
	reserve_size = 5;
	fill_count = 0;
	str = new char* [max_lines_count];
	//увеличиваем счетчик кол-ва обьектов 
	count++;
}

//Конструктор с параметрами
Strings::Strings(size_t lines)
{
	cout << "Constr" << "\n";
	max_lines_count = lines;
	reserve_size = 5;
	fill_count = 0;
	str = new char* [max_lines_count];
	//увеличиваем счетчик кол-ва обьектов 
	count++;
}

//Конструктор копирования
Strings::Strings(const Strings& source)
{
	cout << "Copy constr" << "\n";
	max_lines_count = source.max_lines_count;
	fill_count = source.fill_count;
	str = new char* [max_lines_count];

	for (size_t i = 0; i < fill_count; i++)
	{
		str[i] = new char[strlen(source.str[i]) + 1];
		strcpy(str[i], source.str[i]);
	}
	//увеличиваем счетчик кол-ва обьектов 
	count++;
}

//Оператор =
Strings& Strings::operator= (const Strings& source)
{
	if (max_lines_count != source.max_lines_count)
	{
		for (size_t i = 0; i < fill_count; i++)
		{
			delete[] str[i];
		}
		delete[] str;

		max_lines_count = source.max_lines_count;
		fill_count = source.fill_count;
		str = new char* [max_lines_count];
	}

	for (size_t i = 0; i < fill_count; i++)
	{
		str[i] = new char[strlen(source.str[i]) + 1];
		strcpy(str[i], source.str[i]);
	}

	return *this;
}

//Оператор new
void* Strings::operator new(size_t t)
{
	void* p = malloc(t);
	cout << "operator new, Size = " << t << "\n";
	return  p;
}

//Оператор delete
void Strings::operator delete(void* p)
{
	cout << "operator delete" << "\n";
	free(p);
}

//Оператор new[]
void* Strings::operator new[](size_t t)
{
	void* p = malloc(t);
	cout << "operator new[], Size = " << t << "\n";
	return  p;
}

//Оператор delete[]
void Strings::operator delete[](void* p)
{
	cout << "operator delete[]" << "\n";
	free(p);
}

//operator[]
char* Strings::operator[](int pos)
{
	if (pos >= 0 && pos < fill_count)
	{
		return str[pos];
	}
	else return 0;
}

//Оператор +=
Strings& Strings::operator+= (const char* s)
{
	//в случае, если кол-во текущих строк больше чем максимальных, то вызываем метод Stretch_lines()
	if (fill_count >= max_lines_count)
		Stretch_lines();

	str[fill_count] = new char[strlen(s) + 1];
	strcpy(str[fill_count], s);
	fill_count++;

	return *this;
}

//Оператор -=
Strings& Strings::operator-= (const char* s)
{
	for (size_t i = 0; i < fill_count; i++)
	{
		//если среди текущего кол-ва заполненных строк есть совпадающие со строкой 's'
		if (strcmp(str[i], s) == 0)
		{
			for (int k = i; k < fill_count - 1; k++)
			{
				//очищаем память найденной строки
				delete[] str[k];
				//выделяем память заного нужного нам размера (размер следующей строки)
				str[k] = new char[strlen(str[k + 1]) + 1];
				//копируем следующую строку на место текущей, и сдвигаем массив
				strcpy(str[k], str[k + 1]);
			}
			i--;
			fill_count--;
		}
	}
	return *this;
}

//Метод Add (добавление строки)
void Strings::Add(const char* s)
{
	if (fill_count >= max_lines_count)
		throw new StringsException(1, "The current lines number is greater than the maximum!");

	str[fill_count] = new char[strlen(s) + 1];
	strcpy(str[fill_count], s);
	fill_count++;
}

//Метод Save
void Strings::Save(const char filepath[])
{
	ofstream f1;
	f1.open(filepath);
	if (f1.is_open())
	{
		for (size_t i = 0; i < fill_count; i++)
		{
			f1 << str[i] << "\n";
		}
		f1.close();
		cout << "The file saved successfully!" << "\n";
	}
	else
		throw new StringsException(2, "Error opening file for saving!");
}

//Метод Load
void Strings::Load(const char filepath[])
{
	ifstream f2;
	f2.open(filepath);
	if (f2.is_open())
	{
		//если текущее кол-во строк больше нуля, то очищаю эти строки, и обнуляю fill_count
		if (fill_count > 0)
		{
			for (size_t i = 0; i < fill_count; i++)
			{
				delete[] str[i];
			}
		}
		fill_count = 0;

		//цикл пока не закончится файл
		while (!f2.eof())
		{
			/*памяти для str[i] необходимо выделить столько, сколько символов есть в строке в файле
			как изначально посчитать кол-во символов в строке в файле, до того как выделить память я не знаю
			поэтому я создал указатель на массив чаров "buffer", куда считываю строку*/
			char* buffer = new char[1024];
			f2.getline(buffer, 1024);
			//далее вычисляю с помощью strlen сколько считалось символов, и использую это значение для выделения памяти под str[i]
			str[fill_count] = new char[strlen(buffer) + 1];
			//далее копирую строку из буфера в str[i] и удаляю буфер
			strcpy(str[fill_count], buffer);
			delete[] buffer;

			fill_count++;
			//в случае, если кол-во строк в файле больше чем максимальных, то вызываем метод Stretch_lines()
			if (fill_count >= max_lines_count)
				Stretch_lines();
		}
		f2.close();
		cout << "The file loaded successfully!" << "\n";
	}
	else
		throw new StringsException(3, "Error opening load file!");
}

//Метод увеличения максимального кол-ва строк
void Strings::Stretch_lines()
{
	cout << "Stretch_lines" << endl;
	char** new_str = new char* [max_lines_count + reserve_size];

	for (size_t i = 0; i < max_lines_count; i++)
	{
		new_str[i] = str[i];
	}

	delete[] str;
	str = new_str;
	max_lines_count += reserve_size;
}

//Деструктор
Strings::~Strings()
{
	cout << "destr" << "\n";
	for (size_t i = 0; i < fill_count; i++)
	{
		delete[] str[i];
	}
	delete[] str;
	//уменьшаем счетчик кол-ва обьектов 
	count--;
}

//Вывод
void Strings::Print()
{
	cout << endl;
	for (size_t i = 0; i < fill_count; i++)
	{
		cout << str[i] << endl;
	}
	//выводим текущее и максимальное кол-во строк
	cout << "\nfill_count = " << fill_count << "\n";
	cout << "max_lines_count = " << max_lines_count << "\n\n";
}

//Статический метод возврата значения count
int Strings::Get_count()
{
	return count;
}