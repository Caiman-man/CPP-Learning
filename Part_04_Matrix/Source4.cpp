#include <iostream>
using namespace std;
void main()
{
	/*4. ������������ ������ 2 ������� 2�2. 
		 ���� ������������ ���� ����� 1 ������� ����� ����� ���� ����� 2 �������, 
		 �� ��������� ����� "YES", ����� "NO"*/

	int a[2][2];
	int b[2][2];
	int sum = 0;
	int mult = 1;

	//���� ������� a � ������ ������������
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cin >> a[i][k];
			mult *= a[i][k];
		}
	}
	cout << endl;

	//���� ������� b � ������ �����
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cin >> b[i][k];
			sum += b[i][k];
		}
	}
	cout << endl;

	//����� ������� a
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << "a[" << i << "][" << k << "]= " << a[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	//����� ������� b
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << "b[" << i << "][" << k << "]= " << b[i][k] << "   ";
		}
		cout << endl;
	}
	cout << endl;

	if (mult == sum) cout << "YES" << endl;
	else cout << "NO" << endl;


	system("pause");
}
