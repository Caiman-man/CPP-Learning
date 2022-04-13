#include <iostream>
#include "Matrix.h"
using namespace std;

/*2. ��� ������ Matrix (��������� ������������ ������) �������� ��������� ������:
	- Copy constr
	- operator =
	- operator ==, !=
	- operator+ (int n)		- ���������� n �� ���� ������ �������
	- operator+ (Matrix m)	- ���������� 2 ������� �����������, ���� ������� �����*/

void main()
{
	//����������� ��� ����������
	cout << "Example without arguments:" << endl;
	Matrix matrix;
	matrix.Print();

	//����������� � �����������
	cout << "Example with arguments:" << endl;
	Matrix matrix2(3, 4);
	matrix2.Print();

	//����������� �����������
	Matrix copy = matrix2;
	copy.Print();

	//�������� =
	Matrix assign;
	assign = copy;
	assign.Print();

	//��������� ���������
	cout << (matrix == matrix2) << endl;
	cout << (matrix != matrix2) << endl;

	//�������� + n
	Matrix add;
	add = matrix2 + 3;
	add.Print();

	//�������� + Matrix n
	Matrix addMatrix;
	addMatrix = matrix2 + matrix2;
	addMatrix.Print();
}