#include <iostream>
using namespace std;
void main()
{
	//3. ������������ ������ 5 �����, ��������� ������� ������������ �� ���

	// ����� - �����

	int a, max;
	cin >> a;
	max = a;							//Max ����� ����� ������ ��������� ����������
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		if (a > max) max = a;
	}
	cout << "Max is: " << max << endl;
	system("pause");
	
}