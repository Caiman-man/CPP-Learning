#pragma once
class Strings
{
	char** str;
	size_t max_lines_count;						//������������ ���������� �����
	size_t fill_count;							//������� ���������� �����
	size_t reserve_size;						//���������� ��������� �����		
	static int count;							//����������� ���������� (���-�� ��������)
	void Stretch_lines();						//����� ��� ���������� �������
public:
	Strings();
	Strings(size_t lines);
	Strings(const Strings& source);
	Strings& operator= (const Strings& source);
	~Strings();

	static int Get_count();						//����� ��� �������� �������� count

	void* operator new(size_t);
	void operator delete(void* p);
	void* operator new[](size_t);
	void operator delete[](void* p);

	char* operator[](int pos);
	Strings& operator+= (const char* s);
	Strings& operator-= (const char* s);

	void Add(const char* s);
	void Save(const char filepath[]);
	void Load(const char filepath[]);

	void Print();
};

