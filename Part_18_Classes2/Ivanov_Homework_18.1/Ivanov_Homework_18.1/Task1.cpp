#include <iostream>
#include "String.h"
using namespace std;

/*1. ��� ������ String �������� ��������� ������:
	 - Load(char filename[]) - �������� ������ �� �����
	 - operator()(char ch1, char ch2) - �������� � ������ ��� ��������� ����� ����� �� ������
	 - Reverse() - ��������� ������ hello->olleh
	 - Save(char filename[]) - ���������� ������ � ����*/

	 //��� ����������� �������� ��� ����� �������, ������� ������� �� ����� source.txt, � ����� � ��������

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