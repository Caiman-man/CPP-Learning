#include <iostream>
using namespace std;

/*5. ������������ ������ 5 �����, 
	 ����������� ������� ���������� 1, ���� ��� ����� �������� ��������, � ����� 0*/

/*� ������� �������� �� �������� ������� ��� ��������� "x" � "i". ������ ���������� ����� 2. 
  ����� �� ������ ���� ������ 2 � �� ������ �������� �� "i" ��� �������.*/

bool simple(int x, int i)
{
	if (x < 2)
		return false;
	else if (x == i)
		return true;
	else if (x % i == 0)
		return false;
	else
		return simple(x, i + 1);
}

bool check(int n)
{
	int a;
	bool res = true;
	cin >> a;
	if (n < 5)
	{
		res = check(n + 1);
	}
	if (res == true && simple(a, 2) == true)
		return true;
	else
		return false;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	cout << "Result is: " << check(1) << endl;
}