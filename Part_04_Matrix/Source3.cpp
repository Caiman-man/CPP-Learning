#include <iostream>
using namespace std;
void main()
{
	/*3. ������������ ������ ������ 3�4. 
		 ��������� ������ ��� 3 �� 5, � ��� 5 �� 3 � ������� ������ �� �����*/

	int a[3][4];
	int sum = 0;

	//���� � �������� �������
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cin >> a[i][k];
			if (a[i][k] == 3) a[i][k] = 5;
			else
			{
				if (a[i][k] == 5) a[i][k] = 3;
			}
		}
	}
	cout << endl;

	//����� �������
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
