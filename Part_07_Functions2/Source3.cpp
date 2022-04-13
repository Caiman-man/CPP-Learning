#include <iostream>
using namespace std;

/*3. Функция принимает строку и меняет все гласные буквы на символ '!'.*/

	 //пользователь самостоятельно вводит строку

void change_vowels(char s[])
{
	for (size_t i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'y' || s[i] == 'u' || s[i] == 'i' || s[i] == 'o'|| 
			s[i] == 'A' || s[i] == 'E' || s[i] == 'Y' || s[i] == 'U' || s[i] == 'I' || s[i] == 'O')
		{
			s[i] = '!';
		}
	}
	cout << "\n";
}

void main()
{
	cout << "Enter a string: " << endl;
	char str[100];
	cin.getline(str, 100);

	change_vowels(str);
	cout << "After changing: \n" << str << endl;

	system("pause");
}