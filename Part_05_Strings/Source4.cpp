#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*4. Пользователь вводит 2 строки, 
		 программа определяет равно ли у них количество гласных букв*/

	char s1[100];
	cin.getline(s1, 100);
	char s2[100];
	cin.getline(s2, 100);
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; s1[i] != 0; i++)
	{
		if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'y')
		{
			cnt1++;
		}
	}
	for (int i = 0; s2[i] != 0; i++)
	{
		if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' || s2[i] == 'y')
		{
			cnt2++;
		}
	}
	if (cnt1 == cnt2) cout << "YES" << endl;
	else cout << "NO" << endl;

	system("pause");

}