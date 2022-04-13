#include <iostream>
using namespace std;

/*4. Функция принимает двумерный динамический массив и находит минимум, максимум, выводит их на экран, 
	 а потом меняет их местами в массиве и выводит массив на экран.*/

	 //матрица заполняется вручную!

void fill_matrix(int** a, int row, int col)							//ручное заполнение матрицы
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
	cout << "\n";
}

void max_min_swap(int** a, int row, int col)						//нахождение max и min и вывод их на экран
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

	for (int i = 0; i < row; i++)									//сразу же в этой функции делаем swap
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

	fill_matrix(p, rows, cols);										//4 заполняем матрицу

	print_matrix(p, rows, cols);									//5 выводим на экран

	max_min_swap(p, rows, cols);									//6 находим max и min, и делаем swap

	cout << "Result is: " << endl;									//7 выводим результат на экран
	print_matrix(p, rows, cols);								

	for (int i = 0; i < rows; i++)									//8 очищаем память
	{
		delete[] p[i];
	}
	delete[] p;

	system("pause");
}