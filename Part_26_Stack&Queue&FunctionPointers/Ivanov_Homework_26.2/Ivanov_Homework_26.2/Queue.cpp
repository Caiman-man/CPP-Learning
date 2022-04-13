#include <iostream>
#include "Queue.h"
using namespace std;

//Конструктор с параметрами
Queue::Queue(size_t max_size)
{
	this->m_max_size = max_size;
	m_size = 0;
	m_queue = new int[m_max_size];
}

//Деструктор
Queue::~Queue()
{
	delete[] m_queue;
}

//Enqueue
void Queue::Enqueue(int value)
{
	if (m_size < m_max_size)
	{
		m_queue[m_size] = value;
		m_size++;
		cout << value << " - element added!\n";
	}
	else
		throw "QUEUE IS FULL!!!";
}

//Dequeue
int Queue::Dequeue()
{
	if (m_size > 0)
	{
		int temp = m_queue[0];
		for (int i = 1; i < m_size; i++)
		{
			m_queue[i - 1] = m_queue[i];
		}
		m_size--;
		return temp;
	}
	else
		throw "QUEUE IS EMPTY!!!";
}

//Clear
void Queue::Clear()
{
	cout << "Queue is cleared!" << endl;
	m_size = 0;
}

//Length
int Queue::Length()
{
	return m_max_size;
}

//CurrentCount
int Queue::CurrentCount()
{
	return m_size;
}

//Peek
int Queue::Peek()
{
	return m_queue[0];
}

//Вывод
void Queue::Print()
{
	if (m_size == 0)
	{
		cout << "Print: \n";
		cout << "Queue is empty!\n";
	}
	else
	{
		cout << "Print: \n";
		for (size_t i = 0; i < m_size; i++)
		{
			cout << m_queue[i] << " ";
		}
	}
}
