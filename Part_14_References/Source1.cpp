#include <iostream>
#include <io.h>
using namespace std;

/*1. ������� ��������� ��������� ������������ ������ � �� ������� ���������� 
	 ������� ��������������, ���������� ������� ����� � ���������� ������������� �����.*/

void func(int** a, int row, int col, double& avg, int& simpl, int& neg)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			avg += a[i][k];									
			neg = (a[i][k] < 0) ? neg + 1 : neg;			//������� ���-�� ������������� �����
		}
	}
	avg /= (row * col);										//������� ������� ��������������


	for (int i = 0; i < row; i++)							//������� ���-�� ������� �����
	{
		for (int k = 0; k < col; k++)
		{
			bool SIMPLE = true;

			if (a[i][k] < 2)
				SIMPLE = false;
			else if (a[i][k] == 2)
				SIMPLE = true;
			else
			{
				for (int j = 2; j < a[i][k]; j++)
					if (a[i][k] % j == 0)
					{
						SIMPLE = false;
						break;
					}
			}

			if (SIMPLE == true) 
				simpl++;
		}
	}
}

void main()
{
	int rows, cols;
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	//���� �������
	cout << "Enter an array: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			cin >> arr[i][k];
		}
	}
	cout << "\n";

	//����� �������
	cout << "Array is: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			cout << arr[i][k] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	//���������� ����������
	double average = 0;
	int simples = 0, negatives = 0;

	//���������
	func(arr, rows, cols, average, simples, negatives);

	cout << "Average = " << average << endl;
	cout << "Number of simples = " << simples << endl;
	cout << "Number of negatives = " << negatives << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	system("pause");
}