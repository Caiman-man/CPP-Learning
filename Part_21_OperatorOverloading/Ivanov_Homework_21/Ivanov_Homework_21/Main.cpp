#include <iostream>
#include "Strings.h"
#include "StringsException.h"
using namespace std;

/*1. Для класса Strings добавить следующие методы :
	- статическое поле count для подсчёта количества переменных типа Strings
	- при работе со строками выбрасывать переменную класса StringsException для обработки исключений 
	  (выход за границы, работа с файлами)
	- операторы new, delete, new[], delete[], +=, -= (полное удаление строки из массива)
	- Save
	- Load*/

void main()
{
	//1. Проверяем операторы += и -=
	cout << "--------------------------" << "\n";
	cout << "   OPERATORS += and -=" << "\n";
	cout << "--------------------------" << "\n";
	Strings lines;
	//выводим на экран кол-во созданных обьектов
	cout << "count = " << Strings::Get_count() << endl;
	lines += "One";
	lines += "Two";
	lines += "!!!!!";
	lines += "Four";
	lines += "Five";
	lines += "!!!!!";
	lines += "Seven";
	lines += "!!!!!";
	lines += "Nine";
	lines += "!!!!!";
	lines.Print();
	//оператор -= удаляет все вхождения строки "!!!!!"
	lines -= "!!!!!";
	lines.Print();


	//2. Проверяем операторы new и delete
	cout << "--------------------------" << "\n";
	cout << " OPERATORS new and delete" << "\n";
	cout << "--------------------------" << "\n";
	//создаем массив обьектов типа Strings из 5-ти элементов
	Strings* arr = new Strings[5];
	//выводим на экран кол-во созданных обьектов
	cout << "count = " << Strings::Get_count() << endl;
	//добавляем с помощью оператора += пять строк в первый обьект из массива
	arr[0] += "One";
	arr[0] += "Two";
	arr[0] += "Three";
	arr[0] += "Four";
	arr[0] += "Five";
	arr[0].Print();
	//удаляем массив
	delete[] arr;
	//снова выводим на экран кол-во созданных обьектов
	cout << "count = " << Strings::Get_count() << endl;


	//3. Проверяем метод Save
	cout << "--------------------------" << "\n";
	cout << "	   SAVE" << "\n";
	cout << "--------------------------" << "\n";
	Strings lines2;
	lines2 += "One minute";
	lines2 += "Two hours";
	lines2 += "Three days";
	lines2 += "Four weeks";
	lines2 += "Five years";
	lines2.Print();
	//результат сохраняем в текстовый файл result.txt
	lines2.Save("result.txt");


	//4. Проверяем метод Load
	cout << "-------------------------" << "\n";
	cout << "	   LOAD" << "\n";
	cout << "-------------------------" << "\n";
	//создаем массив обьектов типа Strings из 5-ти элементов
	Strings* arr2 = new Strings[5];
	//загружаем строки из файла load.txt в последний обьект массива (в файле данные из телефонной книги из предыдущего ДЗ)
	arr2[4].Load("load.txt");
	arr2[4].Print();
	delete[] arr2;


	//5. Проверяем try catch
	/*В методе Add я убрал возможность увеличения массива указателей на строки (метод Stretch_lines), 
	  поэтому при добавлении новых строк я выбрасываю исключение*/
	cout << "-------------------------" << "\n";
	cout << "     TRY CATCH (Add)" << "\n";
	cout << "-------------------------" << "\n";
	Strings lines3(3);
	try
	{
		lines3.Add("First string");
		lines3.Add("Second string");
		lines3.Add("Third string");
		lines3.Add("Fourth string");
	}
	catch (StringsException* exeption)
	{
		exeption->PrintException();
		delete exeption;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}
	lines3.Print();


	//Так же исключение выбрасывается, если не удалось открыть файл для чтения/записи
	cout << "-------------------------" << "\n";
	cout << "     TRY CATCH (Load)" << "\n";
	cout << "-------------------------" << "\n";
	try
	{
		//В данном примере я удалил одну букву из расширения txt, при попытке открыть файл для чтения
		lines3.Load("load2.tx");
	}
	catch (StringsException* exeption)
	{
		exeption->PrintException();
		delete exeption;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}
	lines3.Print();
}