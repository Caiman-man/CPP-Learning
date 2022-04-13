#include <iostream>
using namespace std;
void main()
{
	/*2. Пользователь вводит 5 чисел, программа подсчитывает сумму чётных 
	чисел и выводит на экран*/

	int a = 0, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a % 2 == 0) sum += a;
	}
	cout << "Sum is: " << sum << endl;
}