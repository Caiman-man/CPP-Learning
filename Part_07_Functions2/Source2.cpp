#include <iostream>
using namespace std;

/*2. ������� ��������� ������ �����, ������ ������� ������ � ��������� ������ �������
	 � ������ ������� ������� ������ �� �����.*/

	 //������������ �������������� ������ ������ �� 5�� ���������

void enter_and_change(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	int temp = arr[0];
	arr[0] = arr[size - 1];
	arr[size - 1] = temp;
	cout << "\n";
}

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void main()
{
	cout << "Enter an array: " << endl;
	int array[5];

	enter_and_change(array, 5);

	cout << "After changing: ";
	print_array(array, 5);

	system("pause");
}