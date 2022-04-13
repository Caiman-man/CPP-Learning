#include "SalesPerson.h"
#include <fstream>
#include <iostream>
using namespace std;

//Конструктор с параметрами
SalesPerson::SalesPerson(const char* firstname, const char* lastname, unsigned int age,
						 double sp_salary, double percent_for_sales, double sales_amount) :Employee(firstname, lastname, age)
{
	this->m_sp_salary = sp_salary;
	this->m_percent_for_sales = percent_for_sales;
	this->m_sales_amount = sales_amount;
}

//GetPayment
double SalesPerson::GetPayment()
{
	return m_sp_salary + m_percent_for_sales/100 * m_sales_amount;
}

//Вывод
void SalesPerson::Print()
{
	cout << "SalesPerson" << "\n";
	Employee::Print();
	cout << "1. SalesPerson's month salary = " << m_sp_salary << "\n";
	cout << "2. percent for total amount of sales = " << m_percent_for_sales << "\n";
	cout << "3. total amount of sales = " << m_sales_amount << "\n";
}

//Save
void SalesPerson::Save(const char filename[])
{
	Employee::Save(filename);

	ofstream f;
	f.open(filename, ios_base::app);
	if (f.is_open())
	{
		f << "Position - SalesPerson" << "\n";
		f << "1. SalesPerson's month salary = " << m_sp_salary << "\n";
		f << "2. percent for total amount of sales = " << m_percent_for_sales << "\n";
		f << "3. total amount of sales = " << m_sales_amount << "\n\n";
		f.close();
	}
	else
		cout << "Error opening file!" << "\n";
}