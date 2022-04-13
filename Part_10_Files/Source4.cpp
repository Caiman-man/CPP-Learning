#include <iostream>
using namespace std;

/*4. ������������ ������ 2 ����� �����, 
	 ��������� �������� ������ �� ������ �� ������� ����� �� ������, 
	 ������� �������� �������.*/

	 //����� - �����
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
		fputs("123abc\n-123\n-def456\n456\nghi789\n-789", f1);
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
			int cnt = 0;												//�������
			char buf[256];												//�����
			strcpy(buf, "");
			fgets(buf, 256, f1);
			if (buf[0] == '-' || (buf[0] >= '0' && buf[0] <= '9'))		//���� ������ ������ - ����� ��� �����
			{
				cnt++;													//����� ������ �������
				for (int i = 1; buf[i] != 0; i++)						//� ��������� � ����� ��� ��������� �������
				{
					if (buf[i] >= '0' && buf[i] <= '9')
						cnt++;
				}
			}
			if (buf[strlen(buf) - 1] == 10)
				buf[strlen(buf) - 1] = 0;
			if (strlen(buf) == cnt)										//���� ����� ������(��� ������� "new line") ����� ��������
			{
				fputs(buf, f2);											//�� �������� ������ �� 2� ����
				fputs("\n", f2);
			}
		}
		fclose(f1);
		fclose(f2);
	}
	else
		cout << "Error opening file!" << endl;
}