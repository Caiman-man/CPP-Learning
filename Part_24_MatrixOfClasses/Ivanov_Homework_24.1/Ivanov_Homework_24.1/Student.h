#pragma once
#include "Person.h"

class Student: public Person
{
protected:
	char* m_dormitory;
	unsigned int m_room_number;
	double m_avg_mark;
public:
	Student();
	Student(const char* firstname, const char* lastname, unsigned int age, const char* dormitory, unsigned int room_number, double avg_mark);
	Student(const Student& source);
	Student& operator= (Student& source);
	~Student();
	void Print();

	char* get_dormitory();
	unsigned int get_room_number();
	double get_avg_mark();
};

