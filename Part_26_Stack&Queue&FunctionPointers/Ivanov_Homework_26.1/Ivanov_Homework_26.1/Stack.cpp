#include <iostream>
#include "Stack.h"
using namespace std;

// онструктор с параметрами
Stack::Stack(size_t max_size)
{
	this->m_max_size = max_size;
	m_size = 0;
	m_stack = new int[m_max_size];
}

//ƒеструктор
Stack::~Stack()
{
	delete[] m_stack;
}

//Push
void Stack::Push(int value)
{
	if (m_size < m_max_size)
	{
		m_stack[m_size] = value;
		m_size++;
		cout << value << " - element added!\n";
	}
	else 
		throw "STACK OVERFLOW!!!";
}

//Pop
int Stack::Pop()
{
	if (m_size > 0)
	{
		m_size--;
		return m_stack[m_size];
	}
	else
		throw "STACK IS EMPTY!!!";
}

//Clear
/*данный метод по моему не очень корректный, так как значени€ в массиве все-равно остаютс€, 
  но использоватьс€ они уже не будут*/
void Stack::Clear()
{
	cout << "Stack is cleared!" << endl;
	m_size = 0;
}

//Length
int Stack::Length()
{
	return m_max_size;
}

//CurrentCount
int Stack::CurrentCount()
{
	return m_size;
}

//Peek
int Stack::Peek()
{
	return m_stack[m_size-1];
}

//¬ывод
void Stack::Print()
{
	if (m_size == 0)
	{
		cout << "Print: \n";
		cout << "Stack is empty!\n";
	}
	else
	{
		cout << "Print: \n";
		for (size_t i = 0; i < m_size; i++)
		{
			cout << m_stack[i] << " ";
		}
	}
}