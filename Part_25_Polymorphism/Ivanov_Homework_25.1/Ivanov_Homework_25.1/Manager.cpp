#include "Manager.h"
#include <fstream>
#include <iostream>
using namespace std;

//Конструктор с параметрами
Manager::Manager(const char* firstname, const char* lastname, unsigned int age,
				 double manager_salary, double pay_by_orders, unsigned int amount_of_orders) :Employee(firstname, lastname, age)
{
	this->m_manager_salary = manager_salary;
	this->m_pay_by_orders = pay_by_orders;
	this->m_amount_of_orders = amount_of_orders;
}

//GetPayment
double Manager::GetPayment()
{
	return m_manager_salary + m_pay_by_orders * m_amount_of_orders;
}

//Вывод
void Manager::Print()
{
	cout << "Manager" << "\n";
	Employee::Print();
	cout << "1. Manager's month salary = " << m_manager_salary << "\n";
	cout << "2. payment for each order = " << m_pay_by_orders << "\n";
	cout << "3. amount of orders = " << m_amount_of_orders << "\n";
}

//Save
void Manager::Save(const char filename[])
{
	Employee::Save(filename);

	ofstream f;
	f.open(filename, ios_base::app);
	if (f.is_open())
	{
		f << "Position - Manager" << "\n";
		f << "1. Manager's month salary = " << m_manager_salary << "\n";
		f << "2. payment for each order = " << m_pay_by_orders << "\n";
		f << "3. amount of orders = " << m_amount_of_orders << "\n\n";
		f.close();
	}
	else
		cout << "Error opening file!" << "\n";
}