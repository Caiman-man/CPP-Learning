#pragma once
class Vector
{
private:
	int v[5];
public:
	//Конструктор без параметров
	Vector();

	//Конструктор с параметрами
	Vector(int n);

	//Сеттеры / Геттеры для доступа к полям
	void set_Number(int index, int n);
	int get_Number(int index);

	//Вывод на экран
	void Print();
};

