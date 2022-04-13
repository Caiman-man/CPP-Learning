#include <iostream>
using namespace std;

/*5. ������������ ������ � ���������� ������� 2 ������������ �������� � ���� �������.
	 ��������� ���������� ��� ������� � ������ ������������ ������ � ������� ��� �� �����.*/

void fill_keyboard(int a[], int size)							//��������� ������ � ����������
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
}

void print(int a[], int size)									//������ �������
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

int search_size_3(int size1, int size2)							//����� ����� �������_3
{
	int length1 = 0, length2 = 0;
	for (int i = 0; i < size1; i++)
	{
		length1++;
	}

	for (int i = 0; i < size2; i++)
	{
		length2++;
	}
	return length1 + length2;
}

void copy(int a[], int b[], int c[], int size1, int size2)		//�����w������
{
	for (int i = 0; i < size1; i++)
	{
		c[i] = a[i];
	}
	for (int i = size1, k = 0; k < size2; i++, k++)
	{
		c[i] = b[k];
	}
}


void main()
{
	int size_1 = 0;												//1. �������, ������ � ������� ������_1
	cout << "Enter a size of first array: " << endl;
	cin >> size_1;				
	int* arr_1 = new int[size_1];
	cout << "Enter a first array: " << endl;
	fill_keyboard(arr_1, size_1);						
	cout << "First array: ";
	print(arr_1, size_1);
	cout << "\n";

	int size_2 = 0;												//2. �������, ������ � ������� ������_2
	cout << "Enter a size of second array: " << endl;
	cin >> size_2;
	int* arr_2 = new int[size_2];
	cout << "Enter a second array: " << endl;
	fill_keyboard(arr_2, size_2);
	cout << "Second array: ";
	print(arr_2, size_2);
	cout << "\n";

	int size_3 = search_size_3(size_1, size_2);					//3. ������ ����� �������_3
	int* arr_3 = new int[size_3];								//4. ������� ������_3
	copy(arr_1, arr_2, arr_3, size_1, size_2);					//5. �������� ������� 1 � 2 � ������_3
	cout << "Result is: " << endl;
	print(arr_3, size_3);										//6. ������� ������_3

	delete[]arr_1;
	delete[]arr_2;
	delete[]arr_3;

	system("pause");
}

