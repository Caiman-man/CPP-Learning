#include <iostream>
using namespace std;
void main()
{
	/* ������ 2: ������������ ������ 5 �����, 
	��������� ������������ ����� ������������� ����� 
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

	//������� ���������� ��� �����
	int sum = 0;

	//��������� ��������������� �����, � ���������
	if (a > 0)
	{
		sum = sum + a;
	}
	if (b > 0)
	{
		sum = sum + b;
	}
	if (c > 0)
	{
		sum = sum + c;
	}
	if (d > 0)
	{
		sum = sum + d;
	}
	if (e > 0)
	{
		sum = sum + e;
	}

	//����� ����������
	cout << "Sum: " << sum << endl;

	system("pause");
}