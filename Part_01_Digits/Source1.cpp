#include <iostream>
using namespace std;
void main()
{
	/* Задача 1: Пользователь вводит 4 числа, 
	программа подсчитывает количество троек среди них
	и выводит на экран*/

	//задаем три переменные, и вводим входные данные
	int a, b, c;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;

	//создаем переменную-счетчик
	int count = 0;

	//проверяем наличие троек, и включаем счетчик
	if (a == 3)
	{
		count++;
	}
	if (b == 3)
	{
		count++;
	}
	if (c == 3)
	{
		count++;
	}

	//вывод результата
	cout << "Number of triples: " << count << endl;

	system("pause");
}