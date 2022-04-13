#include <iostream>
#include <io.h>
using namespace std;

/*5. ������������ ������ ���� � ����� � ����� ������, 
	 ��������� ������������ ����� ������ ������ � ��������� ������.*/

void main()
{
	char path[256], extension[8];
	printf("Enter file path : \n");
	scanf("%s", &path);
	printf("Enter file extension \n");
	scanf("%s", &extension);
	strcat(path, extension);

	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;
	// ����� ������ ��������� ������
	long hFile;
	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
	hFile = _findfirst(path, &c_file);

	//������ ���������� "sum" ���� long, ��� �������� ����� �������� ������
	long sum = 0;
	// ���� ���� �������� ������
	if (c_file.attrib & _A_SUBDIR)
		cout << c_file.name << "   " << "<DIR>" << endl;
	else
	{
		cout << c_file.name << "   " << c_file.size << endl;
		sum = c_file.size;
	}

	// ���� ��� ��������� ���������� �� ��������� ��������� ������
	while (_findnext(hFile, &c_file) == 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else 
		{
			cout << c_file.name << "   " << c_file.size << endl;
			sum += c_file.size;
		}
	}
	cout << "\n";
	cout << "Sum = " << sum << endl;

	// ���������� ������ �� ������ ��������� ������
	_findclose(hFile);
}