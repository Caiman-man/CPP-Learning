#include "Student.h"
#include <iostream>
using namespace std;

//Конструктор по умолчанию
Student::Student() : Person("First", "Last", 20)
{
    //cout << "Default student constr" << endl;
    this->m_dormitory = new char[strlen("Dormitory") + 1];
    strcpy(this->m_dormitory, "Dormitory");
    this->m_room_number = 100;
    this->m_avg_mark = 4.9;
}

//Конструктор с параметрами
Student::Student(const char* firstname, const char* lastname, unsigned int age,
                 const char* dormitory, unsigned int room_number, double avg_mark) :Person(firstname, lastname, age)
{
    //cout << "Params student constr" << endl;
    this->m_dormitory = new char[strlen(dormitory) + 1];
    strcpy(this->m_dormitory, dormitory);
    this->m_room_number = room_number;
    this->m_avg_mark = avg_mark;
}

//Конструктор копирования
Student::Student(const Student& source) :Person(source)
{
    //cout << "Copy student constr" << endl;
    this->m_dormitory = new char[strlen(source.m_dormitory) + 1];
    strcpy(this->m_dormitory, source.m_dormitory);
    this->m_room_number = source.m_room_number;
    this->m_avg_mark = source.m_avg_mark;
}

//Оператор =
Student& Student::operator= (Student& source)
{
    //cout << "Student operator =" << endl;
    if (m_firstname != nullptr) delete[] m_firstname;
    m_firstname = new char[strlen(source.m_firstname) + 1];
    strcpy(this->m_firstname, source.m_firstname);

    if (m_lastname != nullptr) delete[] m_lastname;
    m_lastname = new char[strlen(source.m_lastname) + 1];
    strcpy(this->m_lastname, source.m_lastname);

    if (m_age != source.m_age)
        this->m_age = source.m_age;

    if (m_dormitory != nullptr) delete[] m_dormitory;
    m_dormitory = new char[strlen(source.m_dormitory) + 1];
    strcpy(this->m_dormitory, source.m_dormitory);

    if (m_room_number != source.m_room_number)
        this->m_room_number = source.m_room_number;
    if (m_avg_mark != source.m_avg_mark)
        this->m_avg_mark = source.m_avg_mark;

    return *this;
}

//Деструктор
Student::~Student()
{
    //cout << "Student destr" << endl;
    delete[] m_dormitory;
}

//Вывод
void Student::Print()
{
    Person::Print();
    cout << "Address: " << m_dormitory << ", Room number: " << m_room_number << ", Average mark: " << m_avg_mark << "\n";
}

//Геттеры
char* Student::get_dormitory()
{
    return this->m_dormitory;
}

unsigned int Student::get_room_number()
{
    return m_room_number;
}

double Student::get_avg_mark()
{
    return m_avg_mark;
}