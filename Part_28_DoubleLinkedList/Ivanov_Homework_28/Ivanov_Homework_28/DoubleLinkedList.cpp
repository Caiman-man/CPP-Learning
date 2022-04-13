#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

//Конструктор по умолчанию
DoubleLinkedList::DoubleLinkedList()
{
	m_first = m_last = nullptr;
	m_count = 0;
}


//Конструктор копирования 
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& source)
{
	m_first = m_last = nullptr;
	m_count = 0;

	Element* current = source.m_first;
	while (current != nullptr)
	{
		Add(current->m_str);
		current = current->m_next;
	}
}


//оператор = 
DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList& source)
{
	// удаление старых элементов списка
	Element* current = m_first;
	while (current != nullptr)
	{
		Element* temp = current;
		current = current->m_next;
		delete temp;
	}

	m_first = m_last = nullptr;

	// добавление новых элементов
	current = source.m_first;
	while (current != nullptr)
	{
		Add(current->m_str);
		current = current->m_next;
	}
	return *this;
}


//Деструктор
DoubleLinkedList::~DoubleLinkedList()
{
	Element* current = m_first;
	while (current != nullptr)
	{
		Element* temp = current;
		current = current->m_next;
		delete temp;
	}
}


//Add
void DoubleLinkedList::Add(const char* str)
{
	if (m_first == nullptr)
	{
		m_first = m_last = new Element(str, 0, 0);
	}
	else
	{
		Element* elem = new Element(str, 0, 0);
		elem->m_prev = m_last;
		m_last->m_next = elem;
		elem->m_next = nullptr;
		m_last = elem;
	}
	m_count++;
}


//AddFirst
void DoubleLinkedList::AddFirst(const char* str)
{
	if (m_first == nullptr)
	{
		m_first = m_last = new Element(str, 0, 0);
	}
	else
	{
		Element* elem = new Element(str, 0, 0);
		elem->m_prev = nullptr;
		elem->m_next = m_first;
		m_first->m_prev = elem;
		m_first = elem;
	}
	m_count++;
}


//Find - находит первое вхождение элемента списка по значению
Element* DoubleLinkedList::Find(const char* str)
{
	Element* current = m_first;
	bool find = true;
	while (current != nullptr)
	{
		if (strcmp(current->m_str, str) == 0)
			return current;
		else
			find = false;

		current = current->m_next;
	}
	if (find == false)
		throw exception("String dosn't exist!");
}


//Clear - очищает все элементы списка
void DoubleLinkedList::Clear()
{
	while (m_first != nullptr)
	{
		Element* temp = m_first;
		m_first = m_first->m_next;
		delete temp;
	}
	m_count = 0;
	cout << "List cleared successfully!" << endl;
}


//Insert - вставляет элемент перед элементом с указанным индексом
void DoubleLinkedList::Insert(const char* str, size_t index)
{
	if (index >= 0 && index < m_count)
	{
		// создать новый элемент списка
		Element* elem = new Element(str, 0, 0);
		//если новый элемент необходимо вставить перед первым элементом
		if (index == 0)
		{
			elem->m_prev = nullptr;
			elem->m_next = m_first;
			m_first->m_prev = elem;
			m_first = elem;
			m_count++;
			return;
		}

		Element* current = m_first;
		Element* previous = nullptr;
		size_t n = 0;

		while (current != nullptr)
		{
			if (index == n + 1)
			{
				previous = current;
				current = current->m_next;
				break;
			}
			current = current->m_next;
			n++;
		}
		//настройка связей между новым элементом и существующими
		previous->m_next = elem;
		elem->m_prev = previous;
		elem->m_next = current;
		current->m_prev = elem;
		m_count++;
	}
	else throw exception("Attemp to insert to empty list!");
}


//Delete - удаление элемента по индексу 
void DoubleLinkedList::Delete(size_t index)
{
	Element* current = m_first;
	size_t n = 0;

	if (index >= 0 && index < m_count)
	{
		//если список пуст
		if (m_first == nullptr)
		{
			throw exception("List is empty!");
		}
		//если позиция - первая
		if (index == 0)
		{
			m_first = m_first->m_next;
			m_first->m_prev = nullptr;
			delete current;
			m_count--;
			return;
		}
		//если позиция - последняя
		else if (index == m_count - 1)
		{
			current = m_last;
			m_last = m_last->m_prev;
			m_last->m_next = nullptr;
			delete current;
			m_count--;
			return;
		}
		while (current != nullptr)
		{
			if (index == n + 1)
			{
				current = current->m_next;
				break;
			}
			current = current->m_next;
			n++;
		}

		//настройка связей между элементами
		current->m_next->m_prev = current->m_prev;
		current->m_prev->m_next = current->m_next;
		delete current;
		m_count--;
	}
	else
		throw exception("Wrong index!");
}


