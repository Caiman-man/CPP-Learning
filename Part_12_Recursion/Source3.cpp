#include <iostream>
using namespace std;

/*3. ������������ ������ 5 �����, 
	 ����������� ������� ���������� 1, ���� ��� ����� �������������, � ����� 0*/

	 /*����� ������� ����� �������������� �������, res ����� ����� ����� true,
	 � ��� ���������� "a" ����� ���� ������ ����,
	 �� ���� ���� ���� ��� ������� �� ���������� �� res ����� ����� - false 
	 � ��� ������� �� ����� ����� - true*/

bool check(int n)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1);
	}
	if (res == true && a > 0)		
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: "<< check(1)<< endl;
}