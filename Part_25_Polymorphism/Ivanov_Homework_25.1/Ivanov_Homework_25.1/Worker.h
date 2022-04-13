#pragma once
#include "Employee.h"
class Worker : public Employee
{
	//������ �� ����
	double m_rate_by_day;
	//���-�� ������������ ����
	unsigned int m_worked_days;
public:
	Worker(const char* firstname, const char* lastname, unsigned int age,
		   double rate_by_day, unsigned int worked_days);
	double GetPayment();
	void Print();
	void Save(const char filename[]);
};

