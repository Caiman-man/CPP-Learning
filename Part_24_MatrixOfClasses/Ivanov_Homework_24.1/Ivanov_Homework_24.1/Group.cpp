#include "Group.h"
#include <iostream>
#include <fstream>
using namespace std;

//Конструктор по умолчанию
Group::Group()
{
	//cout << "Group constr" << endl;
	m_size = 0;
	m_max_size = 5;
	m_students = new Student * [m_max_size];
}


//Конструктор с параметрами
Group::Group(size_t max_size)
{
	//cout << "Group constr" << endl;
	m_size = 0;
	m_max_size = max_size;
	m_students = new Student * [m_max_size];
}


//Конструктор копирования
Group::Group(const Group& source)
{
	cout << "Copy constr" << endl;
	this->m_size = source.m_size;
	this->m_max_size = source.m_max_size;
	m_students = new Student * [m_max_size];
	for (size_t i = 0; i < m_size; i++)
	{
		//строка все-равно подчеркивается зеленым, но работает
		//здесь, в массиве указателей, для каждого из них я выделяю память под обьекты, которые копирую из "source" с помощью геттеров
		m_students[i] = new Student(source.m_students[i]->get_firstname(), 
									source.m_students[i]->get_lastname(), 
									source.m_students[i]->get_age(),
									source.m_students[i]->get_dormitory(), 
									source.m_students[i]->get_room_number(), 
									source.m_students[i]->get_avg_mark());
	}
}


//Оператор =
Group& Group::operator = (const Group& source)
{
	cout << "Operator =" << endl;
	//если размеры не совпадают, то очищаю память
	if (m_max_size != source.m_max_size)
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_students[i];
		}
		delete[] m_students;
	}

	//присваиваю новые значени и создаю указатель на массив указателей заново
	this->m_size = source.m_size;
	this->m_max_size = source.m_max_size;
	m_students = new Student * [m_max_size];

	//копирую обьекты с помощью геттеров
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


//Деструктор
Group::~Group()
{
	//cout << "Group destr" << endl;
	for (size_t i = 0; i < m_size; i++)
	{
		delete m_students[i];
	}
	delete[] m_students;
}


//Оператор +
void Group::operator + (Student* st_source)
{
	if (m_size >= m_max_size)
		throw "Array is full!!!";
	m_students[m_size] = st_source;
	m_size++;
}


//Оператор += student
void Group::operator += (Student* st_source)
{
	Check_size();
	m_students[m_size] = st_source;
	m_size++;
}


//Оператор += group (Не работает, не добавляет вторую группу)
void Group::operator += (const Group& source)
{
	//создаю временный указатель на массив указателей (с новым размером)
	Student** temp_students = new Student * [m_max_size + source.m_max_size];

	//копирую в новый массив указатели из первой группы
	for (size_t i = 0; i < m_size; i++)
	{
		temp_students[i] = m_students[i];
	}
	//продолжаю копирование, (копирую в новый массив указатели из второй группы)
	for (size_t i = m_size, k = 0; k < source.m_size; i++, k++)
	{
		temp_students[i] = source.m_students[k];
	}

	delete[] m_students;
	m_students = temp_students;
	m_max_size = m_max_size + source.m_max_size;
}

//Оператор ==
bool Group::operator == (Group& source)
{
	if (m_size != source.m_size || m_max_size != source.m_max_size) return false;
	else
	{
		for (size_t i = 0; i < m_size; i++)
		{
			//сравниваю каждый обьект, используя геттеры для доступа к полям
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


//Оператор >=
bool Group::operator >= (Group& source)
{
	//сравниваю размеры
	if (m_size < source.m_size || m_max_size < source.m_max_size) return false;
	else
	{
		return true;
	}
}


//Оператор []
Student* Group::operator[](int pos)
{
	if (pos >= 0 && pos < m_size)
	{
		return m_students[pos];
	}
	else return 0;
}


//Метод Add
void Group::Add(Student* st_source)
{
	Check_size();
	m_students[m_size] = st_source;
	m_size++;
}


//Проверка на наличие свободного места и пересоздание массива студентов, если это нужно
void Group::Check_size()
{
	// если массив студентов нуждается в увеличении
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

//Вывод
void Group::Print()
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_students[i]->Print();
	}
}
