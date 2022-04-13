#include <iostream>
#include "Student.h"
using namespace std;

//Конструктор с параметрами
Student::Student(const char name[24], const char lastname[24], int age, double height,
				 const char group_name[16], int place_in_group, int average_score, const char attendance[4]): Person(name, lastname, age, height)
{
	if (strlen(group_name) > 0 && place_in_group > 0 && place_in_group <= 14 && average_score >= 0 && average_score <= 12 && strlen(attendance) > 0)
	{
		strcpy(this->m_group_name, group_name);
		this->m_place_in_group = place_in_group;
		this->m_average_score = average_score;
		strcpy(this->m_attendance, attendance);
	}
	else
	{
		strcpy(this->m_group_name, "-");
		this->m_place_in_group = 0;
		this->m_average_score = 0;
		strcpy(this->m_attendance, "0%");
	}
}

//Сеттер / Геттер - Название группы
void Student::set_group_name(const char group_name[16])
{
	strcpy(this->m_group_name, group_name);
}

char* Student::get_group_name()
{
	return this->m_group_name;
}

//Сеттер / Геттер - Место в группе
void Student::set_place_in_group(int place_in_group)
{
	if (place_in_group > 0 && place_in_group <= 14)
	{
		this->m_place_in_group = place_in_group;
	}
}
int Student::get_place_in_group()
{
	return m_place_in_group;
}

//Сеттер / Геттер - Средний балл
void Student::set_average_score(int average_score)
{
	if (average_score >= 0 && average_score <= 12)
	{
		this->m_average_score = average_score;
	}
}
int Student::get_average_score()
{
	return m_average_score;
}

//Сеттер / Геттер - Посещаемость
void Student::set_attendance(const char attendance[4])
{
	strcpy(this->m_attendance, attendance);
}
char* Student::get_attendance()
{
	return this->m_attendance;
}


//Вывод
void Student::Print()
{
	Person::Print();
	cout << "Group name: " << m_group_name << "\nPlace in group: " << m_place_in_group << "\nAverage score: " << m_average_score << "\nAttendance: " << m_attendance << "\n";
}