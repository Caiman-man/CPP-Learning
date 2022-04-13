#include <iostream>
#include "Vector.h"
using namespace std;

//Конструктор без параметров (массив по умолчанию заполняется нулями)
Vector::Vector()
{
	for (int i = 0; i < 5; i++)
	{
		this->v[i] = 0;
	}
}

//Конструктор с параметрами
Vector::Vector(int n)
{
	for (int i = 0; i < 5; i++)
	{
		this->v[i] = n;
	}
}

//Сеттеры / Геттеры для доступа к полям
void Vector::set_Number(int index, int n)
{
	if (index < 5) this->v[index] = n;
	else cout << "Error index" << endl;
}

int Vector::get_Number(int index)
{
	return v[index];
}

//Вывод на экран
void Vector::Print()
{
	for (int i = 0; i < 5; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}