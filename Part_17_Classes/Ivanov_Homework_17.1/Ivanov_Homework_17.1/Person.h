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
	//Конструктор без параметров
	Person();

	//Конструктор с параметрами
	Person(const char name[20], const char lastname[20], int age, double height, double weight);

	//Сеттеры / Геттеры для доступа к полям
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

	//Вывод на экран
	void Print();
};