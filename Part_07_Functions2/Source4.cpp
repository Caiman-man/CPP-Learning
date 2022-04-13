#include <iostream>
using namespace std;

/*4. ��������� �������� �� ������� ������� ��� �������� ����� � ���� �� ������ ������
	 � ������� ��� �� ����� (������������ �������)*/

void fill_keyboard(int a[], int size)					//��������� ������ � ����������
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	cout << "\n";
}

void print(int a[], int size)							//������ �������
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

int search_size_2(int a[], int size)					//���������� �������_2
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 1 || a[i] % 2 == -1 || a[i] == 0) result++;
	}
	return result;
}

void copy(int a[], int b[], int size)					//�����������
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] % 2 == 1 || a[i] % 2 == -1 || a[i] == 0)
		{
			b[k] = a[i];
			k++;
		}
	}
}

void main()
{
	int size_1 = 0;										//1 ������ ���������� ��� ������� �������_1
	cout << "Enter a size of array: " << endl;
	cin >> size_1;										//2 ������ ������ �������_1
	int* arr_1 = new int[size_1];						//3 ������� ������_1

	cout << "Enter an array: " << endl;
	fill_keyboard(arr_1, size_1);						//4 ��������� �������������� ������_1
	print(arr_1, size_1);								//5 ������� ������_1

	int size_2 = search_size_2(arr_1, size_1);			//6 ������� ������ ��� �������_2
	int* arr_2 = new int[size_2];						//7 ������� ������_2

	copy(arr_1, arr_2, size_1);							//8 ����������� �� 1 � 2
	print(arr_2, size_2);								//9 ������� ������_2

	delete[]arr_1;
	delete[]arr_2;

	system("pause");
}

