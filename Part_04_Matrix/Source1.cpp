#include <iostream>
using namespace std;
void main()
{
	/*1. Пользователь вводит массив 3Х3. Программа находит максимальное 
		 отрицательное число и минимальное положительное, и выводит их на экран*/

	int a[3][3];
	int max = 0, min = 0;

	//ввод
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

	//вывод массива
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//присвоение стартовых значений max и min
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (a[i][k] < 0) max = a[i][k];		//перебираю все значения массива, если хоть одно - меньше нуля, то беру его как опорное значение
			if (a[i][k] > 0) min = a[i][k];		//перебираю все значения массива, если хоть одно - больше нуля, то беру его как опорное значение
		}
	}

	//проверка условия в цикле
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (a[i][k] > max && a[i][k] < 0) max = a[i][k];
			if (a[i][k] < min && a[i][k] > 0) min = a[i][k];
		}
	}
	
	//вывод (если положительных/ отрицательных нет - то выдает ошибку)
	if (max != 0) cout << "Max of negatives = " << max << endl;
	else cout << "Negatives not found" << endl;
	if (min != 0) cout << "Min of positives = " << min << endl;
	else cout << "Positives not found" << endl;


	system("pause");
}
