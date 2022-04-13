#include <iostream>
using namespace std;
void main()
{
	/*3. ѕользователь вводит массив из 5 чисел, 
		 программа увеличивает все отрицательные числа в 2 раза, 
		 а все положительные числа уменьшает на 2 и выводит массив на экран*/

	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		if (a[i] < 0) a[i] *= 2;
		if (a[i] > 0) a[i] -= 2;
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	system("pause");





}