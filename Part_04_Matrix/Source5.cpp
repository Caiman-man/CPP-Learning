#include <iostream>
using namespace std;
void main()
{
	/*5. Пользователь вводит массив 3Х4. 
		 Программа меняет местами первую и последнюю строки, 
		 после чего выводит массив на экран*/

	int a[3][4];
	int temp;

	//ввод массива
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

	//вывод массива до
	cout << "Before:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//расчет
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			temp = a[0][k];
			a[0][k] = a[2][k];
			a[2][k] = temp;
		}
	}
	cout << endl;

	//вывод массива после
	cout << "After:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}
