#include <iostream>
using namespace std;
void main()
{
	/* ������ 3: ������������ ������ 5 �����, 
	��������� ������������ ������������ ������������� ����� 
	� ������� �� �����*/

	//������ ���� ����������, � ������ ������� ������
	int a, b, c, d, e;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;
	cout << "Enter a fourth number: " << endl;
	cin >> d;
	cout << "Enter a fifth number: " << endl;
	cin >> e;

	//������� ����������-��������������
	int mult = 1;

	//��������� ��������������� �����, � ��������
	if (a < 0)
	{
		mult = mult * a;
	}
	if (b < 0)
	{
		mult = mult * b;
	}
	if (c < 0)
	{
		mult = mult * c;
	}
	if (d < 0)
	{
		mult = mult * d;
	}
	if (e < 0)
	{
		mult = mult * e;
	}
	else
	{
		mult = 0;
	}

	//����� ����������
	cout << "Multiplication: " << mult << endl;

	system("pause");
}