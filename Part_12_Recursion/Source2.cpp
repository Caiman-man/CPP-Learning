#include <iostream>
using namespace std;

/*2. ������������ ������ �����, ���� �� ����� 0. 
	 ����������� ������� ������������ ���������� ����� ����� ��������� �����.*/

	//����������� ���-�� ������ ������������� �����

int count(int n)
{
	int a;
	int res = 0;
	cin >> a;
	if (a !=0)
	{
		res = count(n + 1);
	}
	return (a == 3) ? res + 1 : res;
}

void main()
{
	cout << "Enter the numbers:" << endl;
	int result = count(1);
	cout << "Number of triples = " << result << endl;
}