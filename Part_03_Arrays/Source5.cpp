#include <iostream>
using namespace std;
void main()
{
	/*5. ������������ ������ 2 ������� �� 4 �����, 
		 ��������� �������� �� ������� �������� ������� ������� ������� ������� ������� 
		 � ��������� ���������� � 3 ������, ��� ������� ��������� �� �����.*/

	int a[4], b[4], c[4];
	
	//������ ������ ������
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	cout << endl;

	//������ ������ ������
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
	}
	cout << endl;

	//������� ������� � ���������� � ������� ������
	for (int i = 0; i < 4; i++)
	{
		c[i] = a[i] - b[i];
	}
	cout << endl;

	//������� ��� �������
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << b[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << c[i] << "  ";
	}
	cout << endl;

	system("pause");





}