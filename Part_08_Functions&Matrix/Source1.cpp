#include <iostream>
#include <time.h>
using namespace std;

/*1. Пользователь вводит диапазон случайных чисел и размеры двумерного динамического массива.
	 Программа заполняет массив числами в заданном диапазоне и выводит на экран, подсчитав общую сумму.*/

void fill_arr(int** arr, int row, int col, int a_range, int b_range)	//функция для заполнения
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			arr[i][k] = rand() % (b_range - a_range + 1) + a_range;
		}
	}
}


void print_arr(int** arr, int row, int col)								//функция для вывода на экран матрицы
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


int sum_arr(int** arr, int row, int col)								//функция для расчета суммы
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

	int a, b, rows, cols;											//создаем переменные
	cout << "Enter a start of range: " << endl;
	cin >> a;
	cout << "Enter an end of range: " << endl;
	cin >> b;
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;

	int** p = new int* [rows];										//выделяем память на куче под масс. указателей

	for (int i = 0; i < rows; i++)									//выделяем память под массивы-строки
	{
		p[i] = new int[cols];
	}

	fill_arr(p, rows, cols, a, b);									//заполняем
	cout << endl;
	print_arr(p, rows, cols);										//выводим на экран
	cout << endl;
	cout << "Sum is: " << sum_arr(p, rows, cols) << endl;			//считаем сумму и выводим

	for (int i = 0; i < rows; i++)									//очищаем память
	{
		delete[] p[i];
	}

	delete[] p;

	system("pause");
}