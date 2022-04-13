#include <iostream>
using namespace std;

/*3. ѕользователь вводит 5 чисел, 
	 –екурсивна€ функци€ возвращает 1, если все числа положительные, а иначе 0*/

	 /*когда функци€ будет раскручиватьс€ обратно, res точно будет равен true,
	 а вот переменна€ "a" может быть меньше нул€,
	 но если хоть один раз условие не выполнитс€ то res стане равен - false 
	 и уже никогда не будет равен - true*/

bool check(int n)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1);
	}
	if (res == true && a > 0)		
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: "<< check(1)<< endl;
}