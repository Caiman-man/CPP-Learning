#include <iostream>
using namespace std;

//1. ������� ��������� 3 ����� � ���������� �� ������������

//������������ �������������� ������ ��� �����
int mult(int a, int b, int c)
{
	return a * b * c;
}

void main()
{
	int d, e, f;
	cout << "Enter a first number: " << endl;
	cin >> d;
	cout << "Enter a second number: " << endl;
	cin >> e;
	cout << "Enter a third number: " << endl;
	cin >> f;

	cout << "Multiply:" << mult(d, e, f) << endl;

	system("pause");
}

