#include <iostream>
#include "String.h"
using namespace std;

/*1. Для класса String добавить следующие методы:
	 - Load(char filename[]) - загрузка строки из файла
	 - operator()(char ch1, char ch2) - заменяет в строке все вхождения одной буквы на другую
	 - Reverse() - переворот строки hello->olleh
	 - Save(char filename[]) - сохранение строки в файл*/

	 //Все манипуляции делаются над одной строкой, которая берется из файла source.txt, в папке с проектом

void main()
{
	String str;
	str.Load("source.txt");
	cout << "Before changes: " << endl;
	str.Print();

	str.operator() ('u', '!');
	str.Reverse();
	str.Save("result.txt");
	cout << "After changes: " << endl;
	str.Print();
}