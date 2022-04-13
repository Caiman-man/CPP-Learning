#pragma once
class Stack
{
	//указатель на стек (динамический массив)
	int* m_stack;
	//максимальный размер стека
	size_t m_max_size;
	//текущее кол-во элементов в стеке (вершина стека)
	size_t m_size;
public:
	Stack(size_t max_size);
	~Stack();

	void Push(int value);
	int Pop();
	void Clear();
	int Length();
	int CurrentCount();
	int Peek();
	void Print();
};

