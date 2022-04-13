#include <iostream>
using namespace std;
void main()
{
	/* Задача 4: Пользователь вводит 3 числа, 
	программа находит максимальное число 
	и выводит на экран*/

	//задаем три переменные, и вводим входные данные
	int a, b, c;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;

	//Создаем переменную для максимума
	int max;

	//проверяем какая переменная больше, используя логическое И
	if (a > b && a > c)
	{
		max = a;
	}
	if (b > a && b > c)
	{
		max = b;
	}
	if (c > a && c > b)
	{
		max = c;
	}

	//вывод результата
	cout << "Max: " << max << endl;

	system("pause");
}