//DeleteAll - удаление всех вхождений строки в список
size_t DoubleLinkedList::DeleteAll(const char* str)
{
	size_t deletedElementsCount = 0;

	// если список не пуст
	if (m_first != nullptr)
	{
		Element* current = m_first;

		// цикл по элементам списка
		while (current != nullptr)
		{
			// если найден элемент, который надо удалить
			if (strcmp(current->m_str, str) == 0)
			{
				// если удаляется первый элемент
				if (current == m_first)
				{
					Element* tmp = m_first;
					m_first = m_first->m_next;
					m_first->m_prev = nullptr;
					delete tmp;
					deletedElementsCount++;
					m_count--;
					// если после удаления в списке не осталось элементов
					if (m_first == nullptr)
						return deletedElementsCount;
					else current = m_first;
				}
				// если удаляется послдений элемент
				else if (current == m_last)
				{
					Element* tmp = m_last;
					m_last = m_last->m_prev;
					m_last->m_next = nullptr;
					delete tmp;
					deletedElementsCount++;
					m_count--;
					// если после удаления в списке не осталось элементов
					if (m_last == nullptr)
						return deletedElementsCount;
					else current = m_last;
				}
				// если удаляется не первый элемент
				else 
				{
					Element* temp = current;
					current = current->m_next;
					//настроить связи
					temp->m_next->m_prev = temp->m_prev;
					temp->m_prev->m_next = temp->m_next;
					delete temp;
					deletedElementsCount++;
					m_count--;
					// если после удаления в списке не осталось элементов
					if (current == nullptr)
						return deletedElementsCount;
				}
			}
			else // если элемент удалять не надо, то перепрыгнуть на следующий
			{
				current = current->m_next;
			}
		}
		// весь список просмотрен, возвратить количество удалённых элементов
		return deletedElementsCount;
	}
	else return 0;
}


//Save
void DoubleLinkedList::Save(const char filename[])
{
	fstream file(filename, ios::out | ios::binary);
	if (!file.fail())
	{
		if (m_first == nullptr)
			cout << "LIST IS EMPTY!\n";

		Element* current = m_first;
		while (current != nullptr)
		{
			//вычисляю размер строки для метода 'write'
			long size = strlen(current->m_str);
			//записываю строку в файл, затем записываю переход на новую строку
			file.write((char*)(current->m_str), size);
			file.write((char*)"\n", 1);
			current = current->m_next;
		}
		file.close();
		cout << "The file saved successfully!\n";
	}
	else
		cout << "Error opening file!\n";
}


//Load
DoubleLinkedList& DoubleLinkedList::Load(const char filename[])
{
	char buffer[128];
	fstream file;
	file.open(filename, ios::in);
	if (!file.fail())
	{
		while (!file.eof())
		{
			// чтение файла построчно
			file.getline(buffer, 128);
			//вызов метода Add для создания элементов и добавления считанных строк в них
			Add(buffer);
		}
		file.close();
		cout << "The file loaded successfully!\n";
	}
	else
		cout << "Error opening file!\n";
	return *this;
}


//GetCount - кол-во вхождений указанной строки
size_t DoubleLinkedList::GetCount(const char* str)
{
	size_t result = 0;
	Element* current = m_first;
	while (current != nullptr)
	{
		if (strcmp(current->m_str, str) == 0)
			result++;
		current = current->m_next;
	}
	return result;
}


//оператор [] 
char*& DoubleLinkedList::operator[] (int pos)
{
	int n = 0;
	Element* current = m_first;
	while (current != nullptr)
	{
		if (pos == n)
			return current->m_str;
		current = current->m_next;
		n++;
	}
	throw exception("Incorrect index!");
}


//operator ==
bool DoubleLinkedList::operator == (DoubleLinkedList& source)
{
	Element* current = m_first;
	Element* current2 = source.m_first;

	//если кол-во элементов исходного списка не совпадает со сравниваемым
	if (m_count != source.m_count)
		return false;
	//если совпадает, то проверяем каждый элемент
	else
	{
		while (current != nullptr)
		{
			if (strcmp(current->m_str, current2->m_str) != 0)
				return false;
			current = current->m_next;
			current2 = current2->m_next;
		}
		return true;
	}
}


//operator +	добавление элемента в конец списка
void DoubleLinkedList::operator+ (const char* str)
{
	Add(str);
}


//operator +	добавление списка в конец списка
DoubleLinkedList& DoubleLinkedList::operator+ (DoubleLinkedList& source)
{
	//создаю еще один (результирующий) список
	DoubleLinkedList* result = new DoubleLinkedList();
	Element* current = m_first;

	//копирую элементы из первого списка в результирующий
	while (current != nullptr)
	{
		result->Add(current->m_str);
		current = current->m_next;
	}
	//перемещаю указатель на второй список, и продолжаю копировать элементы уже из 2го списка
	current = source.m_first;
	while (current != nullptr)
	{
		result->Add(current->m_str);
		current = current->m_next;
	}

	return *result;
}


//operator +=	добавление списка в конец списка
DoubleLinkedList& DoubleLinkedList::operator+= (DoubleLinkedList& source)
{
	//ставлю указатель на 2й список
	Element* current = source.m_first;
	while (current != nullptr)
	{
		//добавляю методом Add элементы 2го списка в конец 1го
		Add(current->m_str);
		current = current->m_next;
	}
	return *this;
}


//Вывод
void DoubleLinkedList::Print()
{
	if (m_first == nullptr)
		cout << "LIST IS EMPTY!\n";

	Element* current = m_first;
	while (current != nullptr)
	{
		cout << current->m_str << "\t" << current << endl;
		current = current->m_next;
	}
	//cout << "m_count = " << m_count << endl;
}


//Реверсивный вывод
void DoubleLinkedList::PrintBack()
{
	if (m_first == nullptr)
		cout << "LIST IS EMPTY!\n";

	Element* current = m_last;
	while (current != nullptr)
	{
		cout << current->m_str << "\t" << current << endl;
		current = current->m_prev;
	}
	//cout << "m_count = " << m_count << endl;
}