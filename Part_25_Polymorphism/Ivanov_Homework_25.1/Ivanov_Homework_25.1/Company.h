#pragma once
#include "Employee.h"
class Company
{
	Employee** m_employees;
	size_t m_size;
	size_t m_max_size;
public:
	Company(size_t max_size);
	~Company();
	void Add(Employee* empl_source);
	double GetPayment();
	void Print();
	void Save(const char filename[]);
};

