#include <iostream>
using namespace std;
void main()
{
	/*4. ������������ ������ 5 �����, ��������� ������� ����� ������������ 
	� ������������� ����� �� ��������� � ������� �� �����*/

	// ����� - �����

	int a, max, min;
	cin >> a;
	max = a;							//Max ����� ����� ������ ��������� ����������
	min = a;							//Min ����� ����� ������ ��������� ����������
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > max) max = a;
		if (a < min) min = a;
	}
	cout << "Max + Min = " << max+min << endl;
	system("pause");

}