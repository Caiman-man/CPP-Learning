#include <iostream>
#include "String.h"
using namespace std;

/*1. Для класса String добавить следующие методы :
	- operator ==, != , >= , <=
	- operator +			- добавляет одну строку к другой
	- operator -(char ch)	- удаляет все вхождения символа ch из строки*/

void main()
{
	String str("Hello world!");
	str.Print();

	String str2("Hello big world!");
	str2.Print();

	//логические операторы
	cout << (str == str2) << endl;
	cout << (str != str2) << endl;
	cout << (str <= str2) << endl;
	cout << (str >= str2) << endl;

	//добавление строки
	String add;
	add = str + str2;
	add.Print();

	//удаление букв со сдвигом
	String shift;
	shift = add - 'e';
	shift.Print();
}