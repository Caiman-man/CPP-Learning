#pragma once

struct Contact
{
	int id;
	char name[32];
	char birth_date[16];
	char adress[256];
	char phone_number[32];
	char description[256];
};

void enter_contact(Contact& person, int& fill_book);
void print_contact(const Contact& person);
void add_contact(Contact* person, int& fill_book);
void delete_contact(Contact* person, int& fill_book);
void show_all_contacts(Contact* person, int& fill_book);
void find_contact_by_name(Contact* person, int& fill_book);
void find_contact_by_number(Contact* person, int& fill_book);
void change_contact(Contact* person, int& fill_book);
void save_phone_book(Contact* person, int& fill_book);
void load_phone_book(Contact* person, int& fill_book);
