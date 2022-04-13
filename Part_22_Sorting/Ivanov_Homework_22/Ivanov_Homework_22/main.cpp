#include <iostream>
#include <time.h>
using namespace std;

/*1. Написать программу, которая сравнивает эффективность алгоритмов сортировки
	 (посчитать количество сравнений и количество перестановок).
	 Проанализировать следующие алгоритмы: пузырёк, вставки, выбор, быстрая, а также один алгоритм на выбор.*/

//обьявление массива
int ArraySize;

//Вывод массива
void PrintArray(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//Сортировка Пузырьком
void BubbleSort(int* array, int size, int& compare_cnt, int& transp_cnt)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = size - 1; j >= i; j--)
		{
			//считаем кол-во сравнений
			compare_cnt++;

			if (array[j - 1] > array[j])
			{
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;

				//считаем кол-во перестановок
				transp_cnt++;
			}
		}
	}
}


//Сортировка Выбором
void SelectionSort(int* arr, long size, int& compare_cnt, int& transp_cnt)
{
	long i, j, k;
	int x;

	for (i = 0; i < size; i++)
	{
		k = i;
		x = arr[i];

		for (j = i + 1; j < size; j++)
		{
			//считаем кол-во сравнений
			compare_cnt++;

			if (arr[j] < x)
			{
				k = j;
				x = arr[j];
			}
		}
		arr[k] = arr[i];
		arr[i] = x;

		//считаем кол-во перестановок
		transp_cnt++;
	}
}


//Сортировка Вставками
void InsertionSort(int* array, int size, int& compare_cnt, int& transp_cnt, int& displace_cnt)
{
	int i, j, k, temp;

	for (i = 1; i < size; i++)
	{
		temp = array[i];

		for (j = 0; j < i; j++)
		{
			compare_cnt++;								//считаем кол-во сравнений
			if (array[j] > temp) break;
		}

		compare_cnt++;									//считаем кол-во сравнений
		if (j == i) continue;

		for (k = i; k > j; k--)
		{
			displace_cnt++;								//считаем кол-во смещений
			array[k] = array[k - 1];
		}

		transp_cnt++;									//считаем кол-во перестановок
		array[j] = temp;
	}
}


//Быстрая Сортировка
void QSort(int* array, int start, int end, int& compare_cnt, int& transp_cnt)
{
	if (start >= end) return;
	int i = start, j = end;

	int baseElementIndex = start + (end - start) / 2;

	while (i < j)
	{
		int value = array[baseElementIndex];

		while (i < baseElementIndex && (array[i] <= value))
		{
			i++;
			//считаем кол-во сравнений
			compare_cnt++;
		}

		while (j > baseElementIndex && (array[j] >= value))
		{
			j--;
			//считаем кол-во сравнений
			compare_cnt++;
		}

		if (i < j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			//считаем кол-во перестановок
			transp_cnt++;

			if (i == baseElementIndex) baseElementIndex = j;
			else if (j == baseElementIndex) baseElementIndex = i;
		}
	}

	QSort(array, start, baseElementIndex, compare_cnt, transp_cnt);
	QSort(array, baseElementIndex + 1, end, compare_cnt, transp_cnt);
}

void QuickSort(int* arr, int size, int& compare_cnt, int& transp_cnt)
{
	QSort(arr, 0, size - 1, compare_cnt, transp_cnt);
}


//функция для подсчета кол-ва сравнения в сортировке Шелла, а так же для сравнения двух элементов
bool is_greater(int a, int b, int& compare)
{
	compare++;
	if (a > b) return true;
	else return false;
}

//Сортировка Шелла
void ShellSort(int* array, int size, int& compare_cnt, int& transp_cnt)
{
	int step, i, j, tmp;

	// Выбор шага
	for (step = size / 2; step > 0; step /= 2)
		// Перечисление элементов, которые сортируются на определённом шаге
		for (i = step; i < size; i++)
		{
			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
			for (j = i - step; j >= 0 && is_greater(array[j], array[j + step], compare_cnt); j -= step)
			{
				tmp = array[j];
				array[j] = array[j + step];
				array[j + step] = tmp;

				//считаем кол-во перестановок
				transp_cnt++;
			}
		}
}


