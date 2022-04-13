#include <iostream>
using namespace std;
void main()
{
	/*4. Пользователь вводит 2 массива 2Х2. 
		 Если произведение всех чисел 1 массива равно сумме всех чисел 2 массива, 
		 то программа пишет "YES", иначе "NO"*/

	int a[2][2];
	int b[2][2];
	int sum = 0;
	int mult = 1;

	//ввод массива a и расчет произведения
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cin >> a[i][k];
			mult *= a[i][k];
		}
	}
	cout << endl;

	//ввод массива b и расчет суммы
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cin >> b[i][k];
			sum += b[i][k];
		}
	}
	cout << endl;

	//вывод массива a
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//вывод массива b
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << "b[" << i << "][" << k << "]= " << b[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	if (mult == sum) cout << "YES" << endl;
	else cout << "NO" << endl;


	system("pause");
}
