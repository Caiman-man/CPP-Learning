#include <iostream>
using namespace std;
void main()
{
	/*2. ������������ ������ ������ �� 5 �����, 
		 ��������� ���������, ��� �� ��� �������������(YES / NO)*/

	int a[5], count = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		if (a[i] > 0) count++;
	}

	if (count == 5) cout << "YES" << endl;
	else cout << "NO" << endl;

	system("pause");





}