#include <iostream>
using namespace std;

//1. Пользователь вводит 5 чисел, рекурсивная функция подсчитывает сумму отрицательных чисел.

int sum_neg(int n)
{
	int a;
	int res = 0;
	cin >> a;
	if (n < 5)
	{
		res = sum_neg(n + 1);
	}
	return (a < 0) ? res + a : res;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	int result = sum_neg(1);
	cout << "Sum of negatives = " << result << endl;
}