#include <iostream>
using namespace std;

/*2. Ўаблонна€ функци€ принимает одномерный массив и размер 
	 и выводит на экран 2 самых больших числа в массиве (тернарные операторы)*/

	//массив используетс€ динамический
	//программа выводит именно два самых больших числа, не элемента

template <typename T>
void fill_keyboard(T a[], int size)											//заполн€ем массив с клавиатуры
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








1

if (length == 1) {
         max1 = max2 = *arr;
     } else if (length == 2) {
         max1 = *arr;
         max2 = *(arr + 1);
     } else {
         max1 = *arr;
         max2 = *(arr + 1);
         for (int i = 1; i < length; ++i) {
             if (arr[i] > max1) {
                 max2 = max1;
                 max1 = (arr + i);
             } else if ((arr + i) > max2) {
                 max2 = *(arr + i);
             }
         }
     }
	 
	 
	 
	 
	 
	 
	 
	 
	 2
	 
	 template<typename T>
void printTwoMaxNum(const T *arr, const unsigned &length) {
    T max1, max2;

    /**
     *Вариант с тернарным оператором
     * Читается не очень
     * */

    bool isElse = false;
    length == 1 ? max1 = max2 = *arr : length == 2 ? max1 = *arr, max2 = *(arr + 1) : isElse = true;
    if (isElse) {
        max1 = *arr;
        max2 = *(arr + 1);
        for (int i = 1; i < length; ++i)
            *(arr + i) > max1 ? max2 = max1, max1 = *(arr + i) : *(arr + i) > max2 ? max2 = *(arr + i) : max2;
    }
std::cout << "Max1: " << max1 << std::endl;
    std::cout << "Max2: " << max2 << std::endl;

}