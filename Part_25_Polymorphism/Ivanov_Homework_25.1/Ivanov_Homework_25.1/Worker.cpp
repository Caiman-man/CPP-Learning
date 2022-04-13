#include "Worker.h"
#include <fstream>
#include <iostream>
using namespace std;

//Конструктор с параметрами
Worker::Worker(const char* firstname, const char* lastname, unsigned int age,
			   double rate_by_day, unsigned int worked_days) :Employee(firstname, lastname, age)
{
	this->m_rate_by_day = rate_by_day;
	this->m_worked_days = worked_days;
}

//GetPayment
double Worker::GetPayment()
{
	return m_rate_by_day * m_worked_days;
}

//Вывод
void Worker::Print()
{
	cout << "Worker" << "\n";
	Employee::Print();
	cout << "1. Worker's day rate = " << m_rate_by_day << "\n";
	cout << "2. number of days worked = " << m_worked_days << "\n";
}

//Save
void Worker::Save(const char filename[])
{
	Employee::Save(filename);

	ofstream f;
	f.open(filename, ios_base::app);
	if (f.is_open())
	{
		f << "Position - Worker" << "\n";
		f << "1. Worker's day rate = " << m_rate_by_day << "\n";
		f << "2. number of days worked = " << m_worked_days << "\n\n";
		f.close();
	}
	else
		cout << "Error opening file!" << "\n";
}