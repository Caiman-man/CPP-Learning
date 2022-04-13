#include <iostream>
#include "Points.h"
using namespace std;

/*1. ����������� �����, ������� ������ ������������ ������ ����� �� ���������.
	 ��� ������ ����������� ��������� ������:
	 - ����������� � �����������
	 - ����������� �����������
	 - operator =
	 - ����������
	 - Print
	 - Save
	 - Load*/

void main()
{
	// 1. �������� ������� �������� �� 5�� ��������� (����������� �� ���������)
	Points* arr = new Points[5];
	// ����� 1�� �������
	arr->Print();


	// 2. �������� ������ ������� � ����� ������������ �����������
	Points* arr2 = arr;
	// ����� 2�� �������
	arr2[2].Print();


	// 3. �������� ������ ������� 
	Points* arr3 = new Points;
	// ����� ��������� =						
	// (������� cout << "Operator = " �� ������, �� ��������� �� �����)
	arr3 = arr2;
	// ����� 3�� �������
	arr3[3].Print();
	// � ��� ���� ��������� �����-�� ���������� ������, �� ��������� ��������� �� �����
	arr3[0] = arr2[4];
	arr3[0].Print();


	//4. ������� ��� ���� ������ (����������� � ���a�������)
	Points* pnt = new Points(-10, 15);
	pnt->Print();
	cout << "------------------------------\n";


	// 5. ��������
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
	//�����
	f[0].Print();
	f[1].Print();
	f[2].Print();
	f[3].Print();
	f[4].Print();


	// 6. ����������
	// ������ �������� � ���� ��������, ��� �� ��������� ������������ ���������� � ����
	f[0] = *pnt;
	f[2] = *pnt;
	//�����
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


	// 7. ������� ������ � ����� ������������	
	cout << "------------------------------\n";
	// ��� ���������� ��������, ���� � ������� ������� ������ arr2 ��� arr3
	//delete[] arr3;
	//delete[] arr2;
	delete[] arr;
	delete pnt;
}