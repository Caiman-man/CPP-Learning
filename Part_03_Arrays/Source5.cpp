#include <iostream>
using namespace std;
void main()
{
	/*5. Пользователь вводит 2 массива из 4 чисел, 
		 программа вычитает из каждого элемента первого массива элемент второго массива 
		 и результат записывает в 3 массив, все массивы выводятся на экран.*/

	int a[4], b[4], c[4];
	
	//вводим первый массив
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	cout << endl;

	//вводим второй массив
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
	}
	cout << endl;

	//считаем разницу и записываем в трейтий массив
	for (int i = 0; i < 4; i++)
	{
		c[i] = a[i] - b[i];
	}
	cout << endl;

	//выводим три массива
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << c[i] << "  ";
	}
	cout << endl;

	system("pause");





}