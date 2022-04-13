#include <iostream>
using namespace std;
void main()
{
	/*2. Пользователь вводит массив 3Х3. 
		 Программа находит сумму элементов каждого столбца*/

	int a[3][3];
	int sum = 0;

	//ввод
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

	//вывод массива
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//считаем сумму и выводим
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int k = 0; k < 3; k++)
		{
			sum += a[k][i];			
		}
		cout << "   sum  = " << sum;
	}
	cout << endl;
	
	system("pause");
}
