#include <iostream>
using namespace std;

/*1. Пользователь вводит строки до тех пор, пока не введёт слово "exit".
	 Программа сохраняет все введенные строки в файл text.txt, слово "exit" НЕ сохраняется.*/

void main()
{
	FILE* f = fopen("text.txt", "w");
	if (f != nullptr)
	{
		char enter[14] = "Enter string:";
		printf("%s\n", enter);
		while (true)
		{
			char str[128];
			strcpy(str, "");
			scanf("%s", &str);
			if (strcmp(str, "exit") == 0) 
				break;
			fputs(str, f);
			fputs("\n", f);
		}
		fclose(f);
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}