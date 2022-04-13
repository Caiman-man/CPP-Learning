#include <iostream>
#include <fstream>
#include "Points.h"
using namespace std;

//Конструктор по умолчанию
Points::Points()
{
	this->m_x = 3;
	this->m_y = 4;
}

//Конструктор с параметрами
Points::Points(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

//Конструктор копирования
Points::Points(const Points& source) 
{
	cout << "Copy Constr \n";
	this->m_x = source.m_x;
	this->m_y = source.m_y;
}

//Оператор =
Points& Points::operator = (const Points& source)
{
	cout << "Operator = \n";
	if (m_x != source.m_x)
		this->m_x = source.m_x;
	if (m_y != source.m_y)
		this->m_y = source.m_y;
	return *this;
}

//Деструктор
Points::~Points()
{
	cout << "Destr " << m_x << "  " << m_y << "\n";
}

//Сохранение
void Points::Save(Points* pnt, const int& size, const char filepath[128])
{
	ofstream f1;
	f1.open(filepath);
	if (f1.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			f1 << pnt[i].m_x << "\n";
			f1 << pnt[i].m_y << "\n\n";
		}
		f1.close();
		cout << "The file saved successfully!" << "\n";
	}
	else
		throw "Error opening file!";
}

//Загрузка
void Points::Load(Points* pnt, const char filepath[128])
{
	int i = 0;
	ifstream f2;
	f2.open(filepath);
	if (f2.is_open())
	{
		while (!f2.eof())
		{
			(f2 >> pnt[i].m_x).get();
			(f2 >> pnt[i].m_y).get();
			i++;
		}
		f2.close();
		cout << "The file loaded successfully!" << "\n";
	}
	else
		throw "File doesn't exist!";
}

//Вывод
void Points::Print()
{
	cout << "x = "<< m_x << ", y = " << m_y << "\n";
}
