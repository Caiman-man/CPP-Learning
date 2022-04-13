#include <iostream>
using namespace std;

/*1. Пользователь вводит имя файла.
	 Программа удаляет из него все гласные буквы и сохраняет в другой файл*/

	 //имя файла вводим без расширения

void main()
{
	FILE* f1, * f2;
	char s1[128];
	printf("Enter the file name: \n");
	scanf("%s", &s1);
	strcat(s1, ".txt");

	//в первый файл вводится фиксированный текст.
	f1 = fopen(s1, "wb");
	if (f1 != nullptr)
	{
		char text[12] = "Hello world";
		fwrite(text, sizeof(char), 12, f1);
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;

	//копирование
	f1 = fopen(s1, "rb");
	if (f1 != nullptr)
	{
		fseek(f1, 0, SEEK_END);
		size_t fileSize = ftell(f1);
		fseek(f1, 0, SEEK_SET);
		char* buf = new char[fileSize];
		if (buf != nullptr)
		{
			fread(buf, sizeof(char), fileSize, f1);

			//удаляем элементы массива и сдвигаем буквы
			for (int i = 0; i < (fileSize - 1); i++)
			{
				if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u' || buf[i] == 'y' ||
					buf[i] == 'A' || buf[i] == 'E' || buf[i] == 'I' || buf[i] == 'O' || buf[i] == 'U' || buf[i] == 'Y')
				{
					for (int k = i; buf[k] != 0; k++)
					{
						buf[k] = buf[k + 1];
					}
					i--;
				}
			}

			f2 = fopen("result.txt", "wb");
			if (f2 != nullptr)
			{
				fwrite(buf, sizeof(char), fileSize, f2);
				fclose(f2);
			}
			delete[] buf;
		}
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;
}