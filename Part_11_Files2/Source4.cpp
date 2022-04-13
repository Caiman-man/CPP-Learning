#include <iostream>
using namespace std;

/*4. ������������ ������ 2 ����� �����. 
	 ��������� ���������� �� ���������� � ����������, ��������� �� ���.*/

	 //� �������� �������� ������ - 2 ����������� � ������� "picture1" � "picture2"
	 //����� ������ ������ � ����������� .jpg

void main()
{
	FILE* f1, * f2;
	char name1[128];
	printf("Enter the first file name: \n");
	scanf("%s", &name1);

	char name2[128];
	printf("Enter the second file name: \n");
	scanf("%s", &name2);
	cout << "\n";

	f1 = fopen(name1, "rb");
	f2 = fopen(name2, "rb");

	if (f1 != nullptr && f2 != nullptr)
	{
		fseek(f1, 0, SEEK_END);
		size_t size1 = ftell(f1);
		fseek(f1, 0, SEEK_SET);

		fseek(f2, 0, SEEK_END);
		size_t size2 = ftell(f2);
		fseek(f2, 0, SEEK_SET);

		//���������� ������� ������
		if (size1 != size2)
			cout << "NO" << endl;
		else
		{
			char* buffer1 = new char[size1];
			char* buffer2 = new char[size2];

			if (buffer1 != nullptr && buffer2 != nullptr)
			{
				fread(buffer1, sizeof(char), size1, f1);
				fread(buffer2, sizeof(char), size2, f2);

				//���������� ��� ������ �����������
				int cnt = 0;
				for (int i = 0; i < size1; i++)
				{
					if (buffer1[i] != buffer2[i])
					{
						cout << "NO" << endl;
						break;
					}
					else
						cnt++;
				}
				if (cnt != size1)
					cout << "NO" << endl;
				else
					cout << "YES" << endl;

				delete[] buffer1;
				delete[] buffer2;
			}
			fclose(f1);
			fclose(f2);
		}
	}
	else
		cout << "Error opening files!" << endl;

}	