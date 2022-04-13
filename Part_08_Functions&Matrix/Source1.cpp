#include <iostream>
#include <time.h>
using namespace std;

/*1. ������������ ������ �������� ��������� ����� � ������� ���������� ������������� �������.
	 ��������� ��������� ������ ������� � �������� ��������� � ������� �� �����, ��������� ����� �����.*/

void fill_arr(int** arr, int row, int col, int a_range, int b_range)	//������� ��� ����������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			arr[i][k] = rand() % (b_range - a_range + 1) + a_range;
		}
	}
}


void print_arr(int** arr, int row, int col)								//������� ��� ������ �� ����� �������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << arr[i][k] << "\t";
		}
		cout << endl;
	}
}


int sum_arr(int** arr, int row, int col)								//������� ��� ������� �����
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			sum += arr[i][k];
		}
	}
	return sum;
}


void main()
{
	srand(time(0));

	int a, b, rows, cols;											//������� ����������
	cout << "Enter a start of range: " << endl;
	cin >> a;
	cout << "Enter an end of range: " << endl;
	cin >> b;
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;

	int** p = new int* [rows];										//�������� ������ �� ���� ��� ����. ����������

	for (int i = 0; i < rows; i++)									//�������� ������ ��� �������-������
	{
		p[i] = new int[cols];
	}

	fill_arr(p, rows, cols, a, b);									//���������
	cout << endl;
	print_arr(p, rows, cols);										//������� �� �����
	cout << endl;
	cout << "Sum is: " << sum_arr(p, rows, cols) << endl;			//������� ����� � �������

	for (int i = 0; i < rows; i++)									//������� ������
	{
		delete[] p[i];
	}

	delete[] p;

	system("pause");
}