#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*5. Пользователь вводит строку, 
		 программа меняет местами первый и последний символы и выводит строку на экран*/

	char s[100];
	cin.getline(s, 100);
	cout << "Before:\t" << s << endl;

	int len = strlen(s);

	char temp = s[0];
	s[0] = s[len-1];
	s[len-1] = temp;

	cout << "After:\t" << s << endl;

	system("pause");

}