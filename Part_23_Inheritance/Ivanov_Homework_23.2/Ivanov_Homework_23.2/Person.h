#pragma once
class Person
{
protected:
	char m_firstname[24];
	char m_lastname[24];
	int m_age;
	double m_height;

public:
	Person(const char name[24], const char lastname[24], int age, double height);
	void Print();

	void set_name(const char name[24]);
	char* get_name();

	void set_lastname(const char lastname[24]);
	char* get_lastname();

	void set_age(int age);
	int get_age();

	void set_height(double height);
	double get_height();
};

