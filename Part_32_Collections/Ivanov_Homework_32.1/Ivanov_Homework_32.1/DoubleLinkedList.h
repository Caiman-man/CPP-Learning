#pragma once
#include <iostream>
using namespace std;

struct Element
{
	char* m_str;
	Element* m_next;
	Element* m_prev;

	Element()
	{
		m_str = new char;
		m_next = nullptr;
		m_prev = nullptr;
	}

	Element(const char* str, Element* next, Element* prev)
	{
		this->m_str = new char[strlen(str) + 1];
		strcpy(this->m_str, str);
		this->m_next = next;
		this->m_prev = prev;
	}

	~Element()
	{
		delete[] m_str;
	}
};


class DoubleLinkedList
{
	Element* m_first;
	Element* m_last;
	size_t m_count;

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& source);
	DoubleLinkedList& operator= (DoubleLinkedList& source);
	~DoubleLinkedList();

	void Add(const char* str);
	void AddFirst(const char* str);
	Element* Find(const char* str);
	void Clear();
	void Insert(const char* str, size_t index);
	void Delete(size_t index);
	size_t DeleteAll(const char* str);
	void Save(const char filename[]);
	DoubleLinkedList& Load(const char filename[]);
	size_t GetCount(const char* str);

	char*& operator[] (int pos);
	bool operator== (DoubleLinkedList& source);
	void operator+ (const char* str);
	DoubleLinkedList& operator+ (DoubleLinkedList& source);
	DoubleLinkedList& operator+= (DoubleLinkedList& source);

	void Print();
	void PrintBack();

	//------------------------------------------------------------------------------------------------
	DoubleLinkedList& operator++();
	DoubleLinkedList  operator++(int n);
	DoubleLinkedList& operator--();
	DoubleLinkedList  operator--(int n);

	//два вида перегруженных операторов одновременно не работают, поэтому один из них я закомментировал
	friend ostream&   operator<< (ostream& osf, const DoubleLinkedList& source);
	friend istream&   operator>> (istream& isf, DoubleLinkedList& source);
	//friend ostream& operator<< (ostream& os, const DoubleLinkedList& source);
	//friend istream& operator>> (istream& is, DoubleLinkedList& source);
};

