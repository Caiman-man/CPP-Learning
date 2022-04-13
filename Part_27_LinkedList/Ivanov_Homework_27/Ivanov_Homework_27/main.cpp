#include <iostream>
#include "LinkedList.h"
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
	 - operator +=	- ���������� ������ � ����� ������*/

void main()
{
	//������� ��� ������, � ��������� � ��� ������
	LinkedList list;
	LinkedList list2;
	cout << "LIST #1:\n";
	list.Add("C");
	list.Add("C++");
	list.Add("C#");
	list.Add("Java");
	list.Print();

	cout << "\nLIST #2:\n";
	list2.Add("Ruby");
	list2.Add("PHP");
	list2.Add("Swift");
	list2.Print();
	cout << "--------------------------------\n";

	//1. Find
	cout << "1. FIND\n";
	char s[] = "C++";
	try
	{
		cout << list.Find(s) << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!\n";
	}
	cout << "--------------------------------\n";

	//2. Clear
	cout << "2. CLEAR\n";
	list2.Clear();
	cout << "Add elements to list #2 again:\n";
	list2.Add("JS");
	list2.Add("Kotlin");
	list2.Add("Python");
	list2.Print();
	cout << "--------------------------------\n";

	//3. Insert
	cout << "3. INSERT\n";
	char s2[] = "SQL";
	try
	{
		list2.Insert(s2, 0);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	list2.Print();
	cout << "--------------------------------\n";

	//4. Delete
	cout << "4. DELETE\n";
	try
	{
		list2.Delete(0);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	list2.Print();
	cout << "--------------------------------\n";

	//5. DeleteAll
	cout << "5. DELETE_ALL\n";
	char s3[] = "Kotlin";
	list2.DeleteAll(s3);
	list2.Print();
	cout << "--------------------------------\n";

	//6. operator ==
	cout << "6. OPERATOR ==\n";
	cout << "Result is: " << (list == list2) << endl;
	cout << "--------------------------------\n";

	//7. operator +
	cout << "7. OPERATOR + element\n";
	list2.Clear();
	list2 + "GO";
	list2 + "Obj C";
	list2.Print();
	cout << "--------------------------------\n";

	//8. operator +
	cout << "8. OPERATOR + list\n";
	LinkedList list3 = list + list2;
	list3.Print();
	cout << "--------------------------------\n";

	//9. operator +=
	cout << "9. OPERATOR +=\n";
	LinkedList list4;
	list4.Add(".NET");
	list4.Add("HTML");
	list4.Add("CSS");
	list4 += list;
	list4.Print();
}
