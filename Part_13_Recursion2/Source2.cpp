#include <iostream>
using namespace std;

/*2. Пользователь вводит двумерный динамический массив, 
	 программа находит сумму нечётных отрицательных элементов.*/

//функция для расчета суммы нечётных отрицательных элементов в одной строке
int Sum_1(int* a, int cols)
{
	int res = 0;
	if (cols == 0)
		return 0;
	else
		res = Sum_1(a, cols - 1);

	if (a[cols - 1] % 2 == -1 && a[cols - 1] < 0)
		return res + a[cols - 1];
	else
		return res;
}

//функция для расчета суммы каждой строки
int Sum_2(int** a, int rows, int cols)
{
	int res = 0;
	if (rows == 0)
		return 0;
	else
		res = Sum_2(a, rows - 1, cols);

	return res + Sum_1(a[rows - 1], cols);
}


void main()
{
	int rows, cols;													
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of cols: " << endl;
	cin >> cols;
	int** p = new int* [rows];									
	for (int i = 0; i < rows; i++)								
	{
		p[i] = new int[cols];
	}

	//ввод массива
	cout << "Enter an array: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			cin >> p[i][k];
		}
	}
	cout << "\n";

	//вывод массива
	cout << "Array is: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			cout << p[i][k] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	//результат
	cout << "Result is: " << Sum_2(p, rows, cols) << endl;

	for (int i = 0; i < rows; i++)	
	{
		delete[] p[i];
	}
	delete[] p;

	system("pause");
}