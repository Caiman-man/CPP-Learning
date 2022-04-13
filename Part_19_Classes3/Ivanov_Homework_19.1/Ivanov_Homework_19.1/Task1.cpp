#include <iostream>
#include "String.h"
using namespace std;

/*1. ��� ������ String �������� ��������� ������ :
	- operator ==, != , >= , <=
	- operator +			- ��������� ���� ������ � ������
	- operator -(char ch)	- ������� ��� ��������� ������� ch �� ������*/

void main()
{
	String str("Hello world!");
	str.Print();

	String str2("Hello big world!");
	str2.Print();

	//���������� ���������
	cout << (str == str2) << endl;
	cout << (str != str2) << endl;
	cout << (str <= str2) << endl;
	cout << (str >= str2) << endl;

	//���������� ������
	String add;
	add = str + str2;
	add.Print();

	//�������� ���� �� �������
	String shift;
	shift = add - 'e';
	shift.Print();
}