#include <iostream>
using namespace std;

/*1. ������������ ������ ������ �� 5 �����, 
	 ����������� ������� ��������, ��� �� ����� � ������� ������� �� 2 � �� 3 ��� �������.*/

int Check(int arr[], int size, int n = 0)
{
	int res = 1;
	cin >> arr[n];
	if (n < size-1)
		res = Check(arr, size, n + 1);

	if (arr[n] % 2 == 0 && arr[n] % 3 == 0)
		return 1 * res;
	else
		return 0;
}

void main()
{
	int arr[5];
	cout << "Enter an array: " << endl;
	cout << "Result is: "<< Check(arr, 5) << endl;
}