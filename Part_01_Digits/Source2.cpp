#include <iostream>
using namespace std;
void main()
{
	/* Задача 2: Пользователь вводит 5 чисел, 
	программа подсчитывает сумму положительных чисел 
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

	//создаем переменную для суммы
	int sum = 0;

	//проверяем положительность чисел, и ссумируем
	if (a > 0)
	{
		sum = sum + a;
	}
	if (b > 0)
	{
		sum = sum + b;
	}
	if (c > 0)
	{
		sum = sum + c;
	}
	if (d > 0)
	{
		sum = sum + d;
	}
	if (e > 0)
	{
		sum = sum + e;
	}

	//вывод результата
	cout << "Sum: " << sum << endl;

	system("pause");
}