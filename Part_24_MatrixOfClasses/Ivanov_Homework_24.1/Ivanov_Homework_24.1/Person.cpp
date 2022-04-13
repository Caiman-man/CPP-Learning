#include "Person.h"
#include <iostream>
using namespace std;

//Конструктор с параметрами
Person::Person(const char* firstname, const char* lastname, unsigned int age)
{
	//cout << "Person constr" << endl;
	this->m_firstname = new char[strlen(firstname) + 1];
	this->m_lastname = new char[strlen(lastname) + 1];
	strcpy(this->m_firstname, firstname);
	strcpy(this->m_lastname, lastname);
	this->m_age = age;
}

//Конструктор копирования
Person::Person(const Person& source)
{
	//cout << "Person Copy constr" << endl;
	this->m_firstname = new char[strlen(source.m_firstname) + 1];
	this->m_lastname = new char[strlen(source.m_lastname) + 1];
	strcpy(this->m_firstname, source.m_firstname);
	strcpy(this->m_lastname, source.m_lastname);
	this->m_age = source.m_age;
}

//Деструктор
Person::~Person()
{
	//cout << "Person destr" << endl;
	delete[] m_firstname;
	delete[] m_lastname;
}

//Вывод
void Person::Print()
{
	cout << m_firstname << " " << m_lastname << ", Age: " << m_age << " ";
}

//Геттеры
char* Person::get_firstname()
{
	return this->m_firstname;
}

char* Person::get_lastname()
{
	return this->m_lastname;
}

unsigned int Person::get_age()
{
	return m_age;
}

