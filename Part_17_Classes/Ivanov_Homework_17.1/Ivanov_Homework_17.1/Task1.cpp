#include <iostream>
#include "Person.h"
using namespace std;

/*1. Разработать класс Person, который содержит следующие члены класса:
	 - минимум 5 полей								
	 - конструктор без параметров					
	 - конструктор с параметрами					
	 - print() - печать на экран				
	 - сеттеры / геттеры для доступа к полям*/


void main()
{
	//Вызов конструктора с параметрами
	Person student("Alexander", "Ivanov", 29, 1.95, 98.5);
	student.Print();
	//изменение членов-переменных обьекта student с помощью сеттеров
	student.set_Name("Rick");
	student.set_LastName("Sanches");
	student.set_Age(30);
	student.set_Height(1.97);
	student.set_Weight(99.4);
	student.Print();
	cout <<"---------------------------"<<endl;

	//Вызов конструктора по умолчанию
	Person man;
	man.Print();
	//изменение членов-переменных обьекта man с помощью сеттеров
	man.set_Name("Bilbo");
	man.set_LastName("Beggins");
	man.set_Age(60);
	man.set_Height(1.55);
	man.set_Weight(69.5);
	man.Print();

	//использование геттеров для получения данных из закрытых полей класса
	char *b_firstname = man.get_Name();
	char *b_lastname = man.get_LastName();
	int b_age = man.get_Age();
	double b_height = man.get_Height();
	double b_weight = man.get_Weight();
	cout << "---------------------------" << endl;
	cout << "Bilbo's name: " << b_firstname << "\nBilbo's lastname: " << b_lastname << "\nBilbo's age: " << b_age << "\nBilbo's height: " << b_height << "\nBilbo's weight: " << b_weight << endl;
}