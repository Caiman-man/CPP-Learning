#include <iostream>
using namespace std;
void main()
{
	/* ������ 1: ������������ ������ 4 �����, 
	��������� ������������ ���������� ����� ����� ���
	� ������� �� �����*/

	//������ ��� ����������, � ������ ������� ������
	int a, b, c;
	cout << "Enter a first number: " << endl;
	cin >> a;
	cout << "Enter a second number: " << endl;
	cin >> b;
	cout << "Enter a third number: " << endl;
	cin >> c;

	//������� ����������-�������
	int count = 0;

	//��������� ������� �����, � �������� �������
	if (a == 3)
	{
		count++;
	}
	if (b == 3)
	{
		count++;
	}
	if (c == 3)
	{
		count++;
	}

	//����� ����������
	cout << "Number of triples: " << count << endl;

	system("pause");
}