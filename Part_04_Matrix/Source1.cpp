#include <iostream>
using namespace std;
void main()
{
	/*1. ������������ ������ ������ 3�3. ��������� ������� ������������ 
		 ������������� ����� � ����������� �������������, � ������� �� �� �����*/

	int a[3][3];
	int max = 0, min = 0;

	//����
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

	//����� �������
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//���������� ��������� �������� max � min
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (a[i][k] < 0) max = a[i][k];		//��������� ��� �������� �������, ���� ���� ���� - ������ ����, �� ���� ��� ��� ������� ��������
			if (a[i][k] > 0) min = a[i][k];		//��������� ��� �������� �������, ���� ���� ���� - ������ ����, �� ���� ��� ��� ������� ��������
		}
	}

	//�������� ������� � �����
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (a[i][k] > max && a[i][k] < 0) max = a[i][k];
			if (a[i][k] < min && a[i][k] > 0) min = a[i][k];
		}
	}
	
	//����� (���� �������������/ ������������� ��� - �� ������ ������)
	if (max != 0) cout << "Max of negatives = " << max << endl;
	else cout << "Negatives not found" << endl;
	if (min != 0) cout << "Min of positives = " << min << endl;
	else cout << "Positives not found" << endl;


	system("pause");
}
