#pragma once
class Vector
{
private:
	int v[5];
public:
	//����������� ��� ����������
	Vector();

	//����������� � �����������
	Vector(int n);

	//������� / ������� ��� ������� � �����
	void set_Number(int index, int n);
	int get_Number(int index);

	//����� �� �����
	void Print();
};

