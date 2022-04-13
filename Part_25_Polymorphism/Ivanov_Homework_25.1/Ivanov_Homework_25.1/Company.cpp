#include "Company.h"
#include <iostream>
using namespace std;

//Конструктор с параметрами
Company::Company(size_t max_size)
{
	this->m_max_size = max_size;
	m_size = 0;
	m_employees = new Employee * [m_max_size];
}

//Деструктор
Company::~Company()
{
	for (size_t i = 0; i < m_size; i++)
	{
		delete m_employees[i];
	}
	delete[] m_employees;
}

//Метод Add
void Company::Add(Employee* empl_source)
{
	if (m_size < m_max_size)
		m_employees[m_size++] = empl_source;
}

//GetPayment
double Company::GetPayment()
{
	double payment = 0;
	for (size_t i = 0; i < m_size; i++)
	{
		payment += m_employees[i]->GetPayment();
	}
	return payment;
}

//Вывод
void Company::Print()
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_employees[i]->Print();
		cout << endl;
	}
}

//Save
void Company::Save(const char filename[])
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_employees[i]->Save(filename);
	}
}

