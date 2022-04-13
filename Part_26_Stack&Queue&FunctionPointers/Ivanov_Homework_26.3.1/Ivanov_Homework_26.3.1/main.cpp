#include <iostream>
#include <fstream>
using namespace std;

/*3. ������� ������ � ������������� �������� �� 000000 �� 999999
����� ���������� ������� �� ��� ����������.
����������� �������� ����� ������� ������ � ������������ � ������������
���������� : 123321, 123123, 123456, 101010, 987654
������������ ������ ������������ ������������ "��������� ����������� �������",
������� ��������� ����� � ���������� ��������� ��������.

����������� ������ ����� ��������� �� �������

LuckyCriteria - ������� ����� ��� ���� ���������� �������(����� Check)
���������� : LuckySums, LuckySequence

��������� ��� ���������� ������ � ����.*/


//���������� ���� ������ lucky_type
typedef bool (*lucky_type)(int, int, int, int, int, int);

//������� ������� - 10 �����:
//1. ����� ���� ����
bool func1(int a, int b, int c, int d, int e, int f)
{
	if (a + b + c == d + e + f)
	{
		return true;
	}
	else return false;
}

//2. 111111
bool func2(int a, int b, int c, int d, int e, int f)
{
	if (a == b && b == c && c == d && d == e && e == f)
	{
		return true;
	}
	else return false;
}

//3. 123456
bool func3(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1 && f == e + 1)
	{
		return true;
	}
	else return false;
}

//4. 987654
bool func4(int a, int b, int c, int d, int e, int f)
{
	if (b == a - 1 && c == b - 1 && d == c - 1 && e == d - 1 && f == e - 1)
	{
		return true;
	}
	else return false;
}

//5. 123123
bool func5(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == a && e == b && f == c)
	{
		return true;
	}
	else return false;
}

//6. 123321
bool func6(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == c && e == b && f == a)
	{
		return true;
	}
	else return false;
}

//7. 010101
bool func7(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == a && d == b && e == a && f == b)
	{
		return true;
	}
	else return false;
}

//8. 101010
bool func8(int a, int b, int c, int d, int e, int f)
{
	if (b == a - 1 && c == a && d == b && e == a && f == b)
	{
		return true;
	}
	else return false;
}

//9. 111222
bool func9(int a, int b, int c, int d, int e, int f)
{
	if (a == b && b == c && d == e && e == f)
	{
		return true;
	}
	else return false;
}

//10. 112233
bool func10(int a, int b, int c, int d, int e, int f)
{
	if (a == b && c == d && e == f)
	{
		return true;
	}
	else return false;
}

//�����
bool quit(int a, int b, int c, int d, int e, int f)
{
	exit(0);
	return true;
}

void main()
{
	int count = 0;
	int menu_index;

	// ������ ���������� �� ������� �������
	lucky_type menu[11] = { func1, func2, func3, func4, func5, func6, func7, func8, func9, func10, quit };

	//������ ����, ��� �� ��� ����� ������� ���������, �� ������������� ������ ������
	remove("result.txt");

	do 
	{
		cout << "1. - sum of three numbers" << endl;
		cout << "2. - 111111" << endl;
		cout << "3. - 123456" << endl;
		cout << "4. - 987654" << endl;
		cout << "5. - 123123" << endl;
		cout << "6. - 123321" << endl;
		cout << "7. - 010101" << endl;
		cout << "8. - 101010" << endl;
		cout << "9. - 111222" << endl;
		cout << "10. - 112233" << endl;
		cout << "11. - exit" << endl;

		cout << "Enter menu number:" << "\n";
		cin >> menu_index;

		//���� ����� ���� �� ���������� - �� ������� ��������������� ���������
		if (menu_index <= 0 || menu_index > 11)
		{
			cout << "WRONG MENU NUMBER!" << "\n";
			system("pause");
			system("cls");
		}
		else
		{
			//����� �� �������� ����� ��� ������ � ����
			ofstream file;
			file.open("result.txt", ios_base::app);
			if (file.is_open())
			{
				//��������� ����� ��� �������� ����� � ������ ����������� ������� �������
				for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
				for (int c = 0; c <= 9; c++)
				for (int d = 0; d <= 9; d++)
				for (int e = 0; e <= 9; e++)
				for (int f = 0; f <= 9; f++)
				{
					//������� ������� ���������� � ����������� �� ���������� ������ � ����
					//���� ������� ������ true, �� ���������� ����� ��������� �� �����, ��������� � ����, � ����������� ���-�� �������
					if (menu[menu_index - 1](a, b, c, d, e, f))
					{
						cout << a << b << c << d << e << f << "\n";
						file << a << b << c << d << e << f << "\n";
						count++;
					}
				}
				file << "\n";
				file.close();

				cout << "Tickets saved successfully!" << "\n";
				cout << "Amount of lucky tickets = " << count << "\n";

				system("pause");
				system("cls");
			}
			else
				cout << "Error opening file!" << "\n";
		}
	} while (true);
}