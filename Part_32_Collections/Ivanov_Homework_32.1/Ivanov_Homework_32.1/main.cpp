#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

/*1. ƒл€ двусв€зного списка добавить следующие методы:
	 - operator ++, которые добавл€ют к каждому элементу '!' (префикc, посфикс)
	 - operator --, который удал€ет одну букву в конце строки  (префикc, посфикс)
	 - operator >>, << выводит на экран и в файл (друзь€ класса)*/

void main()
{
	//1. Operator ++
	cout << "1. OPERATOR ++\n";
	DoubleLinkedList list;
	list.Add("C#");
	list.Add("Java");
	list.Add("Kotlin");
	cout << "BEFORE: \n";
	list.Print();
	cout << "\n";

	list++;
	list++;
	++list;
	++list;
	cout << "AFTER: \n";
	list.Print();
	cout << "---------------------------------------------\n";

	//2. Operator --
	cout << "2. OPERATOR --\n";
	DoubleLinkedList list2;
	list2.Add("Ruby1234");
	list2.Add("PHP1234");
	list2.Add("Swift1234");
	cout << "BEFORE: \n";
	list2.Print();
	cout << "\n";

	list2--;
	list2--;
	--list2;
	--list2;
	cout << "AFTER: \n";
	list2.Print();
	cout << "---------------------------------------------\n";

	//3. Operator <<
	cout << "3. OPERATOR <<\n";
	cout << list << "\n" <<list << "\n" << list2;
	cout << "---------------------------------------------\n";

	//4. Operator >>
	cout << "4. OPERATOR >>\n";
	DoubleLinkedList list3;
	cin >> list3;
	list3.Print();
	cout << "---------------------------------------------\n";
}
