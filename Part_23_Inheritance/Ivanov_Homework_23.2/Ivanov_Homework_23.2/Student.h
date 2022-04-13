#pragma once
#include "Person.h"

class Student: public Person
{
	char m_group_name[16];
	int m_place_in_group;
	int m_average_score;
	char m_attendance[4];
public:
	Student(const char name[24], const char lastname[24], int age, double height, 
			const char group_name[16], int place_in_group, int average_score, const char attendance[4]);
	void Print();

	void set_group_name(const char group_name[16]);
	char* get_group_name();

	void set_place_in_group(int place_in_group);
	int get_place_in_group();

	void set_average_score(int average_score);
	int get_average_score();

	void set_attendance(const char attendance[4]);
	char* get_attendance();

};

