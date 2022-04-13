#include <iostream>
using namespace std;
void main()
{
	/*1. Пользователь вводит числа, пока их сумма не будет больше 20
		 Программа вычисляет произведение положительных чисел.*/

	int a, sum = 0, mult = 1;
	while (sum <= 20)
	{
		cin >> a;
		sum += a;
		if (a > 0) mult *= a;
	}
	cout << "Sum is:\t\t" << sum << endl;
	cout << "Multiply is:\t" << mult << endl;

	system("pause");





}