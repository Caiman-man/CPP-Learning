#include <iostream>
using namespace std;

/*5. Пользователь вводит 5 чисел, 
	 Рекурсивная функция возвращает 1, если все числа являются простыми, а иначе 0*/

/*в функцию проверки на простоту передаю два параметра "x" и "i". Второй изначально равен 2. 
  Число не должно быть меньше 2 и не должно делиться на "i" без остатка.*/

bool simple(int x, int i)
{
	if (x < 2)
		return false;
	else if (x == i)
		return true;
	else if (x % i == 0)
		return false;
	else
		return simple(x, i + 1);
}

bool check(int n)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1);
	}
	if (res == true && simple(a, 2) == true)
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: " << check(1) << endl;
}