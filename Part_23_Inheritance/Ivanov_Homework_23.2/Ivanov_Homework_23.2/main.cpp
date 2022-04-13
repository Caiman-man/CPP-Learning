#include <iostream>
#include "Student.h"
using namespace std;

/*2. Разработать классы Person и Student, который наследует от Person.
	 В каждом классе реализовать по 4 поля и к ним геттеры и сеттеры и метод Print*/

void main()
{
	//1. Вызов конструктора с параметрами для обьекта person
	Person person("Alexander", "Ivanov", 29, 1.95);
	person.Print();

	//2. Изменение членов-переменных обьекта person с помощью сеттеров
	person.set_name("Rick");
	person.set_lastname("Sanches");
	person.set_age(61);
	person.set_height(1.77);
	cout << "\n";
	person.Print();

	//3. Использование геттеров для получения данных из закрытых полей класса
	char* r_firstname = person.get_name();
	char* r_lastname = person.get_lastname();
	int r_age = person.get_age();
	double r_height = person.get_height();
	cout << "\nRick's name: " << r_firstname << "\nRick's lastname: " << r_lastname << "\nRick's age: " << r_age << "\nRick's height: " << r_height << endl;
	cout << "---------------------------\n";


	//4. Вызов конструктора с параметрами для обьекта student
	cout << "\n";
	Student student("Alex", "Ivanovs", 30, 1.96, "SPD021", 6, 11, "100%");
	student.Print();

	//5. Изменение членов-переменных обьекта student с помощью сеттеров (в т.ч. сеттеров из класса Person)
	student.set_name("Bilbo");
	student.set_lastname("Baggins");
	student.set_age(60);
	student.set_height(1.55);
	student.set_group_name("C++");
	student.set_place_in_group(1);
	student.set_average_score(12);
	student.set_attendance("150%");
	cout << "\n";
	student.Print();

	//6. Использование геттеров для получения данных из закрытых полей класса
	char* b_firstname = student.get_name();
	char* b_lastname = student.get_lastname();
	int b_age = student.get_age();
	double b_height = student.get_height();
	char* b_group_name = student.get_group_name();
	int b_place_in_group = student.get_place_in_group();
	int b_average_score = student.get_average_score();
	char* b_attendance = student.get_attendance();
	cout << "\nBilbo's name: " << b_firstname << "\nBilbo's lastname: " << b_lastname << "\nBilbo's age: " << b_age << "\nBilbo's height: " << b_height;
	cout << "\nBilbo's group name: " << b_group_name << "\nBilbo's place in group: " << b_place_in_group << "\nBilbo's average score: " << b_average_score << "\nBilbo's attendance: " << b_attendance << endl;


}