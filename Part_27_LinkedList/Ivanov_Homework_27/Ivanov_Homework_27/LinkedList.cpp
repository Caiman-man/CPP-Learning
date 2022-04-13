#include <iostream>
#include "LinkedList.h"
using namespace std;

//Конструктор по умолчанию
LinkedList::LinkedList()
{
	m_first = m_last = nullptr;
	m_count = 0;
}


//Конструктор копирования
LinkedList::LinkedList(const LinkedList& source)
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
LinkedList& LinkedList::operator= (LinkedList& source)
{
	// удаление старых элементов списка
	Element* current = m_first;
	while (current != nullptr)
	{
		Element* temp = current;
		// "перепрыгнуть" на следующий элемент списка
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
LinkedList::~LinkedList()
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
void LinkedList::Add(const char* str)
{
	if (m_first == nullptr)
	{
		m_first = m_last = new Element(str, 0);
	}
	else
	{
		// создать новый элемент списка
		Element* elem = new Element(str, 0);
		// последний элемент списка указывает на новый созданный элемент
		m_last->m_next = elem;
		// поменять указатель на последний элемент
		m_last = elem;
	}
	m_count++;
}


//оператор [] 
char*& LinkedList::operator[] (int pos)
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
	throw exception("Incorrect index!!!");
}


//GetCount - кол-во вхождений указанной строки
size_t LinkedList::GetCount(const char* str)
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


//Вывод
void LinkedList::Print()
{
	Element* current = m_first;
	while (current != nullptr)
	{
		cout << current->m_str << "	"<<current<<endl;
		current = current->m_next;
	}
	cout << "m_count = " << m_count << endl;
}


//Find - находит первое вхождение элемента списка по значению
Element* LinkedList::Find(char* str)
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
		throw exception("Data dosn't exist!!!");
}


//Clear - очищает все элементы списка
void LinkedList::Clear()
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
void LinkedList::Insert(char* str, size_t index)
{
	if (m_count > index)
	{
		// создать новый элемент списка
		Element* new_element = new Element(str, 0);
		if (index == 0)
		{
			// связать новый элемент с первым в списке
			new_element->m_next = m_first;
			// поменять первый элемент в списке на новый
			m_first = new_element;
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
				// previous - указатель на элемент, после которого нужно вставить новый 
				previous = current;
				// current - элемент с номером index
				current = current->m_next;
				break;
			}
			// "перепрыгнуть" на следующий элемент списка
			current = current->m_next;
			n++;
		}
		// связать новый элемент с элементом index-1
		previous->m_next = new_element;
		// связать новый элемент с элементом index
		new_element->m_next = current;
		m_count++;
	}
	else throw exception("Attemp to insert to empty list!!!");
}


//Delete - удаление элемента по индексу 
void LinkedList::Delete(size_t index)
{
	Element* current = m_first;
	Element* temp = nullptr;
	Element* previous = nullptr;
	size_t n = 0;

	if (index >= 0 && index < m_count)
	{
		//если список пуст
		if (m_first == nullptr)
		{
			throw exception("List is empty!!!");
		}
		//если позиция первая
		if (index == 0)
		{
			m_first = m_first->m_next;
			delete current;
			delete temp;
			delete previous;
			m_count--;
			return;
		}
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
		previous->m_next = current->m_next;

		if (m_last == current)
			m_last = previous;
		delete current;
		m_count--;
	}
	else
		throw exception("Wrong index!!!");
}


//DeleteAll - удаление всех вхождений строки в список
size_t LinkedList::DeleteAll(char* str)
{
	// количество удалённых элементов
	size_t deletedElementsCount = 0;
	// если в списке есть элементы
	if (m_first != nullptr)
	{
		Element* current = m_first;
		Element* prev = nullptr;
		// цикл по элементам списка
		while (current != nullptr)
		{
			// если найден элемент, который надо удалить
			if (strcmp(current->m_str, str) == 0)
			{
				// если удаляется первый элемент
				if (m_first == current)
				{
					// запомнить адрес первого элемента
					Element* temp = m_first;
					// переместить первый элемент вперёд на 1 элемент
					m_first = m_first->m_next;
					// удалить старый элемент
					delete temp;
					deletedElementsCount++;
					m_count--;
					// если после удаления в списке не осталось элементов
					if (m_first == nullptr)
						return deletedElementsCount;
					else current = m_first;

				}
				else // удаляется не первый элемент
				{
					// связать элемент перед удаляемым с элементом после удаляемого
					prev->m_next = current->m_next;
					// если удаляется последний элемент, то исправить указатель last
					if (m_last == current)
					{
						m_last = prev;
					}
					// запомнить адрес первого элемента
					Element* temp = current;
					// переместить первый элемент вперёд на 1 элемент
					current = current->m_next;
					// удалить старый элемент
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
				// запомнить предыдущий элемент
				prev = current;
				// "перепрыгнуть" на следующий элемент списка
				current = current->m_next;
			}
		}
		// весь список просмотрен, возвратить количество удалённых элементов
		return deletedElementsCount;
	}
	else return 0;
}


//operator ==
bool LinkedList::operator == (LinkedList& source)
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
void LinkedList::operator+ (const char* str)
{
	Add(str);
}


//operator +	добавление списка в конец списка
LinkedList& LinkedList::operator+ (LinkedList& source)
{
	//создаю еще один (результирующий) список
	LinkedList* result = new LinkedList();
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
LinkedList& LinkedList::operator+= (LinkedList& source)
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
