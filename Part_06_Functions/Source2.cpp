#include <iostream>
using namespace std;

//2. ������� ��������� ������, ������ ������� � ���������� ����� ������������� ���������

//������������ �������������� ������ ������ �� 5�� ���������
int SumofNeg(int a[], int size)
{
	int res = 0;
	for (size_t i = 0; i < size; i++) 
	{
		cin >> a[i];
		if (a[i] < 0) res += a[i];
	}
	return res;
}

void main()
{
	cout << "Enter an array:" << endl;
	int arr[5];
	cout << "Sum of negatives is: " << SumofNeg(arr, 5) << endl;

	system("pause");
}

