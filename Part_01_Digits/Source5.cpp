#include <iostream>
using namespace std;
void main()
{
	/* ������ 5: ������������ ������ 5 �����, 
	��������� ������������ ���������� �������������, 
	������������� ����� � �����
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

	//������� ����������-������� ��� ������������� �����
	int pos = 0;

	//������� ����������-������� ��� ������������� �����
	int neg = 0;

	//������� ����������-������� ��� �����
	int zer = 0;

	//��������� ���������� �
	if (a > 0)
	{
		pos++;
	}
	else
	{
		if (a < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//��������� ���������� b
	if (b > 0)
	{
		pos++;
	}
	else
	{
		if (b < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//��������� ���������� c
	if (c > 0)
	{
		pos++;
	}
	else
	{
		if (c < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//��������� ���������� d
	if (d > 0)
	{
		pos++;
	}
	else
	{
		if (d < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//��������� ���������� e
	if (e > 0)
	{
		pos++;
	}
	else
	{
		if (e < 0)
		{
			neg++;
		}
		else
		{
			zer++;
		}
	}

	//����� ����������
	cout << "Positives: " << pos << endl;
	cout << "Negatives: " << neg << endl;
	cout << "Zeros: " << zer << endl;

	system("pause");
}