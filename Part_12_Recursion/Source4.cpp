#include <iostream>
using namespace std;

/*4. ������������ ������ 5 �����, 
	 ����������� ������� ���������� 1, ���� ��� ����� ���� � ������� �����������, � ����� 0*/

	/*� ��������� ������� ��� ���� ����������, ��� �� ���������� � �� ��������� �����,
	��� �� ����� ����� ���� � ��� ���������*/

bool check(int n, int b)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1, a);
	}
	if (res == true && a > b)
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: " << check(1, 0) << endl;
}