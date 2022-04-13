#include <iostream>
#include <algorithm>
#include "String.h"
using namespace std;

//����������� �� ���������
String::String()
{
	m_str = new char[1024];
	strcpy(m_str, "");
}

//����������
String::~String()
{
	delete[] m_str;
}

//������� �� �����
void String::Load(const char filepath[128])
{
	FILE* f1 = fopen(filepath, "r");
	if (f1 != nullptr)
	{
		while (!feof(f1))
		{
			fgets(m_str, 1024, f1);
		}
		fclose(f1);
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}

//�������� () - ����� ����
void String::operator() (char ch1, char ch2)
{
	for (size_t i = 0; m_str[i] != 0; i++)
	{
		if (m_str[i] == ch1) m_str[i] = ch2;
	}
}

//��������� ������
void String::Reverse()
{
	char temp;
	int len = strlen(m_str) - 1;
	for (size_t i = 0; i <= len/2; i++)
	{
		temp = m_str[i];
		m_str[i] = m_str[len - i];
		m_str[len - i] = temp;
	}
}

//���������� � ����
void String::Save(const char filepath[128])
{
	FILE* f2 = fopen(filepath, "w");
	if (f2 != nullptr)
	{
		fputs(m_str, f2);
		fclose(f2);
	}
	else
		cout << "Error opening file!" << endl;
}

//�����
void String::Print()
{
	cout << m_str << endl;
}
