#include <iostream>
#include "LinkedList.h"
using namespace std;

//����������� �� ���������
LinkedList::LinkedList()
{
	m_first = m_last = nullptr;
	m_count = 0;
}


//����������� �����������
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


//�������� = 
LinkedList& LinkedList::operator= (LinkedList& source)
{
	// �������� ������ ��������� ������
	Element* current = m_first;
	while (current != nullptr)
	{
		Element* temp = current;
		// "������������" �� ��������� ������� ������
		current = current->m_next;
		delete temp;
	}

	m_first = m_last = nullptr;

	// ���������� ����� ���������
	current = source.m_first;
	while (current != nullptr)
	{
		Add(current->m_str);
		current = current->m_next;
	}
	return *this;
}


//����������
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
		// ������� ����� ������� ������
		Element* elem = new Element(str, 0);
		// ��������� ������� ������ ��������� �� ����� ��������� �������
		m_last->m_next = elem;
		// �������� ��������� �� ��������� �������
		m_last = elem;
	}
	m_count++;
}


//�������� [] 
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


//GetCount - ���-�� ��������� ��������� ������
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


//�����
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


//Find - ������� ������ ��������� �������� ������ �� ��������
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


//Clear - ������� ��� �������� ������
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


//Insert - ��������� ������� ����� ��������� � ��������� ��������
void LinkedList::Insert(char* str, size_t index)
{
	if (m_count > index)
	{
		// ������� ����� ������� ������
		Element* new_element = new Element(str, 0);
		if (index == 0)
		{
			// ������� ����� ������� � ������ � ������
			new_element->m_next = m_first;
			// �������� ������ ������� � ������ �� �����
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
				// previous - ��������� �� �������, ����� �������� ����� �������� ����� 
				previous = current;
				// current - ������� � ������� index
				current = current->m_next;
				break;
			}
			// "������������" �� ��������� ������� ������
			current = current->m_next;
			n++;
		}
		// ������� ����� ������� � ��������� index-1
		previous->m_next = new_element;
		// ������� ����� ������� � ��������� index
		new_element->m_next = current;
		m_count++;
	}
	else throw exception("Attemp to insert to empty list!!!");
}


//Delete - �������� �������� �� ������� 
void LinkedList::Delete(size_t index)
{
	Element* current = m_first;
	Element* temp = nullptr;
	Element* previous = nullptr;
	size_t n = 0;

	if (index >= 0 && index < m_count)
	{
		//���� ������ ����
		if (m_first == nullptr)
		{
			throw exception("List is empty!!!");
		}
		//���� ������� ������
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


//DeleteAll - �������� ���� ��������� ������ � ������
size_t LinkedList::DeleteAll(char* str)
{
	// ���������� �������� ���������
	size_t deletedElementsCount = 0;
	// ���� � ������ ���� ��������
	if (m_first != nullptr)
	{
		Element* current = m_first;
		Element* prev = nullptr;
		// ���� �� ��������� ������
		while (current != nullptr)
		{
			// ���� ������ �������, ������� ���� �������
			if (strcmp(current->m_str, str) == 0)
			{
				// ���� ��������� ������ �������
				if (m_first == current)
				{
					// ��������� ����� ������� ��������
					Element* temp = m_first;
					// ����������� ������ ������� ����� �� 1 �������
					m_first = m_first->m_next;
					// ������� ������ �������
					delete temp;
					deletedElementsCount++;
					m_count--;
					// ���� ����� �������� � ������ �� �������� ���������
					if (m_first == nullptr)
						return deletedElementsCount;
					else current = m_first;

				}
				else // ��������� �� ������ �������
				{
					// ������� ������� ����� ��������� � ��������� ����� ����������
					prev->m_next = current->m_next;
					// ���� ��������� ��������� �������, �� ��������� ��������� last
					if (m_last == current)
					{
						m_last = prev;
					}
					// ��������� ����� ������� ��������
					Element* temp = current;
					// ����������� ������ ������� ����� �� 1 �������
					current = current->m_next;
					// ������� ������ �������
					delete temp;
					deletedElementsCount++;
					m_count--;
					// ���� ����� �������� � ������ �� �������� ���������
					if (current == nullptr)
						return deletedElementsCount;
				}
			}
			else // ���� ������� ������� �� ����, �� ������������ �� ���������
			{
				// ��������� ���������� �������
				prev = current;
				// "������������" �� ��������� ������� ������
				current = current->m_next;
			}
		}
		// ���� ������ ����������, ���������� ���������� �������� ���������
		return deletedElementsCount;
	}
	else return 0;
}


//operator ==
bool LinkedList::operator == (LinkedList& source)
{
	Element* current = m_first;
	Element* current2 = source.m_first;

	//���� ���-�� ��������� ��������� ������ �� ��������� �� ������������
	if (m_count != source.m_count)
		return false;
	//���� ���������, �� ��������� ������ �������
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


//operator +	���������� �������� � ����� ������
void LinkedList::operator+ (const char* str)
{
	Add(str);
}


//operator +	���������� ������ � ����� ������
LinkedList& LinkedList::operator+ (LinkedList& source)
{
	//������ ��� ���� (��������������) ������
	LinkedList* result = new LinkedList();
	Element* current = m_first;

	//������� �������� �� ������� ������ � ��������������
	while (current != nullptr)
	{
		result->Add(current->m_str);
		current = current->m_next;
	}
	//��������� ��������� �� ������ ������, � ��������� ���������� �������� ��� �� 2�� ������
	current = source.m_first;
	while (current != nullptr)
	{
		result->Add(current->m_str);
		current = current->m_next;
	}

	return *result;
}


//operator +=	���������� ������ � ����� ������
LinkedList& LinkedList::operator+= (LinkedList& source)
{
	//������ ��������� �� 2� ������
	Element* current = source.m_first;
	while (current != nullptr)
	{
		//�������� ������� Add �������� 2�� ������ � ����� 1��
		Add(current->m_str);
		current = current->m_next;
	}
	return *this;
}
