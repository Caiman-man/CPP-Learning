#include <iostream>
#include "conio.h"
using namespace std;

//4. –екурсивна€ функци€ принимает 2 строки и вы€сн€ет равны ли они.

int Compare(char* s1, char* s2, int n = 0)
{
	int res = 1;
	if (s1[n])
		res = Compare(s1, s2, n + 1);

	if (s1[n] == s2[n])
		return 1 * res;
	else
		return 0;
}

void main()
{
	cout << "Enter the first string:" << endl;
	char str1[128];
	cin.getline(str1, 128);
	cout << "Enter the second string:" << endl;
	char str2[128];
	cin.getline(str2, 128);

	if (strlen(str1) != strlen(str2))					//это условие специально не вносил в рекурсивную функцию
		cout << "Result is: " << 0 << endl;
	else
		cout << "Result is: " << Compare(str1,str2) << endl;

	system("pause");
}