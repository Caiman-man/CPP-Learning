#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

/*1. �������� � ����� LinkedList ��������� ������:
	 - Element * Find(char* str) - ������� ������ ��������� �������� ������ �� ��������
	 - void Clear() - ������� ��� �������� ������
	 - void Insert(char* str, int pos) - ��������� ������� ����� ��������� � ��������� ��������
	 - void Delete(int pos) - �������� �������� �� �������
	 - void DeleteAll(char* str) - �������� ���� ��������� ������ � ������
	 - operator ==	- ��������� �������
	 - operator +	- ���������� �������� � ����� ������
	 - operator +	- ���������� ������ � ����� ������
	 - operator +=	- ���������� ������ � ����� ������
	 
	 �� ������ ������ LinkedList ����������� ����� DoubleLinkedList, ������ ������� �������� ����� 2 ���������:
	 'prev' - ��������� �� ���������� �������, � 'next' - ��������� �� ��������� �������.
	 �������� ��� ������������ ������ � �������� ���������:
	 - PrintBack() - �������� ������ � �������� �������
	 - AddFirst(const char* str) - ���������� � ������ ������
	 - Save(const char* filename) - ���������� ������ � ���� (fstream) - �������!
	 - Load(const char* filename) - �������� ������ �� ����� (fstream)*/

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
