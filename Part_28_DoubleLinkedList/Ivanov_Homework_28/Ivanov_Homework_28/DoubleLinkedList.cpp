#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
using namespace std;

//����������� �� ���������
DoubleLinkedList::DoubleLinkedList()
{
	m_first = m_last = nullptr;
	m_count = 0;
}


//����������� ����������� 
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


//�������� = 
DoubleLinkedList& DoubleLinkedList::operator= (DoubleLinkedList& source)
{
	// �������� ������ ��������� ������
	Element* current = m_first;
	while (current != nullptr)
	{
		Element* temp = current;
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


//Find - ������� ������ ��������� �������� ������ �� ��������
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


//Clear - ������� ��� �������� ������
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


//Insert - ��������� ������� ����� ��������� � ��������� ��������
void DoubleLinkedList::Insert(const char* str, size_t index)
{
	if (index >= 0 && index < m_count)
	{
		// ������� ����� ������� ������
		Element* elem = new Element(str, 0, 0);
		//���� ����� ������� ���������� �������� ����� ������ ���������
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
		//��������� ������ ����� ����� ��������� � �������������
		previous->m_next = elem;
		elem->m_prev = previous;
		elem->m_next = current;
		current->m_prev = elem;
		m_count++;
	}
	else throw exception("Attemp to insert to empty list!");
}


//Delete - �������� �������� �� ������� 
void DoubleLinkedList::Delete(size_t index)
{
	Element* current = m_first;
	size_t n = 0;

	if (index >= 0 && index < m_count)
	{
		//���� ������ ����
		if (m_first == nullptr)
		{
			throw exception("List is empty!");
		}
		//���� ������� - ������
		if (index == 0)
		{
			m_first = m_first->m_next;
			m_first->m_prev = nullptr;
			delete current;
			m_count--;
			return;
		}
		//���� ������� - ���������
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

		//��������� ������ ����� ����������
		current->m_next->m_prev = current->m_prev;
		current->m_prev->m_next = current->m_next;
		delete current;
		m_count--;
	}
	else
		throw exception("Wrong index!");
}


//DeleteAll - �������� ���� ��������� ������ � ������
size_t DoubleLinkedList::DeleteAll(const char* str)
{
	size_t deletedElementsCount = 0;

	// ���� ������ �� ����
	if (m_first != nullptr)
	{
		Element* current = m_first;

		// ���� �� ��������� ������
		while (current != nullptr)
		{
			// ���� ������ �������, ������� ���� �������
			if (strcmp(current->m_str, str) == 0)
			{
				// ���� ��������� ������ �������
				if (current == m_first)
				{
					Element* tmp = m_first;
					m_first = m_first->m_next;
					m_first->m_prev = nullptr;
					delete tmp;
					deletedElementsCount++;
					m_count--;
					// ���� ����� �������� � ������ �� �������� ���������
					if (m_first == nullptr)
						return deletedElementsCount;
					else current = m_first;
				}
				// ���� ��������� ��������� �������
				else if (current == m_last)
				{
					Element* tmp = m_last;
					m_last = m_last->m_prev;
					m_last->m_next = nullptr;
					delete tmp;
					deletedElementsCount++;
					m_count--;
					// ���� ����� �������� � ������ �� �������� ���������
					if (m_last == nullptr)
						return deletedElementsCount;
					else current = m_last;
				}
				// ���� ��������� �� ������ �������
				else 
				{
					Element* temp = current;
					current = current->m_next;
					//��������� �����
					temp->m_next->m_prev = temp->m_prev;
					temp->m_prev->m_next = temp->m_next;
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
				current = current->m_next;
			}
		}
		// ���� ������ ����������, ���������� ���������� �������� ���������
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
			//�������� ������ ������ ��� ������ 'write'
			long size = strlen(current->m_str);
			//��������� ������ � ����, ����� ��������� ������� �� ����� ������
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
			// ������ ����� ���������
			file.getline(buffer, 128);
			//����� ������ Add ��� �������� ��������� � ���������� ��������� ����� � ���
			Add(buffer);
		}
		file.close();
		cout << "The file loaded successfully!\n";
	}
	else
		cout << "Error opening file!\n";
	return *this;
}


//GetCount - ���-�� ��������� ��������� ������
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


//�������� [] 
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
void DoubleLinkedList::operator+ (const char* str)
{
	Add(str);
}


//operator +	���������� ������ � ����� ������
DoubleLinkedList& DoubleLinkedList::operator+ (DoubleLinkedList& source)
{
	//������ ��� ���� (��������������) ������
	DoubleLinkedList* result = new DoubleLinkedList();
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
DoubleLinkedList& DoubleLinkedList::operator+= (DoubleLinkedList& source)
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


//�����
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


//����������� �����
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