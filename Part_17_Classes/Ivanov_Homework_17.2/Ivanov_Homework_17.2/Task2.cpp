#include <iostream>
#include "Vector.h"
using namespace std;

/*2. ����������� ����� Vector, ������� �������� � ���� ���������� ����������� ������
	 � ����� ��������� ����� ������:
	 - int v[5]																	
	 - ����������� ��� ����������												
	 - ����������� � ����������� (�����, ��� ���������� �������)			
	 - print() - ������ �� �����												
	 - set(int index, int n) - ��������� ����� n � ������ � ������� index		
	 - get(int index) - ������� �������� �������� ������� � ������� index*/

void main()
{
	//����� ������������ �� ���������
	cout <<"First object: " <<endl;
	Vector vector1;
	vector1.Print();
	cout << endl;

	//����� ������������ � �����������
	cout << "Second object: " << endl;
	Vector vector2(777);
	vector2.Print();
	cout << endl;

	//��������� �������� ������� � ������� �������
	vector2.set_Number(0, 555);
	vector2.Print();
	cout << endl;

	//������������� ������� ��� ��������� ������
	int index, get;
	cout << "Enter an index: " << endl;
	cin >> index;
	if (index < 5)												//�������� ������ ����� � main'e
	{
		get = vector2.get_Number(index);
		cout << get << endl;
	}
	else cout << "Error index" << endl;
















}