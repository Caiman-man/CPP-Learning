#include <iostream>
using namespace std;
void main()
{
	/*5. ������������ ������ 5 �����, ��������� ������������ ���������� 
	�������������, ������������� ����� � ����� � ������� �� �����*/

	int a;
	int pos = 0, neg = 0, zer = 0;		//��������
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a > 0) pos++;
		if (a < 0) neg++;
		if (a == 0) zer++;
	}
	cout << "Positives: " << pos<< endl;
	cout << "Negatives: " << neg<< endl;
	cout << "Zeros: " << zer<< endl;

	system("pause");

}