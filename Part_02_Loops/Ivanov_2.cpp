#include <iostream>
using namespace std;
void main()
{
	/*2. ������������ ������ 5 �����, ��������� ������������ ����� ������ 
	����� � ������� �� �����*/

	int a = 0, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a % 2 == 0) sum += a;
	}
	cout << "Sum is: " << sum << endl;
}