#include <iostream>
using namespace std;

/*1. ������������ ������ ��� �����. 
	 ��������� ������� �� ���� ��� ������� ����� � ��������� � ������ ����*/

	 //��� ����� ������ ��� ����������

void main()
{
	FILE* f1, * f2;
	char s1[128];
	printf("Enter the file name: \n");
	scanf("%s", &s1);
	strcat(s1, ".txt");

	//� ������ ���� �������� ������������� �����.
	f1 = fopen(s1, "wb");
	if (f1 != nullptr)
	{
		char text[15] = "Hello world!!!";
		fwrite(text, sizeof(char), 15, f1);
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;

	//�����������
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

			//������� ����� ��� ������� ������
			int buf2_size = 0;
			for (int i = 0; i < (fileSize - 1); i++)
			{
				if (buf[i] != 'a' && buf[i] != 'e' && buf[i] != 'i' && buf[i] != 'o' && buf[i] != 'u' && buf[i] != 'y' &&
					buf[i] != 'A' && buf[i] != 'E' && buf[i] != 'I' && buf[i] != 'O' && buf[i] != 'U' && buf[i] != 'Y')
				{
					buf2_size++;
				}
			}

			//������� ������ ����� ��� ������ � ���� �����, ����� ������� ����
			char* buf2 = new char[buf2_size];
			int k = 0;
			for (int i = 0; i < (fileSize - 1); i++)
			{
				if (buf[i] != 'a' && buf[i] != 'e' && buf[i] != 'i' && buf[i] != 'o' && buf[i] != 'u' && buf[i] != 'y' &&
					buf[i] != 'A' && buf[i] != 'E' && buf[i] != 'I' && buf[i] != 'O' && buf[i] != 'U' && buf[i] != 'Y')
				{
					buf2[k] = buf[i];
					k++;
				}
			}

			//���������� � ���� �� ������� ������
			f2 = fopen("result.txt", "wb");
			if (f2 != nullptr)
			{
				fwrite(buf2, sizeof(char), buf2_size, f2);
				fclose(f2);
			}
			delete[] buf;
			delete[] buf2;
		}
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;
}