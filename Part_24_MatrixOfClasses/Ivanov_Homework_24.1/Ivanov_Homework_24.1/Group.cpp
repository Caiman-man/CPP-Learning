#include "Group.h"
#include <iostream>
#include <fstream>
using namespace std;

//����������� �� ���������
Group::Group()
{
	//cout << "Group constr" << endl;
	m_size = 0;
	m_max_size = 5;
	m_students = new Student * [m_max_size];
}


//����������� � �����������
Group::Group(size_t max_size)
{
	//cout << "Group constr" << endl;
	m_size = 0;
	m_max_size = max_size;
	m_students = new Student * [m_max_size];
}


//����������� �����������
Group::Group(const Group& source)
{
	cout << "Copy constr" << endl;
	this->m_size = source.m_size;
	this->m_max_size = source.m_max_size;
	m_students = new Student * [m_max_size];
	for (size_t i = 0; i < m_size; i++)
	{
		//������ ���-����� �������������� �������, �� ��������
		//�����, � ������� ����������, ��� ������� �� ��� � ������� ������ ��� �������, ������� ������� �� "source" � ������� ��������
		m_students[i] = new Student(source.m_students[i]->get_firstname(), 
									source.m_students[i]->get_lastname(), 
									source.m_students[i]->get_age(),
									source.m_students[i]->get_dormitory(), 
									source.m_students[i]->get_room_number(), 
									source.m_students[i]->get_avg_mark());
	}
}


//�������� =
Group& Group::operator = (const Group& source)
{
	cout << "Operator =" << endl;
	//���� ������� �� ���������, �� ������ ������
	if (m_max_size != source.m_max_size)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_students[i];
		}
		delete[] m_students;
	}

	//���������� ����� ������� � ������ ��������� �� ������ ���������� ������
	this->m_size = source.m_size;
	this->m_max_size = source.m_max_size;
	m_students = new Student * [m_max_size];

	//������� ������� � ������� ��������
	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i] = new Student(source.m_students[i]->get_firstname(), 
									source.m_students[i]->get_lastname(), 
									source.m_students[i]->get_age(),
									source.m_students[i]->get_dormitory(), 
									source.m_students[i]->get_room_number(), 
									source.m_students[i]->get_avg_mark());
	}
	return *this;
}


//����������
Group::~Group()
{
	//cout << "Group destr" << endl;
	for (size_t i = 0; i < m_size; i++)
	{
		delete m_students[i];
	}
	delete[] m_students;
}


//�������� +
void Group::operator + (Student* st_source)
{
	if (m_size >= m_max_size)
		throw "Array is full!!!";
	m_students[m_size] = st_source;
	m_size++;
}


//�������� += student
void Group::operator += (Student* st_source)
{
	Check_size();
	m_students[m_size] = st_source;
	m_size++;
}


//�������� += group (�� ��������, �� ��������� ������ ������)
void Group::operator += (const Group& source)
{
	//������ ��������� ��������� �� ������ ���������� (� ����� ��������)
	Student** temp_students = new Student * [m_max_size + source.m_max_size];

	//������� � ����� ������ ��������� �� ������ ������
	for (size_t i = 0; i < m_size; i++)
	{
		temp_students[i] = m_students[i];
	}
	//��������� �����������, (������� � ����� ������ ��������� �� ������ ������)
	for (size_t i = m_size, k = 0; k < source.m_size; i++, k++)
	{
		temp_students[i] = source.m_students[k];
	}

	delete[] m_students;
	m_students = temp_students;
	m_max_size = m_max_size + source.m_max_size;
}

//�������� ==
bool Group::operator == (Group& source)
{
	if (m_size != source.m_size || m_max_size != source.m_max_size) return false;
	else
	{
		for (size_t i = 0; i < m_size; i++)
		{
			//��������� ������ ������, ��������� ������� ��� ������� � �����
			if ((m_students[i]->get_firstname(),
				m_students[i]->get_lastname(),
				m_students[i]->get_age(),
				m_students[i]->get_dormitory(),
				m_students[i]->get_room_number(),
				m_students[i]->get_avg_mark())
				!= (source.m_students[i]->get_firstname(),
					source.m_students[i]->get_lastname(),
					source.m_students[i]->get_age(),
					source.m_students[i]->get_dormitory(),
					source.m_students[i]->get_room_number(),
					source.m_students[i]->get_avg_mark()))
			{
				return false;
			}
		}
		return true;
	}
}


//�������� >=
bool Group::operator >= (Group& source)
{
	//��������� �������
	if (m_size < source.m_size || m_max_size < source.m_max_size) return false;
	else
	{
		return true;
	}
}


//�������� []
Student* Group::operator[](int pos)
{
	if (pos >= 0 && pos < m_size)
	{
		return m_students[pos];
	}
	else return 0;
}


//����� Add
void Group::Add(Student* st_source)
{
	Check_size();
	m_students[m_size] = st_source;
	m_size++;
}


//�������� �� ������� ���������� ����� � ������������ ������� ���������, ���� ��� �����
void Group::Check_size()
{
	// ���� ������ ��������� ��������� � ����������
	if (m_size >= m_max_size)
	{
		//cout << "CheckSize add memory" << endl;
		Student** new_students = new Student * [m_max_size + m_new_std_amount];
		for (size_t i = 0; i < m_size; i++)
		{
			new_students[i] = m_students[i];
		}
		delete[] m_students;
		m_students = new_students;
		m_max_size += m_new_std_amount;
	}
}

//Save
void Group::Save(const char filename[])
{
	ofstream f1;
	f1.open(filename);
	if (f1.is_open())
	{
		for (int i = 0; i < m_size; i++)
		{
			 f1 << m_students[i]->get_firstname() << ", " 
				<< m_students[i]->get_lastname() << ", " 
				<< m_students[i]->get_age() << ", " 
				<< m_students[i]->get_dormitory() << ", " 
				<< m_students[i]->get_room_number() << ", " 
				<< m_students[i]->get_avg_mark();
			f1 << "\n";
		}
		f1.close();
		cout << "File saved successfully!" << endl;
	}
	else
		cout << "Error opening file!" << endl;
}

//�����
void Group::Print()
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i]->Print();
	}
}
