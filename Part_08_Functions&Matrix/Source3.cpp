#include <iostream>
using namespace std;

/*3. Функция принимает двумерный динамический массив и копирует все нечётные числа 
	 в одномерный динамический массив, после чего результат выводится на экран*/

	//матрица заполняется вручную!

void fill_matrix(int** a, int row, int col)							//ручное заполнение матрицы
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> a[i][k];
		}
	}
}

void print_matrix(int** a, int row, int col)						//вывод на экран матрицы
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

int size_arr(int** a, int row, int col)								//нахождение размера для одномерного массива
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

void copy_arr(int** a, int b[], int row, int col, int size)			//функция для копирования
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

void print_arr(int b[], int size)									//вывод на экран одномерного массива
{
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << "\t";
	}
	cout << "\n";
}


void main()
{
	int rows, cols;													//1 создаем переменные для размеров
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;
	int** p = new int* [rows];										//2 выделяем память на куче под масс. указателей
	for (int i = 0; i < rows; i++)									//3 выделяем память под массивы-строки
	{
		p[i] = new int[cols];
	}
	cout << "Enter an array: " << endl;
	fill_matrix(p, rows, cols);										//4 заполняем матрицу
	cout << "\n";
	print_matrix(p, rows, cols);									//5 выводим на экран
	cout << "\n";

	int size = size_arr(p, rows, cols);								//6 создаем переменную для размера массива
	int* array = new int[size];										//7 выделяем память под одинарный динам массив

	copy_arr(p, array, rows, cols, size);							//8 копируем
	cout << "Result is: " << endl;
	print_arr(array, size);											//9 выводим результат

	for (int i = 0; i < rows; i++)									//10 очищаем память
	{
		delete[] p[i];
	}

	delete[] p;
	delete[] array;

	system("pause");
}