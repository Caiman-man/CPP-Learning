#pragma once
class Queue
{
	//��������� �� ������� (������������ ������)
	int* m_queue;
	//������������ ������ �������
	size_t m_max_size;
	//������� ���-�� ��������� � �������
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

