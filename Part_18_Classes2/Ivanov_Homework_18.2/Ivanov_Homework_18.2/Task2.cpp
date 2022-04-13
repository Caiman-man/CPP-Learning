#include <iostream>
#include "Matrix.h"
using namespace std;

/*2. ��� ������ Matrix (��������� ������������ ������) �������� ��������� ������:
	 - ������������ � ����������� � ���
	 - ����������
	 - int& operator() (int x, int y) - ������ � ������ (������ ������ � �������) - m(3, 5) = 23;
	 - print();
	 - Save(char filename[]) - ���������� ������� � ����
	 - Load(char filename[]) - �������� ������� �� �����*/

void main()
{
	//�������� ������� � ������� ������������ ��� ����������
	cout << "Example without arguments:" << endl;
	Matrix matrix;
	matrix.Print();

	//�������� ()
	matrix(1, 1) = 777;				
	matrix.Print();

	int a = matrix(1, 1);
	cout << "Middle element is: "<< a << "\n\n";

	//���������� ������� � ����
	matrix.Save("result.txt");

	//�������� ������� �� �����
	cout << "Example from file:" << endl;
	matrix.Load("matrix.txt");
	matrix.Print();

	//�������� ������� � ������� ������������ � �����������
	cout << "Example with arguments:" << endl;
	Matrix matrix2(5, 4);
	matrix2.Print();
}