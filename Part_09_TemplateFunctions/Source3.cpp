#include <iostream>
using namespace std;

/* 3. Пользователь вводит размеры двумерного массива и сам массив. 
	  Программа находит максимальное число в строке и одновременно минимальное число в столбце, 
	  если такое существует в массиве.*/

  /*1. Создаю динамический двумерный массив
	2. Создаю два одномерных массива, что бы сохранить туда максимумы строк, и минимумы столбцов
	   размеры данных массивов равны кол-ву строк/столбцов соответственно
	3. Создаю функцию, которая ищет максимальный элемент в каждой строке, записывает его в одномерный массив, 
	   а потом возвращает минимальный элемент из этого массива
	4. Создаю функцию, которая ищет минимальный элемент в каждом столбце, записывает его в одномерный массив, 
	   а потом возвращает максимальный элемент из этого массива
	5. Если миниммальное значение среди максимумов  равно  максимальному из минимумов, то это и есть седловой элемент*/

template <typename T>
void fill_matrix(T** a, int row, int col)											//ручное заполнение матрицы
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
void print_matrix(T** a, int row, int col)											//вывод на экран матрицы
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
T find_max(T** a, T arr_max[], int row, int col)									//функция поиска всех максимумов по строкам					
{
	T max = 0, size = 0;
	for (int i = 0; i < row; i++)													//поиск максимумов в цикле
	{
		max = a[i][0];
		for (int k = 0; k < col; k++)
		{
			max = (a[i][k] > max) ? a[i][k] : max;
		}
		arr_max[size] = max;														//заполнения одномерного массива максимумами
		size++;
	}

	T MIN_of_max = arr_max[0];
	for (int i = 0; i < size; i++)													//поиск минимального значения среди максимумов
	{
		MIN_of_max = (arr_max[i] < MIN_of_max) ? arr_max[i] : MIN_of_max;
	}
	return MIN_of_max;
}

template <typename T>
T find_min(T** a, T arr_min[], int row, int col)									//функция поиска всех минимумов по столбцам
{
	T min = 0, size = 0;
	for (int k = 0; k < col; k++)													//поиск минимумов в цикле
	{
		min = a[0][k];
		for (int i = 0; i < row; i++)
		{
			min = (a[i][k] < min) ? a[i][k] : min;
		}
		arr_min[size] = min;														//заполнения одномерного массива минимумами
		size++;
	}

	T MAX_of_min = arr_min[0];
	for (int i = 0; i < size; i++)													//поиск максимального значения среди минимумов
	{
		MAX_of_min = (arr_min[i] > MAX_of_min) ? arr_min[i] : MAX_of_min;
	}
	return MAX_of_min;
}


void main()
{
	int rows, cols;																	//создаем динамический двумерный массив
	cout << "Enter a number of rows: " << endl;
	cin >> rows;
	cout << "Enter a number of columns: " << endl;
	cin >> cols;
	int** p = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		p[i] = new int[cols];
	}

	fill_matrix(p, rows, cols);														//заполняем матрицу
	print_matrix(p, rows, cols);													//выводим на экран матрицу

	int* arr_max = new int[rows];													//создаем два динамических одномерных массива
	int* arr_min = new int[cols];

	if (find_max(p, arr_max, rows, cols) == find_min(p, arr_min, rows, cols))		//проверяем есть ли седловой элемент в матрице
		cout <<"Saddle element is: " << find_max(p, arr_min, rows, cols) << endl;
	else cout << "Saddle elements not found" << endl;

	delete[]arr_max;																//очищаем память
	delete[]arr_min;

	for (int i = 0; i < rows; i++)
	{
		delete[] p[i];
	}
	delete[] p;

	system("pause");
}