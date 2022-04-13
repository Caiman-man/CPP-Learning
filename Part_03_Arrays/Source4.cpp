#include <iostream>
using namespace std;
void main()
{
	/*4. Пользователь вводит 2 массива из 4 чисел, программа выясняет,
		 равны ли суммы элементов этих массивов(YES / NO)*/

	int a[4], b[4], sum1 = 0, sum2 = 0;
	
	//вводим первый массив и считаем сумму элементов
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}
	cout << endl;

	//вводим второй массив и считаем сумму элементов
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
		sum2 += b[i];
	}
	cout << endl;

	//проверяем равность сумм
	if (sum1 == sum2) cout << "YES" << endl;
	else cout << "NO" << endl;

	system("pause");





}