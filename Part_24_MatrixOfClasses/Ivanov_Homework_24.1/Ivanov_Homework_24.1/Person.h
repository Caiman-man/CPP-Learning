#pragma once
class Person
{
protected:
	char* m_firstname;
	char* m_lastname;
	unsigned int m_age;
public:
	Person(const char* firstname, const char* lastname, unsigned int age);
	Person(const Person& source);
	~Person();
	void Print();

	char* get_firstname();
	char* get_lastname();
	unsigned int get_age();
};

