#include <iostream>
using namespace std;

/*4. Пользователь вводит 2 имени файла, 
	 программа копирует только те строки из первого файла во второй, 
	 которые являются числами.*/

	 //числа - целые
	 //имя файлов вводим самостоятельно (с расширением .txt)

void main()
{
	FILE* f1, * f2;
	char s1[20], s2[20];
	printf("Enter the first file name: \n");
	scanf("%s", &s1);
	printf("Enter the second file name: \n");
	scanf("%s", &s2);

	//в первый файл вводится фиксированный текст.
	f1 = fopen(s1, "w");
	if (f1 != nullptr)
	{
		fputs("123abc\n-123\n-def456\n456\nghi789\n-789", f1);
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
			int cnt = 0;												//счетчик
			char buf[256];												//буфер
			strcpy(buf, "");
			fgets(buf, 256, f1);
			if (buf[0] == '-' || (buf[0] >= '0' && buf[0] <= '9'))		//если первый индекс - цифра или минус
			{
				cnt++;													//сразу тикает счетчик
				for (int i = 1; buf[i] != 0; i++)						//и проверяем в цикле все остальные индексы
				{
					if (buf[i] >= '0' && buf[i] <= '9')
						cnt++;
				}
			}
			if (buf[strlen(buf) - 1] == 10)
				buf[strlen(buf) - 1] = 0;
			if (strlen(buf) == cnt)										//если длина строки(без символа "new line") равна счетчику
			{
				fputs(buf, f2);											//то копируем строку во 2й файл
				fputs("\n", f2);
			}
		}
		fclose(f1);
		fclose(f2);
	}
	else
		cout << "Error opening file!" << endl;
}