#pragma once

class Person
{
private:
	char m_firstname[20];
	char m_lastname[20];
	int m_age;
	double m_height;
	double m_weight;
public:
	//����������� ��� ����������
	Person();

	//����������� � �����������
	Person(const char name[20], const char lastname[20], int age, double height, double weight);

	//������� / ������� ��� ������� � �����
	void set_Name(const char name[20]);
	char* get_Name();
	void set_LastName(const char lastname[20]);
	char* get_LastName();
	void set_Age(int age);
	int get_Age();
	void set_Height(double height);
	double get_Height();
	void set_Weight(double weight);
	double get_Weight();

	//����� �� �����
	void Print();
};