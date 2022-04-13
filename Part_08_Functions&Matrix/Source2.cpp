#include <iostream>
using namespace std;

/*2. ������� ��������� 2 ��������� ������������ ������� � �� ������� 
	 � ���������� �� �����������. (�� / ���)*/

	//������� ����������� �������!

void fill_arr(int** arr, int row, int col)												//������� ��� ����������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> arr[i][k];
		}
	}
}

void print_arr(int** arr, int row, int col)												//������� ��� ������ �� ����� �������
{
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << arr[i][k] << "\t";
		}
		cout << "\n";
	}
}

int identity_check(int** arr1, int** arr2, int row1, int col1, int row2, int col2)		//������� ��� �������� �� ������������
{
	int res = 0;
	if (row1 != row2 || col1 != col2) return 0;
	else
	{
		for (int i = 0; i < row1; i++)
		{
			for (int k = 0; k < col1; k++)
			{
				if (arr1[i][k] != arr2[i][k])
				{
					return 0;
					break;
				}
				else res++;
			}
		}
	}
	
	if (res != (row1 * col1)) return 0;
	else return 1;
}


void main()
{
	int rows_1, cols_1, rows_2, cols_2;										//������� ���������� ��� �������� ��������			

	cout << "Enter the number of rows for the first array: " << endl;		//������ ������� �������_1
	cin >> rows_1;
	cout << "Enter the number of cols for the first array: " << endl;
	cin >> cols_1;
	int** p_1 = new int* [rows_1];											//�������� ������
	for (int i = 0; i < rows_1; i++)
	{
		p_1[i] = new int[cols_1];
	}
	cout << "Enter the first array: " << endl;								//������ ������� ������_1
	fill_arr(p_1, rows_1, cols_1);
	cout << "\n";
	print_arr(p_1, rows_1, cols_1);											//������� �� �������
	cout << "\n";


	cout << "Enter the number of rows for the second array: " << endl;		//������ ������� �������_2
	cin >> rows_2;
	cout << "Enter the number of cols for the second array: " << endl;
	cin >> cols_2;
	int** p_2 = new int* [rows_2];											//�������� ������											
	for (int i = 0; i < rows_2; i++)										
	{
		p_2[i] = new int[cols_2];
	}
	cout << "Enter the second array: " << endl;								//������ ������� ������_2
	fill_arr(p_2, rows_2, cols_2);									
	cout << "\n";
	print_arr(p_2, rows_2, cols_2);											//������� �� �������									
	cout << "\n";

	if (identity_check(p_1, p_2, rows_1, cols_1, rows_2, cols_2) == 1) cout << "YES" << endl;		//�������� �� ������������
	else cout << "NO" << endl;

	for (int i = 0; i < rows_1; i++)										//������� ������
	{
		delete[] p_1[i];
	}
	for (int i = 0; i < rows_2; i++)
	{
		delete[] p_2[i];
	}

	delete[] p_1;
	delete[] p_2;

	system("pause");
}