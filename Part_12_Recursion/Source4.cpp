#include <iostream>
using namespace std;

/*4. Пользователь вводит 5 чисел, 
	 рекурсивная функция возвращает 1, если все числа идут в порядке возрастания, а иначе 0*/

	/*в аргументы добавил еще одну переменную, что бы передавать в неё введенное число,
	что бы потом можно было с ним сверяться*/

bool check(int n, int b)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1, a);
	}
	if (res == true && a > b)
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: " << check(1, 0) << endl;
}