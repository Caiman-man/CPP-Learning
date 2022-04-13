#include <iostream>
#include "Person.h"
using namespace std;

/*1. ����������� ����� Person, ������� �������� ��������� ����� ������:
	 - ������� 5 �����								
	 - ����������� ��� ����������					
	 - ����������� � �����������					
	 - print() - ������ �� �����				
	 - ������� / ������� ��� ������� � �����*/


void main()
{
	//����� ������������ � �����������
	Person student("Alexander", "Ivanov", 29, 1.95, 98.5);
	student.Print();
	//��������� ������-���������� ������� student � ������� ��������
	student.set_Name("Rick");
	student.set_LastName("Sanches");
	student.set_Age(30);
	student.set_Height(1.97);
	student.set_Weight(99.4);
	student.Print();
	cout <<"---------------------------"<<endl;

	//����� ������������ �� ���������
	Person man;
	man.Print();
	//��������� ������-���������� ������� man � ������� ��������
	man.set_Name("Bilbo");
	man.set_LastName("Beggins");
	man.set_Age(60);
	man.set_Height(1.55);
	man.set_Weight(69.5);
	man.Print();

	//������������� �������� ��� ��������� ������ �� �������� ����� ������
	char *b_firstname = man.get_Name();
	char *b_lastname = man.get_LastName();
	int b_age = man.get_Age();
	double b_height = man.get_Height();
	double b_weight = man.get_Weight();
	cout << "---------------------------" << endl;
	cout << "Bilbo's name: " << b_firstname << "\nBilbo's lastname: " << b_lastname << "\nBilbo's age: " << b_age << "\nBilbo's height: " << b_height << "\nBilbo's weight: " << b_weight << endl;
}