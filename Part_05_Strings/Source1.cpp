#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*1. ������������ ������ �������, ���� �� ����� ESC.
		 ��������� ������������ ����� ���� ��������� �����.*/

	char �h = 0;
	int sum = 0;
	while (�h != 27)
	{
		�h = _getch();
		cout << �h << endl;
		if (�h >= '0' &&  �h <= '9')
		{
			sum += (�h - '0');
		}
	}
	cout << "Sum is: " << sum << endl;

	system("pause");

}