#include <iostream>
using namespace std;

//3. Функция принимает строку и подсчитывает количество гласных букв в ней

//пользователь самостоятельно вводит строку

int vowels(const char str[])
{
	int cnt = 0;
	for (size_t i = 0; str[i] != 0; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
		{
			cnt++;
		}
	}
	return cnt;
}

void main()
{
	cout << "Enter a string:" << endl;
	char str[100];
	cin.getline(str, 100);
	cout << "Number of vowels: " << vowels(str) << endl;

	system("pause");
}

