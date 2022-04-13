#include <iostream>
using namespace std;
void main()
{
	/*3. Пользователь вводит массив 3Х4. 
		 Программа меняет все 3 на 5, а все 5 на 3 и выводит массив на экран*/

	int a[3][4];
	int sum = 0;

	//ввод и проверка условия
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cin >> a[i][k];
			if (a[i][k] == 3) a[i][k] = 5;
			else
			{
				if (a[i][k] == 5) a[i][k] = 3;
			}
		}
	}
	cout << endl;

	//вывод массива
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
