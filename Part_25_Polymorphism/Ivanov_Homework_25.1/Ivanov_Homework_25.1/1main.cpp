#include <iostream>
#include "Company.h"
#include "Worker.h"
#include "Manager.h"
#include "Freelancer.h"
#include "SalesPerson.h"
using namespace std;

/*1. ����������� ����� Company, ������� �������� ������������ ������ �����������:
	 - Employee - ������� ����� �����������								
	 - Worker - �������													
	 - Manager - �������� � ��������									
	 - Freelancer - ���������� ���������								
	 - SalesPerson - ���������											
  2. ��� ���� �������� ������� ��������� ���������� �� ����				
  3. ������� ������ ������ Company, ������� ���������� �����������:		
	 - GetPayment() - ������������ ����� �� �� ��������					
	 - Print() - ������� ������ �����������								
	 - Save() - ��������� ���� ����������� � ����*/

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