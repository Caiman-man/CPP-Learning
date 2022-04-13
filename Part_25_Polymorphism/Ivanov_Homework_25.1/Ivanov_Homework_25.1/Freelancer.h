#pragma once
#include "Employee.h"
class Freelancer : public Employee
{
	//ставка за час
	double m_rate_by_hour;
	//кол-во часов
	unsigned int m_worked_hours;
public:
	Freelancer(const char* firstname, const char* lastname, unsigned int age,
			   double rate_by_hour, unsigned int worked_hours);
	double GetPayment();
	void Print();
	void Save(const char filename[]);
};

