#include <iostream>
using namespace std;
void main()
{
	/*4. ������������ ������ 2 ������� �� 4 �����, ��������� ��������,
		 ����� �� ����� ��������� ���� ��������(YES / NO)*/

	int a[4], b[4], sum1 = 0, sum2 = 0;
	
	//������ ������ ������ � ������� ����� ���������
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		sum1 += a[i];
	}
	cout << endl;

	//������ ������ ������ � ������� ����� ���������
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
		sum2 += b[i];
	}
	cout << endl;

	//��������� �������� ����
	if (sum1 == sum2) cout << "YES" << endl;
	else cout << "NO" << endl;

	system("pause");





}