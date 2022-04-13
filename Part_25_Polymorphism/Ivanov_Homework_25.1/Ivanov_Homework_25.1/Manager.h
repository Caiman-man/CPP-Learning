#pragma once
#include "Employee.h"
class Manager : public Employee
{
	//����� �� �����
	double m_manager_salary;
	//�������������� ����� �� ������ ����������� �����
	double m_pay_by_orders;
	//���-�� �������
	unsigned int m_amount_of_orders;
public:
	Manager(const char* firstname, const char* lastname, unsigned int age,
			double manager_salary, double pay_by_orders, unsigned int amount_of_orders);
	double GetPayment();
	void Print();
	void Save(const char filename[]);
};

