#include "Person.h"
#include <iostream>
using namespace std;

//Конструктор без параметров (данные человека заданы по умолчанию)
Person::Person()
{
	strcpy(this->m_firstname, "Viktor");
	strcpy(this->m_lastname, "Barinov");
	this->m_age = 55;
	this->m_height = 1.8;
	this->m_weight = 105;
}

//Конструктор с параметрами
Person::Person(const char name[20], const char lastname[20], int age, double height, double weight)
{
	if (strlen(name) > 0 && strlen(lastname) > 0 && age > 0 && age < 110 && height > 0 && height < 3 && weight > 0 && weight < 250)
	{
		strcpy(this->m_firstname, name);
		strcpy(this->m_lastname, lastname);
		this->m_age = age;
		this->m_height = height;
		this->m_weight = weight;
	}
	else
	{
		strcpy(this->m_firstname, "NoName");
		strcpy(this->m_lastname, "NoName");
		this->m_age = 0;
		this->m_height = 0;
		this->m_weight = 0;
	}
}

//Сеттер / Геттер - Имя
void Person::set_Name(const char name[20])
{
	strcpy(this->m_firstname, name);
}
char* Person::get_Name()
{
	return this->m_firstname;
}

//Сеттер / Геттер - Фамилия
void Person::set_LastName(const char lastname[20])
{
	strcpy(this->m_lastname, lastname);
}
char* Person::get_LastName()
{
	return this->m_lastname;
}

//Сеттер / Геттер - Возраст
void Person::set_Age(int age)
{
	if (age > 0 && age < 100)
	{
		this->m_age = age;
	}
}

int Person::get_Age()
{
	return m_age;
}

//Сеттер / Геттер - Рост
void Person::set_Height(double height)
{
	if (height > 0 && height < 3)
	{
		this->m_height = height;
	}
}
double Person::get_Height()
{
	return m_height;
}

//Сеттер / Геттер - Вес
void Person::set_Weight(double weight)
{
	if (weight > 0 && weight < 250)
	{
		this->m_weight = weight;
	}
}
double Person::get_Weight()
{
	return m_weight;
}

//Вывод данных
void Person::Print()
{
	cout << "Name: " << m_firstname << "\nLastname: " << m_lastname << "\nAge: " << m_age << "\nHeight: " << m_height << "\nWeight: " << m_weight << endl;
	cout << endl;
}