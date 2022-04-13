#include <iostream>
using namespace std;

/*4. ������� ��������� ��������� ������������ ������ � ������� �������, ��������, ������� �� �� �����, 
	 � ����� ������ �� ������� � ������� � ������� ������ �� �����.*/

	 //������� ����������� �������!

void fill_matrix(int** a, int row, int col)							//������ ���������� �������
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
	cout << "\n";
}

void max_min_swap(int** a, int row, int col)						//���������� max � min � ����� �� �� �����
{
	int max = a[0][0];
	int min = a[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			if (a[i][k] > max) max = a[i][k];
			if (a[i][k] < min) min = a[i][k];
		}
	}
	cout << "Max = " << max << endl;
	cout << "Min = " << min << endl;
	cout << "\n";

	for (int i = 0; i < row; i++)									//����� �� � ���� ������� ������ swap
	{
		for (int k = 0; k < col; k++)
		{
			if (a[i][k] == min) a[i][k] = max;
			else if (a[i][k] == max) a[i][k] = min;
		}
	}
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

	fill_matrix(p, rows, cols);										//4 ��������� �������

	print_matrix(p, rows, cols);									//5 ������� �� �����

	max_min_swap(p, rows, cols);									//6 ������� max � min, � ������ swap

	cout << "Result is: " << endl;									//7 ������� ��������� �� �����
	print_matrix(p, rows, cols);								

	for (int i = 0; i < rows; i++)									//8 ������� ������
	{
		delete[] p[i];
	}
	delete[] p;

	system("pause");
}