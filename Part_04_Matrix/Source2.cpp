#include <iostream>
using namespace std;
void main()
{
	/*2. ������������ ������ ������ 3�3. 
		 ��������� ������� ����� ��������� ������� �������*/

	int a[3][3];
	int sum = 0;

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

	//������� ����� � �������
	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int k = 0; k < 3; k++)
		{
			sum += a[k][i];			
		}
		cout << "   sum  = " << sum;
	}
	cout << endl;
	
	system("pause");
}
