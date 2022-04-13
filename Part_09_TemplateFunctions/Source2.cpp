#include <iostream>
using namespace std;

/*2. ��������� ������� ��������� ���������� ������ � ������ 
	 � ������� �� ����� 2 ����� ������� ����� � ������� (��������� ���������)*/

	//������ ������������ ������������
	//��������� ������� ������ ��� ����� ������� �����, �� ��������

template <typename T>
void fill_keyboard(T a[], int size)											//��������� ������ � ����������
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
}

template <typename T>
void print(T a[], int size)													//������ �������
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

template <typename T>
void find_max(T a[], int size)												//���������� ����������
{
	T max_1 = a[0];
	T max_2 = a[0];

	for (int i = 0; i < size; i++)
	{
		max_1 = (a[i] > max_1) ? a[i] : max_1;

	}
	for (int i = 0; i < size; i++)
	{
		max_2 = (a[i] > max_2 && a[i] < max_1) ? a[i] : max_2;
	}

	cout << "Max 1 = " << max_1 << "\nMax 2 = " << max_2 << endl;
}

void main()
{
	int size = 0;															//�������, ������ � ������� ������
	cout << "Enter a size of array: " << endl;
	cin >> size;
	int* arr = new int[size];
	cout << "Enter an array: " << endl;
	fill_keyboard(arr, size);
	cout << "Array is: ";
	print(arr, size);
	cout << "\n";

	find_max(arr, size);													//������� ���������

	delete[]arr;
	system("pause");
}