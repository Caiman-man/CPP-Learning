#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*1. Пользователь вводит символы, пока не введёт ESC.
		 Программа подсчитывает сумму всех введенных цифер.*/

	char сh = 0;
	int sum = 0;
	while (сh != 27)
	{
		сh = _getch();
		cout << сh << endl;
		if (сh >= '0' &&  сh <= '9')
		{
			sum += (сh - '0');
		}
	}
	cout << "Sum is: " << sum << endl;

	system("pause");

}