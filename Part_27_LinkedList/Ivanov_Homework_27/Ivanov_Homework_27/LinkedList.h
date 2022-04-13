#pragma once
struct Element
{
	char* m_str;
	Element* m_next;

	Element()
	{
		m_str = new char;
		m_next = nullptr;
	}

	Element(const char* str, Element* next)
	{
		this->m_str = new char[strlen(str) + 1];
		strcpy(this->m_str, str);
		this->m_next = next;
	}

	~Element()
	{
		delete[] m_str;
	}
};


class LinkedList
{
	Element* m_first;
	Element* m_last;
	size_t m_count;

public:
	LinkedList();
	LinkedList(const LinkedList& source);
	LinkedList& operator= (LinkedList& source);
	~LinkedList();

	void Add(const char* str);
	char*& operator[] (int pos);
	size_t GetCount(const char* str);

	Element* Find(char* str);
	void Clear();
	void Insert(char* str, size_t index);
	void Delete(size_t index);
	size_t DeleteAll(char* str);
	bool operator== (LinkedList& source);
	void operator+ (const char* str);
	LinkedList& operator+ (LinkedList& source);
	LinkedList& operator+= (LinkedList& source);

	void Print();
};

