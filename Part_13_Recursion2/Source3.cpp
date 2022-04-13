#include <iostream>
#include "conio.h"
using namespace std;

/*3. Рекурсивная функция принимает строку и букву 
	 и подсчитывает сколько раз буква встречается в строке.*/

int Count(char* s, char letter, int n = 0)
{
	int res = 0;
	if (s[n])
		res = Count(s, letter, n + 1);

	return (s[n] == letter) ? res + 1 : res;
}

void main()
{
	cout << "Enter a string:" << endl;
	char str[128];
	cin.getline(str, 128);
	cout << "Enter a letter:" << endl;
	char ch = _getch();
	cout << ch << endl;

	cout << "Result is: " << Count(str, ch) << endl;

	system("pause");
}