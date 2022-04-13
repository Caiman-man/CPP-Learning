#include <iostream>
using namespace std;
void main()
{
	//3. Пользователь вводит 5 чисел, программа находит максимальное из них

	// числа - целые

	int a, max;
	cin >> a;
	max = a;							//Max сразу равен первой введенной переменной
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > max) max = a;
	}
	cout << "Max is: " << max << endl;
	system("pause");
	
}