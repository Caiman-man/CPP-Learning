#include <iostream>
using namespace std;
void main()
{
	/*5. ������������ ������ ������ 3�4. 
		 ��������� ������ ������� ������ � ��������� ������, 
		 ����� ���� ������� ������ �� �����*/

	int a[3][4];
	int temp;

	//���� �������
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

	//����� ������� ��
	cout << "Before:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//������
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			temp = a[0][k];
			a[0][k] = a[2][k];
			a[2][k] = temp;
		}
	}
	cout << endl;

	//����� ������� �����
	cout << "After:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
}