//функция для выброса исключения
void func(int value)
{
	if (value < 0)
	{
		throw "Size can't be less than zero";
	}
}


void main()
{
	srand(time(0));

	cout << "Enter the size of array: \n";
	do
	{
		cin >> ArraySize;
		cout << "ERROR! Size can't be less than zero! Enter the size of array again:\n";
	} while (ArraySize < 0);

	//Блок try catch
	//try 
	//{
	//	cin >> ArraySize;
	//	func(ArraySize);
	//}
	//catch (const char* exception)
	//{
	//	cout << "ERROR! " << exception << endl;

	//	//при данном варианте, catch ловит сообщение, и выводит его на экран, но затем программа все-равно
	//	//пытается создать массивы с отрицательным значением и просто вылетает
	//	//поэтому пришлось сюда вставить exit(0)
	//	exit(0);
	//}
	//catch (...)
	//{
	//	cout << "Unknown error!!!" << endl;
	//}

	//создаем 5 динамических массивов
	int* arr1 = new int[ArraySize];
	int* arr2 = new int[ArraySize];
	int* arr3 = new int[ArraySize];
	int* arr4 = new int[ArraySize];
	int* arr5 = new int[ArraySize];

	//заполняем 1й массив случайными числами
	for (size_t i = 0; i < ArraySize; i++)
	{
		arr1[i] = rand() % 10;
	}

	//копируем значения из первого массива во все остальные (что бы все массивы были одинаковые)
	for (size_t i = 0; i < ArraySize; i++)
	{
		arr5[i] = arr4[i] = arr3[i] = arr2[i] = arr1[i];
	}

	//вывод массива до его сортировки
	system("cls");
	cout << "Arrays before sorting:\n";
	PrintArray(arr1, ArraySize);
	cout << "-----------------------------------------------------------------\n";

	//обьявляем переменные для хранения в них результатов расчетов (для каждой сортировки отдельно)
	//переменные будем передавать в функции сортировок, и получать результаты расчетов по ссылкам 
	int bubble_cs = 0;
	int bubble_ts = 0;
	int selection_cs = 0;
	int selection_ts = 0;
	int insertion_cs = 0;
	int insertion_ts = 0;
	int insertion_ds = 0;
	int shell_cs = 0;
	int shell_ts = 0;
	int quick_cs = 0;
	int quick_ts = 0;

	//сортировка массивов
	BubbleSort(arr1, ArraySize, bubble_cs, bubble_ts);
	SelectionSort(arr2, ArraySize, selection_cs, selection_ts);
	InsertionSort(arr3, ArraySize, insertion_cs, insertion_ts, insertion_ds);
	ShellSort(arr4, ArraySize, shell_cs, shell_ts);
	QuickSort(arr5, ArraySize, quick_cs, quick_ts);

	//вывод массивов после различных сортировок
	cout << "\nArray after Bubble sorting:\n";
	PrintArray(arr1, ArraySize);
	cout << "\nArray after Selection sorting:\n";
	PrintArray(arr2, ArraySize);
	cout << "\nArray after Insertion sorting:\n";
	PrintArray(arr3, ArraySize);
	cout << "\nArray after Shell sorting:\n";
	PrintArray(arr4, ArraySize);
	cout << "\nArray after Quick sorting:\n";
	PrintArray(arr5, ArraySize);
	
	//вывод результатов в таблице
	cout << "\nResult is: \n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Name/Parameters\t|   Comparsion\t| Transposition\t|  Displacment\t|\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Bubble\t\t|\t" << bubble_cs << "\t|\t" << bubble_ts << "\t|\t" << "-" << "\t|\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Selection\t|\t" << selection_cs << "\t|\t" << selection_ts << "\t|\t" << "-" << "\t|\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Insertion\t|\t" << insertion_cs << "\t|\t" << insertion_ts << "\t|\t" << insertion_ds << "\t|\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Shell\t\t|\t" << shell_cs << "\t|\t" << shell_ts << "\t|\t" << "-" << "\t|\n";
	cout << "-----------------------------------------------------------------\n";
	cout << "Quick\t\t|\t" << quick_cs << "\t|\t" << quick_ts << "\t|\t" << "-" << "\t|\n";
	cout << "-----------------------------------------------------------------\n";
	
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
}