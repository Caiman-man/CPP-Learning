#include <iostream>
using namespace std;

/*4. ������� ��������� ������ � ���������, 
	 �������� �� ��� ������ ������������� ����� ������ (��������: "2673")*/

//������������ �������������� ������ ������

int strNum(const char str[])
{
	int cnt = 0;
	if (str[0] != '0')				//����������� ����� �� ������ ���������� � ����
	{
		for (size_t i = 0; str[i] != 0; i++)
		{
			if (str[i] >= '0' && str[i] <= '9') cnt++;
		}
	}

	if (cnt == strlen(str)) return 1;
	else return 0;
}

int main()
{
	cout << "Enter a string:" << endl;
	char string[100];
	cin.getline(string, 100);

	if (strNum(string) == 1) cout << "YES" << endl;
	else cout << "NO" << endl;

	system ("pause");
}

