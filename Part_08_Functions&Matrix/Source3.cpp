#include <iostream>
using namespace std;

/*3. ������� ��������� ��������� ������������ ������ � �������� ��� �������� ����� 
	 � ���������� ������������ ������, ����� ���� ��������� ��������� �� �����*/

	//������� ����������� �������!

void fill_matrix(int** a, int row, int col)							//������ ���������� �������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> a[i][k];
		}
	}
}

void print_matrix(int** a, int row, int col)						//����� �� ����� �������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << "\t";
		}
		cout << "\n";
	}
}

int size_arr(int** a, int row, int col)								//���������� ������� ��� ����������� �������
{
	int res = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if (a[i][k] % 2 != 0) res++;	
		}
	}
	return res;
}

void copy_arr(int** a, int b[], int row, int col, int size)			//������� ��� �����������
{
	int s = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if (a[i][k] % 2 != 0)
			{
				b[s] = a[i][k];
				s++;
			}
		}
	}
}

void print_arr(int b[], int size)									//����� �� ����� ����������� �������
{
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << "\t";
	}
	cout << "\n";
}


void main()
{
	int rows, cols;													//1 ������� ���������� ��� ��������
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;
	int** p = new int* [rows];										//2 �������� ������ �� ���� ��� ����. ����������
	for (int i = 0; i < rows; i++)									//3 �������� ������ ��� �������-������
	{
		p[i] = new int[cols];
	}
	cout << "Enter an array: " << endl;
	fill_matrix(p, rows, cols);										//4 ��������� �������
	cout << "\n";
	print_matrix(p, rows, cols);									//5 ������� �� �����
	cout << "\n";

	int size = size_arr(p, rows, cols);								//6 ������� ���������� ��� ������� �������
	int* array = new int[size];										//7 �������� ������ ��� ��������� ����� ������

	copy_arr(p, array, rows, cols, size);							//8 ��������
	cout << "Result is: " << endl;
	print_arr(array, size);											//9 ������� ���������

	for (int i = 0; i < rows; i++)									//10 ������� ������
	{
		delete[] p[i];
	}

	delete[] p;
	delete[] array;

	system("pause");
}