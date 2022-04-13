#include "Employee.h"
#include <fstream>
#include <iostream>
using namespace std;

//Конструктор с параметрами
Employee::Employee(const char* firstname, const char* lastname, unsigned int age)
{
	this->m_firstname = new char[strlen(firstname) + 1];
	this->m_lastname = new char[strlen(lastname) + 1];
	strcpy(this->m_firstname, firstname);
	strcpy(this->m_lastname, lastname);
	this->m_age = age;
}

//Деструктор
Employee::~Employee()
{
	delete[] m_firstname;
	delete[] m_lastname;
}

//GetPayment
double Employee::GetPayment()
{
	return 0;
}

//Вывод
void Employee::Print()
{
	cout << m_firstname << " " << m_lastname << ", age: " << m_age << "\n";
}

//Save
void Employee::Save(const char filename[])
{
	ofstream f;
	f.open(filename, ios_base::app);
	if (f.is_open())
	{
		f << m_firstname << " " << m_lastname << ", age: " << m_age << "\n";
		f.close();
	}
	else
		cout << "Error opening file!" << "\n";
}
