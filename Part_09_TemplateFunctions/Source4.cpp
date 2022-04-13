#include <iostream>
using namespace std;

/* 4. ������������ ������ ������� ���������� ������� � ��� ������. 
	  ��������� ������ ������� 2 � 3 ������� ����� �������, ����� ���� ������� ������ �� �����.*/

template <typename T>
void fill_matrix(T** a, int row, int col)							//������ ���������� �������
{
	cout << "Enter an array: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << "\n";
}

template <typename T>
void print_matrix(T** a, int row, int col)							//����� �� ����� �������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

template <typename T>
void swap_matrix(T** a, int row, int col)							//swap 2 � 3 ��������
{
	T temp;
	for (int i = 0; i < row; i++)
	{
		temp = a[i][1];
		a[i][1] = a[i][2];
		a[i][2] = temp;
	}
	cout << endl;
}

void main()
{
	int rows, cols;													//������� ������������ ��������� ������
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of columns: " << endl;
	cin >> cols;

	if (cols < 3)
	{
		cout << "Error! Please enter no less then 3 columns" << endl;
		system("pause");
	}
	else 
	{
		int** p = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			p[i] = new int[cols];
		}

		fill_matrix(p, rows, cols);										//��������� ������
		cout << "Before: " << endl;
		print_matrix(p, rows, cols);									//������� �� ����� ��
		swap_matrix(p, rows, cols);										//������ ������� 2 � 3 �������
		cout << "After: " << endl;
		print_matrix(p, rows, cols);									//������� �� ����� �����

		for (int i = 0; i < rows; i++)
		{
			delete[] p[i];
		}
		delete[] p;

		system("pause");
	}
}