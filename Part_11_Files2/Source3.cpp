#include <iostream>
using namespace std;

/*3. ������������ ������ 2 ����� �����. 
	 ��������� ���������� �� � 1 �������������� ����.*/

	 //� �������� �������� ������ - ��������� ����� � ������� "text1" � "text2"
	 //����� ������ ������ � ����������� .txt
	 //�������������� ���� - ���� ���������

void main()
{
	FILE* src1, * src2, * result;
	char name1[128];
	printf("Enter the first file name: \n");
	scanf("%s", &name1);

	char name2[128];
	printf("Enter the second file name: \n");
	scanf("%s", &name2);

	src1 = fopen(name1, "rb");
	src2 = fopen(name2, "rb");

	if (src1 != nullptr && src2 != nullptr)
	{
		fseek(src1, 0, SEEK_END);
		size_t size1 = ftell(src1);
		fseek(src1, 0, SEEK_SET);

		fseek(src2, 0, SEEK_END);
		size_t size2 = ftell(src2);
		fseek(src2, 0, SEEK_SET);

		//������� ��� ������
		char* buffer1 = new char[size1];
		char* buffer2 = new char[size2];

		if (buffer1 != nullptr && buffer2 != nullptr)
		{
			fread(buffer1, sizeof(char), size1, src1);
			fread(buffer2, sizeof(char), size2, src2);

			//���������� �� ���� ������� � ���� ����
			result = fopen("result.txt", "wb");
			if (result != nullptr)
			{
				fwrite(buffer1, sizeof(char), size1, result);
				fwrite(buffer2, sizeof(char), size2, result);
				fclose(result);
			}
			delete[] buffer1;
			delete[] buffer2;
		}
		fclose(src1);
		fclose(src2);
	}
	else
		cout << "Error opening files!" << endl;
}