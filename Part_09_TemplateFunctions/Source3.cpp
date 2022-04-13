#include <iostream>
using namespace std;

/* 3. ������������ ������ ������� ���������� ������� � ��� ������. 
	  ��������� ������� ������������ ����� � ������ � ������������ ����������� ����� � �������, 
	  ���� ����� ���������� � �������.*/

  /*1. ������ ������������ ��������� ������
	2. ������ ��� ���������� �������, ��� �� ��������� ���� ��������� �����, � �������� ��������
	   ������� ������ �������� ����� ���-�� �����/�������� ��������������
	3. ������ �������, ������� ���� ������������ ������� � ������ ������, ���������� ��� � ���������� ������, 
	   � ����� ���������� ����������� ������� �� ����� �������
	4. ������ �������, ������� ���� ����������� ������� � ������ �������, ���������� ��� � ���������� ������, 
	   � ����� ���������� ������������ ������� �� ����� �������
	5. ���� ������������ �������� ����� ����������  �����  ������������� �� ���������, �� ��� � ���� �������� �������*/

template <typename T>
void fill_matrix(T** a, int row, int col)											//������ ���������� �������
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
void print_matrix(T** a, int row, int col)											//����� �� ����� �������
{
	cout << "Array is: " << endl;
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
T find_max(T** a, T arr_max[], int row, int col)									//������� ������ ���� ���������� �� �������					
{
	T max = 0, size = 0;
	for (int i = 0; i < row; i++)													//����� ���������� � �����
	{
		max = a[i][0];
		for (int k = 0; k < col; k++)
		{
			max = (a[i][k] > max) ? a[i][k] : max;
		}
		arr_max[size] = max;														//���������� ����������� ������� �����������
		size++;
	}

	T MIN_of_max = arr_max[0];
	for (int i = 0; i < size; i++)													//����� ������������ �������� ����� ����������
	{
		MIN_of_max = (arr_max[i] < MIN_of_max) ? arr_max[i] : MIN_of_max;
	}
	return MIN_of_max;
}

template <typename T>
T find_min(T** a, T arr_min[], int row, int col)									//������� ������ ���� ��������� �� ��������
{
	T min = 0, size = 0;
	for (int k = 0; k < col; k++)													//����� ��������� � �����
	{
		min = a[0][k];
		for (int i = 0; i < row; i++)
		{
			min = (a[i][k] < min) ? a[i][k] : min;
		}
		arr_min[size] = min;														//���������� ����������� ������� ����������
		size++;
	}

	T MAX_of_min = arr_min[0];
	for (int i = 0; i < size; i++)													//����� ������������� �������� ����� ���������
	{
		MAX_of_min = (arr_min[i] > MAX_of_min) ? arr_min[i] : MAX_of_min;
	}
	return MAX_of_min;
}


void main()
{
	int rows, cols;																	//������� ������������ ��������� ������
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of columns: " << endl;
	cin >> cols;
	int** p = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		p[i] = new int[cols];
	}

	fill_matrix(p, rows, cols);														//��������� �������
	print_matrix(p, rows, cols);													//������� �� ����� �������

	int* arr_max = new int[rows];													//������� ��� ������������ ���������� �������
	int* arr_min = new int[cols];

	if (find_max(p, arr_max, rows, cols) == find_min(p, arr_min, rows, cols))		//��������� ���� �� �������� ������� � �������
		cout <<"Saddle element is: " << find_max(p, arr_min, rows, cols) << endl;
	else cout << "Saddle elements not found" << endl;

	delete[]arr_max;																//������� ������
	delete[]arr_min;

	for (int i = 0; i < rows; i++)
	{
		delete[] p[i];
	}
	delete[] p;

	system("pause");
}