#include <iostream>
#include "Strings.h"
#include "StringsException.h"
using namespace std;

/*1. ��� ������ Strings �������� ��������� ������ :
	- ����������� ���� count ��� �������� ���������� ���������� ���� Strings
	- ��� ������ �� �������� ����������� ���������� ������ StringsException ��� ��������� ���������� 
	  (����� �� �������, ������ � �������)
	- ��������� new, delete, new[], delete[], +=, -= (������ �������� ������ �� �������)
	- Save
	- Load*/

void main()
{
	//1. ��������� ��������� += � -=
	cout << "--------------------------" << "\n";
	cout << "   OPERATORS += and -=" << "\n";
	cout << "--------------------------" << "\n";
	Strings lines;
	//������� �� ����� ���-�� ��������� ��������
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
	//�������� -= ������� ��� ��������� ������ "!!!!!"
	lines -= "!!!!!";
	lines.Print();


	//2. ��������� ��������� new � delete
	cout << "--------------------------" << "\n";
	cout << " OPERATORS new and delete" << "\n";
	cout << "--------------------------" << "\n";
	//������� ������ �������� ���� Strings �� 5-�� ���������
	Strings* arr = new Strings[5];
	//������� �� ����� ���-�� ��������� ��������
	cout << "count = " << Strings::Get_count() << endl;
	//��������� � ������� ��������� += ���� ����� � ������ ������ �� �������
	arr[0] += "One";
	arr[0] += "Two";
	arr[0] += "Three";
	arr[0] += "Four";
	arr[0] += "Five";
	arr[0].Print();
	//������� ������
	delete[] arr;
	//����� ������� �� ����� ���-�� ��������� ��������
	cout << "count = " << Strings::Get_count() << endl;


	//3. ��������� ����� Save
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
	//��������� ��������� � ��������� ���� result.txt
	lines2.Save("result.txt");


	//4. ��������� ����� Load
	cout << "-------------------------" << "\n";
	cout << "	   LOAD" << "\n";
	cout << "-------------------------" << "\n";
	//������� ������ �������� ���� Strings �� 5-�� ���������
	Strings* arr2 = new Strings[5];
	//��������� ������ �� ����� load.txt � ��������� ������ ������� (� ����� ������ �� ���������� ����� �� ����������� ��)
	arr2[4].Load("load.txt");
	arr2[4].Print();
	delete[] arr2;


	//5. ��������� try catch
	/*� ������ Add � ����� ����������� ���������� ������� ���������� �� ������ (����� Stretch_lines), 
	  ������� ��� ���������� ����� ����� � ���������� ����������*/
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


	//��� �� ���������� �������������, ���� �� ������� ������� ���� ��� ������/������
	cout << "-------------------------" << "\n";
	cout << "     TRY CATCH (Load)" << "\n";
	cout << "-------------------------" << "\n";
	try
	{
		//� ������ ������� � ������ ���� ����� �� ���������� txt, ��� ������� ������� ���� ��� ������
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