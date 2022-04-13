#include <iostream>
using namespace std;
void main()
{
	/* Задача 3: Пользователь вводит 5 чисел, 
	программа подсчитывает произведение отрицательных чисел 
	и выводит на экран*/

	//задаем пять переменных, и вводим входные данные
	int a, b, c, d, e;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;
	cout << "Enter a fourth number: " << endl;
	cin >> d;
	cout << "Enter a fifth number: " << endl;
	cin >> e;

	//создаем переменную-мультипликатор
	int mult = 1;

	//проверяем отрицательность чисел, и умножаем
	if (a < 0)
	{
		mult = mult * a;
	}
	if (b < 0)
	{
		mult = mult * b;
	}
	if (c < 0)
	{
		mult = mult * c;
	}
	if (d < 0)
	{
		mult = mult * d;
	}
	if (e < 0)
	{
		mult = mult * e;
	}
	else
	{
		mult = 0;
	}

	//вывод результата
	cout << "Multiplication: " << mult << endl;

	system("pause");
}