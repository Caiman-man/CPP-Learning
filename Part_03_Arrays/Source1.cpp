#include <iostream>
using namespace std;
void main()
{
	/*1. ������������ ������ �����, ���� �� ����� �� ����� ������ 20
		 ��������� ��������� ������������ ������������� �����.*/

	int a, sum = 0, mult = 1;
	while (sum <= 20)
	{
		cin >> a;
		sum += a;
		if (a > 0) mult *= a;
	}
	cout << "Sum is:\t\t" << sum << endl;
	cout << "Multiply is:\t" << mult << endl;

	system("pause");





}