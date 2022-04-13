#pragma once
#include "Employee.h"
class SalesPerson : public Employee
{
	//оклад за мес€ц
	double m_sp_salary;
	//процент от общей суммы проданных товаров
	double m_percent_for_sales;
	//сумма проданных товаров
	double m_sales_amount;
public:
	SalesPerson(const char* firstname, const char* lastname, unsigned int age,
				double sp_salary, double percent_for_sales, double sales_amount);
	double GetPayment();
	void Print();
	void Save(const char filename[]);
};

