#include <iostream>
using namespace std;

/*2. Шаблонная функция принимает одномерный массив и размер 
	 и выводит на экран 2 самых больших числа в массиве (тернарные операторы)*/

	//массив используется динамический
	//программа выводит именно два самых больших числа, не элемента

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
void find_max(T a[], int size)												//нахождение максимумов
{
	T max_1 = a[0];
	T max_2 = a[0];

	for (int i = 0; i < size; i++)
	{
		max_1 = (a[i] > max_1) ? a[i] : max_1;

	}
	for (int i = 0; i < size; i++)
	{
		max_2 = (a[i] > max_2 && a[i] < max_1) ? a[i] : max_2;
	}

	cout << "Max 1 = " << max_1 << "\nMax 2 = " << max_2 << endl;
}

void main()
{
	int size = 0;															//создаем, вводим и выводим массив
	cout << "Enter a size of array: " << endl;
	cin >> size;
	int* arr = new int[size];
	cout << "Enter an array: " << endl;
	fill_keyboard(arr, size);
	cout << "Array is: ";
	print(arr, size);
	cout << "\n";

	find_max(arr, size);													//выводим максимумы

	delete[]arr;
	system("pause");
}