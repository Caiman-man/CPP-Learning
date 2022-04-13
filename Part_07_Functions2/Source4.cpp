#include <iostream>
using namespace std;

/*4. Программа копирует из первого массива все нечётные числа и нули во второй массив
	 и выводит его на экран (динамические массивы)*/

void fill_keyboard(int a[], int size)					//заполняем массив с клавиатуры
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	cout << "\n";
}

void print(int a[], int size)							//печать массива
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

int search_size_2(int a[], int size)					//нахождение размера_2
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 1 || a[i] % 2 == -1 || a[i] == 0) result++;
	}
	return result;
}

void copy(int a[], int b[], int size)					//копирование
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 1 || a[i] % 2 == -1 || a[i] == 0)
		{
			b[k] = a[i];
			k++;
		}
	}
}

void main()
{
	int size_1 = 0;										//1 задаем переменную для размера массива_1
	cout << "Enter a size of array: " << endl;
	cin >> size_1;										//2 вводим размер массива_1
	int* arr_1 = new int[size_1];						//3 создаем массив_1

	cout << "Enter an array: " << endl;
	fill_keyboard(arr_1, size_1);						//4 заполняем самостоятельно массив_1
	print(arr_1, size_1);								//5 выводим массив_1

	int size_2 = search_size_2(arr_1, size_1);			//6 находим размер для массива_2
	int* arr_2 = new int[size_2];						//7 создаем массив_2

	copy(arr_1, arr_2, size_1);							//8 копирование из 1 в 2
	print(arr_2, size_2);								//9 выводим массив_2

	delete[]arr_1;
	delete[]arr_2;

	system("pause");
}

