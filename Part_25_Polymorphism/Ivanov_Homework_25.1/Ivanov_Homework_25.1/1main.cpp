#include <iostream>
#include "Company.h"
#include "Worker.h"
#include "Manager.h"
#include "Freelancer.h"
#include "SalesPerson.h"
using namespace std;

/*1. Разработать класс Company, который содержит динамический массив сотрудников:
	 - Employee - базовый класс сотрудников								
	 - Worker - рабочий													
	 - Manager - менеджер в компании									
	 - Freelancer - внештатный сотрудник								
	 - SalesPerson - продажник											
  2. Для всех дочерних классов придумать подходящие им поля				
  3. Сделать методы класса Company, которые используют полиморфизм:		
	 - GetPayment() - подсчитывает общую ЗП по компании					
	 - Print() - вывести список сотрудников								
	 - Save() - сохранить всех сотрудников в файл*/

void main()
{
	Company* comp = new Company(5);
	comp->Add(new Worker("Aleksey", "Orlov", 29, 750.5, 26));
	comp->Add(new Manager("Dmitriy", "Boiko", 24, 10000, 150.5, 70));
	comp->Add(new Freelancer("Andrey", "Volkov", 33, 500, 24));
	comp->Add(new SalesPerson("Maria", "Borodina", 35, 7000, 20.6, 124000));

	comp->Print();
	comp->Save("result.txt");
	cout << "Total salary = " << comp->GetPayment() <<" rub."<< endl;

	delete comp;
}