#include "Freelancer.h"
#include <fstream>
#include <iostream>
using namespace std;

//Конструктор с параметрами
Freelancer::Freelancer(const char* firstname, const char* lastname, unsigned int age,
					   double rate_by_hour, unsigned int worked_hours) :Employee(firstname, lastname, age)
{
	this->m_rate_by_hour = rate_by_hour;
	this->m_worked_hours = worked_hours;
}

//GetPayment
double Freelancer::GetPayment()
{
	return m_rate_by_hour * m_worked_hours;
}

//Вывод
void Freelancer::Print()
{
	cout << "Freelancer" << "\n";
	Employee::Print();
	cout << "1. Freelancer's hours rate = " << m_rate_by_hour << "\n";
	cout << "2. number of hours worked = " << m_worked_hours << "\n";
}

//Save
void Freelancer::Save(const char filename[])
{
	Employee::Save(filename);

	ofstream f;
	f.open(filename, ios_base::app);
	if (f.is_open())
	{
		f << "Position - Freelancer" << "\n";
		f << "1. Freelancer's hours rate = " << m_rate_by_hour << "\n";
		f << "2. number of hours worked = " << m_worked_hours << "\n\n";
		f.close();
	}
	else
		cout << "Error opening file!" << "\n";
}