#include <iostream>
#include "conio.h"
using namespace std;
void main()
{
	/*3. ������������ ������ ������. 
		 ��������� �������� ��� ����� �� '!' � ������� ������ �� �����*/

	char s[100];
	cin.getline(s, 100);
	cout << "Before:\t"<< s << endl;

	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') s[i]='!';
	}
	cout << "After:\t" << s << endl;

	system("pause");

}