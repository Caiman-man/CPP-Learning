#include <iostream>
using namespace std;

/*2. Пользователь вводит 2 имени файла, 
	 программа копирует все строки из первого файла во второй.*/

	 //имя файлов вводим самостоятельно (с расширением .txt)

void main()
{
	FILE *f1, *f2;
	char s1[20], s2[20];
	printf("Enter the first file name: \n");
	scanf("%s", &s1);
	printf("Enter the second file name: \n");
	scanf("%s", &s2);

	//в первый файл вводится фиксированный текст.
	f1 = fopen(s1, "w");
	if (f1 != nullptr)
	{
		fputs("One minute\nTwo hours\nThree days\nFour weeks\nFive months", f1);
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;

	//копирование
	f1 = fopen(s1, "r");
	f2 = fopen(s2, "w");
	if (f2 != nullptr)
	{
		while (!feof(f1))
		{
			char buffer[256];
			strcpy(buffer, "");
			fgets(buffer, 256, f1);
			fputs(buffer, f2);
		}
		fclose(f1);
		fclose(f2);
	}
	else 
		cout << "Error opening file!" << endl;	
}