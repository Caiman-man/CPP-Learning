#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

/*1. Добавить в класс LinkedList следующие методы:
	 - Element * Find(char* str) - находит первое вхождение элемента списка по значению
	 - void Clear() - очищает все элементы списка
	 - void Insert(char* str, int pos) - вставляет элемент перед элементом с указанной позицией
	 - void Delete(int pos) - удаление элемента по позиции
	 - void DeleteAll(char* str) - удаление всех вхождений строки в список
	 - operator ==	- сравнение списков
	 - operator +	- добавление элемента в конец списка
	 - operator +	- добавление списка в конец списка
	 - operator +=	- добавление списка в конец списка
	 
	 На основе класса LinkedList разработать класс DoubleLinkedList, каждый элемент которого имеет 2 указателя:
	 'prev' - указатель на предыдущий элемент, и 'next' - указатель на следующий элемент.
	 Изменить все существующие методы и добавить следующие:
	 - PrintBack() - просмотр списка в обратном порядке
	 - AddFirst(const char* str) - добавление в начало списка
	 - Save(const char* filename) - сохранение списка в файл (fstream) - сюрприз!
	 - Load(const char* filename) - загрузка списка из файла (fstream)*/

void main()
{
	//1. Add / AddFirst / Operator '+' / PrintBack
	DoubleLinkedList list;
	DoubleLinkedList list2;
	cout << "1. ADD / ADDFIRST / OPERATOR '+' / PRINTBACK\n";
	cout << "LIST #1:\n";
	list.Add("C++");
	list + "C#";
	list + "Java";
	list.AddFirst("C");
	list.Print();
	cout << "\nLIST #1 REVERSE:\n";
	list.PrintBack();

	cout << "\nLIST #2:\n";
	list2.Add("Ruby");
	list2.Add("PHP");
	list2.Add("Swift");
	list2.Print();
	cout << "---------------------------------------------\n";


	//2. Find
	cout << "2. FIND\n";
	try
	{
		cout << "Result of find 'Java' is: " << list.Find("Java") << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!\n";
	}
	cout << "---------------------------------------------\n";


	//3. Clear
	cout << "3. CLEAR\n";
	list2.Clear();
	cout << "---------------------------------------------\n";


	//4. Insert
	cout << "4. INSERT 'Obj C'\n";
	try
	{
		list.Insert("Obj C", 1);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	list.Print();
	cout << "---------------------------------------------\n";


	//5. Delete
	cout << "5. DELETE\n";
	try
	{
		list.Delete(1);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	list.Print();
	cout << "---------------------------------------------\n";


	//6. DeleteAll
	cout << "6. DELETE_ALL 'C#'\n";
	DoubleLinkedList list3;
	list3.Add("C#");
	list3.Add("Java");
	list3.Add("C#");
	list3.Add("Kotlin");
	list3.Add("C#");
	list3.Print();
	cout << "\nAfter deletion 'C#':\n";
	list3.DeleteAll("C#");
	list3.Print();
	cout << "---------------------------------------------\n";


	//7. operator ==
	cout << "7. OPERATOR ==\n";
	list2.Add("JS");
	list2.Add("Kotlin");
	list2.Add("Python");
	cout << "Result of compare list#1 and list#2 is: " << (list == list2) << endl;
	cout << "---------------------------------------------\n";


	//8. operator +
	cout << "8. OPERATOR + list\n";
	DoubleLinkedList list4 = list + list2;
	cout << "Merge result of list#1 and list#2 is: \n";
	list4.Print();
	cout << "---------------------------------------------\n";


	//9. operator +=
	cout << "9. OPERATOR +=\n";
	DoubleLinkedList list5;
	list5.Add(".NET");
	list5.Add("HTML");
	list5.Add("CSS");
	list5 += list;
	cout << "Merge result of list#5 and list#1 is: \n";
	list5.Print();
	cout << "---------------------------------------------\n";


	//10. Save
	cout << "10. SAVE\n";
	list5.Save("result");
	cout << "---------------------------------------------\n";


	//11. Load
	DoubleLinkedList list6;
	cout << "11. LOAD\n";
	list6.Load("load.txt");
	list6.Print();
}
