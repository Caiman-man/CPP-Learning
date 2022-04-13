#include <iostream>
using namespace std;

/*5. Функция принимает 2 строки и 
	 возвращает 1, если они равны, 0 - если они не равны (сравнение строк)*/

//пользователь самостоятельно вводит строки

int CompareStr(const char s1[], const char s2[])
{
	int cnt = 0;							
	int len1 = strlen(s1);					//что бы не вызывать strlen слишком часто

	if (len1 != strlen(s2)) return 0;
	else 
	{
		for (size_t i = 0; s1[i] !=0 ; i++)
		{
			if (s1[i] != s2[i])
			{
				return 0;
				break;
			}
			else
			{
				cnt++;
			}
		}
		if (cnt == len1) return 1;
	}
}

int main()
{
	cout << "Enter a first string:" << endl;
	char str1[100];
	cin.getline(str1, 100);

	cout << "Enter a second string:" << endl;
	char str2[100];
	cin.getline(str2, 100);

	cout << "Result is: " << CompareStr(str1, str2) << endl;

	system ("pause");
}

