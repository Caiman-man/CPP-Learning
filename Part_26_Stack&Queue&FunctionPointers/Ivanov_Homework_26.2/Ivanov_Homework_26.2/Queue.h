#pragma once
class Queue
{
	//указатель на очередь (динамический массив)
	int* m_queue;
	//максимальный размер очереди
	size_t m_max_size;
	//текущее кол-во элементов в очереди
	size_t m_size;
public:
	Queue(size_t max_size);
	~Queue();

	void Enqueue(int value);
	int Dequeue();
	void Clear();
	int Length();
	int CurrentCount();
	int Peek();

	void Print();
};

