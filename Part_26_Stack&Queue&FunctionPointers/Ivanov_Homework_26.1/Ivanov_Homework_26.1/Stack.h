#pragma once
class Stack
{
	//��������� �� ���� (������������ ������)
	int* m_stack;
	//������������ ������ �����
	size_t m_max_size;
	//������� ���-�� ��������� � ����� (������� �����)
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

