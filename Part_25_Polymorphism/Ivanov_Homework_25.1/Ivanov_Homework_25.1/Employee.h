#pragma once
class Employee
{
protected:
	char* m_firstname;
	char* m_lastname;
	unsigned int m_age;
public:
	Employee(const char* firstname, const char* lastname, unsigned int age);
	~Employee();
	virtual double GetPayment();
	virtual void Print();
	virtual void Save(const char filename[]);
};

