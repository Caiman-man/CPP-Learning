#include <iostream>
using namespace std;
void main()
{
	/* ������ 4: ������������ ������ 3 �����, 
	��������� ������� ������������ ����� 
	� ������� �� �����*/

	//������ ��� ����������, � ������ ������� ������
	int a, b, c;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;

	//������� ���������� ��� ���������
	int max;

	//��������� ����� ���������� ������, ��������� ���������� �
	if (a > b && a > c)
	{
		max = a;
	}
	if (b > a && b > c)
	{
		max = b;
	}
	if (c > a && c > b)
	{
		max = c;
	}

	//����� ����������
	cout << "Max: " << max << endl;

	system("pause");
}