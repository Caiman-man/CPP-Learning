#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*2. Пользователь вводит строку. 
		 Программа подсчитывает количество не цифровых символов.*/

	char s[100];
	cin.getline(s, 100);
	int cnt = 0;
	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] < '0' || s[i] > '9') cnt++;
	}
	cout << "Number of symbols: " << cnt << endl;

	system("pause");

}