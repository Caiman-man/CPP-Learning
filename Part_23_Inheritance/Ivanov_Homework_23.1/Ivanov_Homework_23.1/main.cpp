#include <iostream>
#include "Points.h"
using namespace std;

/*1. Разработать класс, который хранит динамический массив точек на плоскости.
	 Для класса реализовать следующие методы:
	 - конструктор с параметрами
	 - конструктор копирования
	 - operator =
	 - деструктор
	 - Print
	 - Save
	 - Load*/

void main()
{
	// 1. создание массива обьектов из 5ти элементов (конструктор по умолчанию)
	Points* arr = new Points[5];
	// вывод 1го обьекта
	arr->Print();


	// 2. создание нового обьекта и вызов конструктора копирования
	Points* arr2 = arr;
	// вывод 2го обьекта
	arr2[2].Print();


	// 3. создание нового обьекта 
	Points* arr3 = new Points;
	// вызов оператора =						
	// (команда cout << "Operator = " из метода, не выводится на экран)
	arr3 = arr2;
	// вывод 3го обьекта
	arr3[3].Print();
	// а вот если присвоить какой-то конкретный обьект, то сообщение выведется на экран
	arr3[0] = arr2[4];
	arr3[0].Print();


	//4. создаем еще один обьект (конструктор с парaметрами)
	Points* pnt = new Points(-10, 15);
	pnt->Print();
	cout << "------------------------------\n";


	// 5. Загрузка
	Points* f = new Points[5];
	try
	{
		f->Load(f, "load.txt");
	}
	catch (const char* ex)
	{
		cout << "ERROR! " << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}
	//вывод
	f[0].Print();
	f[1].Print();
	f[2].Print();
	f[3].Print();
	f[4].Print();


	// 6. Сохранение
	// меняем значения в двух обьектах, что бы проверить правильность сохранения в файл
	f[0] = *pnt;
	f[2] = *pnt;
	//вывод
	f[0].Print();
	f[1].Print();
	f[2].Print();
	f[3].Print();
	f[4].Print();
	try
	{
		f->Save(f, 5, "result.txt");
	}
	catch (const char* ex)
	{
		cout << "ERROR! " << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}


	// 7. очистка памяти и вызов деструкторов	
	cout << "------------------------------\n";
	// тут компилятор ругается, если я пытаюсь удалить память arr2 или arr3
	//delete[] arr3;
	//delete[] arr2;
	delete[] arr;
	delete pnt;
}