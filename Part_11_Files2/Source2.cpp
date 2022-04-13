#include <iostream>
using namespace std;

/*2. Пользователь вводит имя файла. 
	 Программа разбивает его на 2 равные части и сохраняет в 2 результирующих файла.*/

	 //в качестве примера - текстовый файл с именем "text"
	 //имя файла вводим c расширением .txt
	 //результат сохраняем тоже в текстовые файлы

void main()
{
	FILE* source, * dest1, * dest2;
	char name[128];
	printf("Enter the file name: \n");
	scanf("%s", &name);

	source = fopen(name, "rb");
	if (source != nullptr)
	{
		fseek(source, 0, SEEK_END);
		size_t Size = ftell(source);
		fseek(source, 0, SEEK_SET);

		int size1 = Size / 2;
		int size2 = Size - (Size / 2);

		//создаем два буфера
		char* buffer1 = new char[size1];
		char* buffer2 = new char[size2];

		if (buffer1 != nullptr && buffer2 != nullptr)
		{
			fread(buffer1, sizeof(char), size1, source);
			fread(buffer2, sizeof(char), size2, source);

			//записываем данные из кажого буфера в файлы
			dest1 = fopen("part1.txt", "wb");
			if (dest1 != nullptr)
			{ 
				fwrite(buffer1, sizeof(char), size1, dest1);
				fclose(dest1);
			}

			dest2 = fopen("part2.txt", "wb");
			if (dest2 != nullptr)
			{
				fwrite(buffer2, sizeof(char), size2, dest2);
				fclose(dest2);
			}

			delete[] buffer1;
			delete[] buffer2;
		}
		fclose(source);
	}
	else
		cout << "Error opening file!" << endl;
}