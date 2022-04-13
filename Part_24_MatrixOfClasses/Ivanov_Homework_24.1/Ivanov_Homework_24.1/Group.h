#pragma once
#include "Student.h"
#include <vector>

class Group
{
protected:
	Student** m_students;

	//текущее количество студентов в группе
	size_t m_size;
	//максимальное количество студентов в группе
	size_t m_max_size;
	//число, на которое растёт массив студетов при его увеличении
	const size_t m_new_std_amount = 1;
private:
	void Check_size();
public:
	Group();
	Group(size_t max_size);
	Group(const Group& source);
	Group& operator = (const Group& source);
	~Group();

	void operator + (Student* st_source);
	void operator += (Student* st_source);
	void operator += (const Group& source);
	bool operator == (Group& source);
	bool operator >= (Group& source);
	Student* operator[](int pos);
	void Add(Student* st_source);
	void Print();

	void Save(const char filename[]);
};

