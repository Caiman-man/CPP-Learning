#include <iostream>
#include <fstream>
#include "Contact.h"
using namespace std;

//Добавить контакт
void add_contact(Contact* person, int& fill_book)
{
	enter_contact(person[fill_book], fill_book);
	fill_book++;
	system("pause");
}

//Удалить контакт
void delete_contact(Contact* person, int& fill_book)
{
	int id_delete;
	bool exist_name = false;

	cout << "Enter ID: ";
	cin >> id_delete;

	for (int i = 0; i < fill_book; i++)
	{
		if (person[i].id == id_delete)
		{
			print_contact(person[i]);
			for (int k = i; k < fill_book - 1; k++)
			{
				person[k] = person[k + 1];
			}
			i--;
			fill_book--;
			exist_name = true;
			cout << "Contact successfully deleted!" << "\n";
		}
	}
	if (exist_name == false) cout << "Contact doesn't exist!" << "\n";
	system("pause");
}

//Показать все контакты
void show_all_contacts(Contact* person, int& fill_book)
{
	system("cls");
	cout<< "Contact list: " << "\n";
	cout << "---------------------------" << "\n";
	for (int i = 0; i < fill_book; i++)
	{
		print_contact(person[i]);
	}
	cout<< "fill_book = " << fill_book << "\n";
	system("pause");
}

//Найти по имени
void find_contact_by_name(Contact* person, int& fill_book)
{
	char* name = new char[32];
	bool exist_name = false;
	cout << "\nEnter name: ";
	cin.ignore();
	cin.getline(name, 32);

	for (int i = 0; i < fill_book; i++)
	{
		if (strcmp(person[i].name, name) == 0)
		{
			print_contact(person[i]);
			exist_name = true;
		}
	}
	if (exist_name == false) cout << "Contact doesn't exist!" << "\n";
	delete[] name;
	system("pause");
}

//Найти по комеру телефона
void find_contact_by_number(Contact* person, int& fill_book)
{
	char* number = new char[32];
	bool exist_name = false;
	cout << "\nEnter phone number: ";
	cin.ignore();
	cin.getline(number, 32);

	for (int i = 0; i < fill_book; i++)
	{
		if (strcmp(person[i].phone_number, number) == 0)
		{
			print_contact(person[i]);
			exist_name = true;
		}
	}
	if (exist_name == false) cout << "Contact doesn't exist!" << "\n";
	delete[] number;
	system("pause");
}

//Изменить контакт
void change_contact(Contact* person, int& fill_book)
{
	int id_change;
	int submenu_index = 0;
	bool exist_name = false;

	cout << "Enter ID: ";
	cin >> id_change;

	for (int i = 0; i < fill_book; i++)
	{
		if (person[i].id == id_change)
		{
			print_contact(person[i]);
			exist_name = true;
			system("pause");
			do
			{
				system("cls");
				cout << "Change_contact menu:" << "\n";
				cout << "---------------------------" << "\n";
				cout << "1 - change birth date" << "\n";
				cout << "2 - change adress" "\n";
				cout << "3 - change phone number" << "\n";
				cout << "4 - change description" << "\n";
				cout << "5 - back to main menu" << "\n";

				cout << "Enter menu number:" << "\n";
				cin >> submenu_index;

				if (submenu_index <= 0 || submenu_index > 5)
				{
					cout << "Wrong menu number!" << "\n";
					system("pause");
				}
				else if (submenu_index == 1)
				{
					cin.ignore();
					cout << "Enter new birth date: ";
					cin.getline(person[i].birth_date, 16);
					cout << "Birth date was successfully changed!" << "\n";
					system("pause");
				}
				else if (submenu_index == 2)
				{
					cin.ignore();
					cout << "Enter new adress: ";
					cin.getline(person[i].adress, 256);
					cout << "Adress was successfully changed!" << "\n";
					system("pause");
				}
				else if (submenu_index == 3)
				{
					cin.ignore();
					cout << "Enter new phone number: ";
					cin.getline(person[i].phone_number, 32);
					cout << "Phone number was successfully changed!" << "\n";
					system("pause");
				}
				else if (submenu_index == 4)
				{
					cin.ignore();
					cout << "Enter new description: ";
					cin.getline(person[i].description, 256);
					cout << "Description was successfully changed!" << "\n";
					system("pause");
				}
			} while (submenu_index != 5);
		}
	}
	if (exist_name == false)
	{
		cout << "Contact doesn't exist!" << "\n";
		system("pause");
	}
}

//Сохранить телефонную книгу
void save_phone_book(Contact* person, int& fill_book)
{
	char* file_name = new char[16];
	cout << "\nEnter destination file name: ";
	cin.ignore();
	cin.getline(file_name, 16);
	strcat(file_name, ".txt");

	ofstream f1;
	f1.open(file_name);
	if (f1.is_open())
	{
		for (int i = 0; i < fill_book; i++)
		{
			f1 << person[i].id << "\n";
			f1 << person[i].name << "\n";
			f1 << person[i].birth_date << "\n";
			f1 << person[i].adress << "\n";
			f1 << person[i].phone_number << "\n";
			f1 << person[i].description << "\n\n";
		}
		f1.close();
		cout << "The book saved successfully!" << "\n";
	}
	else
		cout << "Error opening file!" << "\n";

	delete[] file_name;
	system("pause");
}

//Загрузить телефонную книгу
void load_phone_book(Contact* person, int& fill_book)
{
	//очищаю переменную для хранения кол-ва заполненных ячеек массива структур
	fill_book = 0;
	char* file_name = new char[32];
	cout << "\nEnter source file name: ";
	//для образца вводим имя файла - "load", который находится в папке с проектом
	cin.ignore();
	cin.getline(file_name, 32);
	strcat(file_name, ".txt");

	ifstream f2;
	f2.open(file_name);
	if (f2.is_open())
	{
		cin.ignore();
		while (!f2.eof())
		{
			(f2 >> person[fill_book].id).get();
			f2.getline(person[fill_book].name, 32);
			f2.getline(person[fill_book].birth_date, 16);
			f2.getline(person[fill_book].adress, 256);
			f2.getline(person[fill_book].phone_number, 32);
			f2.getline(person[fill_book].description, 256);
			fill_book++;
		}
		f2.close();
		cout << "The phone book loaded successfully!" << "\n";
	}
	else
		cout << "Error opening file!" << "\n";

	delete[] file_name;
	system("pause");
}

//Ввести контакт
void enter_contact(Contact& person, int& fill_book)
{
	cout << "Enter ID: ";
	cin >> person.id;
	cout << "Enter name: ";
	cin.ignore();
	cin.getline(person.name, 32);
	cout << "Enter birth date: ";
	cin.getline(person.birth_date, 16);
	cout << "Enter adress: ";
	cin.getline(person.adress, 256);
	cout << "Enter phone number: ";
	cin.getline(person.phone_number, 32);
	cout << "Enter description: ";
	cin.getline(person.description, 256);
	cout << "Successfully added! " << "\n\n";
}

//Показать контакт
void print_contact(const Contact& person)
{
	cout << "Contact ID: " << person.id << "\n";
	cout << "Contact name: " << person.name << "\n";
	cout << "Contact birth date: " << person.birth_date << "\n";
	cout << "Contact adress: " << person.adress << "\n";
	cout << "Contact phone number: " << person.phone_number << "\n";
	cout << "Contact description: " << person.description << "\n\n";
}