#include <iostream>
#include <fstream>
#include "Contact.h"
using namespace std;

/*	–азработать программу "“елефонна€ книга", котора€ позвол€ет хранить следующую информацию о контактах человека:
	Х номер
	Х ‘»ќ (им€)
	Х дата рождени€
	Х адрес
	Х телефон
	Х текстовое описание контакта

	ѕрограмма должна использовать динамический массив структур дл€ хранени€ телефонной книги.
	ѕрограмма имеет меню, в котором есть следующие функции:
	Х добавить контакт														
	Х удалить контакт														
	Х просмотр всех контактов												
	Х поиск по имени														
	Х поиск по телефону														
	Х изменить контакт(помен€ть телефон, адрес, описание, дату рождени€)	
	Х сохранить телефонную книгу в файл										
	Х загрузить телефонную книгу из файла									
	Х выход*/

void main()
{
	Contact* phone_book = new Contact[124];
	int menu_index = 0;

	//переменна€ дл€ хранени€ кол-ва заполненных €чеек массива структур
	int fill_book = 0;

	do
	{
		system("cls");
		cout << "Phone_Book menu:" << "\n";
		cout << "---------------------------" << "\n";
		cout << "1 - add contact" << "\n";
		cout << "2 - delete contact" "\n";
		cout << "3 - show all contacts" << "\n";
		cout << "4 - find contact by name" << "\n";
		cout << "5 - find contact by number" << "\n";
		cout << "6 - change contact" << "\n";
		cout << "7 - save phone book" << "\n";
		cout << "8 - load phone book" << "\n";
		cout << "9 - exit" << "\n";
		cout << "---------------------------" << "\n";
		cout << "Enter menu number:" << "\n";
		cin >> menu_index;

		if (menu_index <= 0 || menu_index > 9)
		{
			cout << "Wrong menu number!" << "\n";
			system("pause");
		}
		else if (menu_index == 1) add_contact(phone_book, fill_book);
		else if (menu_index == 2) delete_contact(phone_book, fill_book);
		else if (menu_index == 3) show_all_contacts(phone_book, fill_book);
		else if (menu_index == 4) find_contact_by_name(phone_book, fill_book);
		else if (menu_index == 5) find_contact_by_number(phone_book, fill_book);
		else if (menu_index == 6) change_contact(phone_book, fill_book);
		else if (menu_index == 7) save_phone_book(phone_book, fill_book);
		else if (menu_index == 8) load_phone_book(phone_book, fill_book);
	} while (menu_index != 9);

	delete[] phone_book;
}