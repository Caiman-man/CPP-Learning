#include <iostream>
using namespace std;

/*3. ������������ ������ 2 ����� �����, 
	 ��������� �������� ������ �� ������ �� ������� ����� �� ������, 
	 ������� �������� ������� �����*/

	 //��� ������ ������ �������������� (� ����������� .txt)

void main()
{
	FILE* f1, * f2;
	char s1[20], s2[20];
	printf("Enter the first file name: \n");
	scanf("%s", &s1);
	printf("Enter the second file name: \n");
	scanf("%s", &s2);

	//� ������ ���� �������� ������������� �����.
	f1 = fopen(s1, "w");
	if (f1 != nullptr)
	{
		fputs("One minute\n2 hrs\nThree days\n4 wks\nFive months", f1);
		fclose(f1);
	}
	else
		cout << "Error opening file!" << endl;

	//�����������
	f1 = fopen(s1, "r");
	f2 = fopen(s2, "w");
	if (f2 != nullptr)
	{
		while (!feof(f1))
		{
			char buf[256];
			strcpy(buf, "");
			fgets(buf, 256, f1);
			for (int i = 0; buf[i] != 0; i++)
			{
				if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u' || buf[i] == 'y'||
					buf[i] == 'A' || buf[i] == 'E' || buf[i] == 'I' || buf[i] == 'O' || buf[i] == 'U' || buf[i] == 'Y')
				{
					fputs(buf, f2);
					break;
				}
			}
		}
		fclose(f1);
		fclose(f2);
	}
	else
		cout << "Error opening file!" << endl;
}