#include <iostream>
#include "Person.h"
using namespace std;

//Конструктор с параметрами
Person::Person(const char name[24], const char lastname[24], int age, double height)
{
	if (strlen(name) > 0 && strlen(lastname) > 0 && age > 0 && age < 110 && height > 0 && height < 3)
	{
		strcpy(this->m_firstname, name);
		strcpy(this->m_lastname, lastname);
		this->m_age = age;
		this->m_height = height;
	}
	else
	{
		strcpy(this->m_firstname, "NoName");
		strcpy(this->m_lastname, "NoName");
		this->m_age = 0;
		this->m_height = 0;
	}
}


//Сеттер / Геттер - Имя
void Person::set_name(const char name[24])
{
	strcpy(this->m_firstname, name);
}
char* Person::get_name()
{
	return this->m_firstname;
}

//Сеттер / Геттер - Фамилия
void Person::set_lastname(const char lastname[24])
{
	strcpy(this->m_lastname, lastname);
}
char* Person::get_lastname()
{
	return this->m_lastname;
}

//Сеттер / Геттер - Возраст
void Person::set_age(int age)
{
	if (age > 0 && age < 110)
	{
		this->m_age = age;
	}
}

int Person::get_age()
{
	return m_age;
}

//Сеттер / Геттер - Рост
void Person::set_height(double height)
{
	if (height > 0 && height < 3)
	{
		this->m_height = height;
	}
}
double Person::get_height()
{
	return m_height;
}


//Вывод
void Person::Print()
{
	cout << "Name: " << m_firstname << "\nLastname: " << m_lastname << "\nAge: " << m_age << "\nHeight: " << m_height << "\n";
}