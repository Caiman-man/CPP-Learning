#include <iostream>
using namespace std;
void main()
{
	/*4. Пользователь вводит 5 чисел, программа находит сумму минимального 
	и максимального чисел из введенных и выводит на экран*/

	// числа - целые

	int a, max, min;
	cin >> a;
	max = a;							//Max сразу равен первой введенной переменной
	min = a;							//Min сразу равен первой введенной переменной
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > max) max = a;
		if (a < min) min = a;
	}
	cout << "Max + Min = " << max+min << endl;
	system("pause");

}