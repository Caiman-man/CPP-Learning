#include <iostream>
using namespace std;
void main()
{
	/* «адача 5: ѕользователь вводит 5 чисел, 
	программа подсчитывает количество положительных, 
	отрицательных чисел и нулей
	и выводит на экран*/

	//задаем п€ть переменных, и вводим входные данные
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

	//создаем переменную-счетчик дл€ положительных чисел
	int pos = 0;

	//создаем переменную-счетчик дл€ отрицательных чисел
	int neg = 0;

	//создаем переменную-счетчик дл€ нулей
	int zer = 0;

	//провер€ем переменную а
	if (a > 0)
	{
		pos++;
	}
	else
	{
		if (a < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//провер€ем переменную b
	if (b > 0)
	{
		pos++;
	}
	else
	{
		if (b < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//провер€ем переменную c
	if (c > 0)
	{
		pos++;
	}
	else
	{
		if (c < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//провер€ем переменную d
	if (d > 0)
	{
		pos++;
	}
	else
	{
		if (d < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//провер€ем переменную e
	if (e > 0)
	{
		pos++;
	}
	else
	{
		if (e < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//вывод результата
	cout << "Positives: " << pos << endl;
	cout << "Negatives: " << neg << endl;
	cout << "Zeros: " << zer << endl;

	system("pause");
}