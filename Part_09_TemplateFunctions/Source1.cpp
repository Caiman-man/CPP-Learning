#include <iostream>
using namespace std;

/*1. Шаблонная функция принимает 2 одномерных массива и их размеры
	 и возвращает максимум обоих массивов (тернарные операторы)*/

	 //массивы используются динамические

template <typename T>
void fill_keyboard(T a[], int size)											//заполняем массив с клавиатуры
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
}

template <typename T>
void print(T a[], int size)													//печать массива
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

template <typename T>
T max(T a[], T b[], int size_a, int size_b)									//нахождение максимума
{
	T MAX;
	T max_a = a[0];
	T max_b = b[0];

	for (int i = 0; i < size_a; i++)
	{
		max_a = (a[i] > max_a) ? a[i] : max_a;
	}

	for (int i = 0; i < size_b; i++)
	{
		max_b = (b[i] > max_b) ? b[i] : max_b;
	}

	MAX = (max_a > max_b) ? max_a : max_b;
	return MAX;
}

void main()
{
	int size_1 = 0;															//создаем, вводим и выводим массив_1
	cout << "Enter a size of first array: " << endl;
	cin >> size_1;
	int* arr_1 = new int[size_1];
	cout << "Enter a first array: " << endl;
	fill_keyboard(arr_1, size_1);
	cout << "First array: ";
	print(arr_1, size_1);
	cout << "\n";

	int size_2 = 0;															//создаем, вводим и выводим массив_2
	cout << "Enter a size of second array: " << endl;
	cin >> size_2;
	int* arr_2 = new int[size_2];
	cout << "Enter a second array: " << endl;
	fill_keyboard(arr_2, size_2);
	cout << "Second array: ";
	print(arr_2, size_2);
	cout << "\n";

	cout << "Maximum is: " << max(arr_1, arr_2, size_1, size_2) << endl;	//находим максимум

	delete[]arr_1;
	delete[]arr_2;
	system("pause");
}