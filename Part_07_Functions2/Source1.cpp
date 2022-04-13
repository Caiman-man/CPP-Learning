#include <iostream>
#include <time.h>
using namespace std;

/*1. Пользователь вводит диапазон случайных чисел и их количество.
	 Программа выводит все числа на экран и подсчитывает их сумму, 
	 количество чётных и нечётных чисел.*/

void main()
{
	srand(time(0));

	int a, b, c;
	int random;								//переменная для хранения рандомного числа
	int sum = 0, cnt_even = 0, cnt_odd = 0;

	cout << "Enter a start of range: " << endl;
	cin >> a;
	cout << "Enter an end of range: " << endl;
	cin >> b;
	cout << "Enter an amount of numbers : " << endl;
	cin >> c;
	cout << "\n";

	for (int i = 0; i < c; i++)
	{
		random = rand() % (b - a + 1) + a;
		cout << random << "  ";
		sum += random;
		if (random % 2 != 0) cnt_odd++;
		else cnt_even++;
	}
	cout << "\n\n";

	cout << "Sum is:\t\t\t" << sum << endl;
	cout << "The number of even:\t" << cnt_even << endl;
	cout << "The number of odd:\t" << cnt_odd << endl;

	system("pause");
}










