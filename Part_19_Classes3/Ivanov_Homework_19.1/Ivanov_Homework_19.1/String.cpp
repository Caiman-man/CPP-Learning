#include <iostream>
#include "String.h"
using namespace std;

//����������� ��� ����������
String::String()
{
	cout << "Constr" << endl;
	m_str = new char[13];
	strcpy(m_str, "Hello world!");
}

//����������� � �����������
String::String(const char* str)
{
	cout << "Constr" << endl;
	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);
}

//����������
String::~String()
{
	cout << "Destr" << endl;
	delete[] m_str;
}

//����������� �����������
String::String(const String& source)
{
	cout << "Copy Constr" << endl;
	m_str = new char[strlen(source.m_str) + 1];
	strcpy(m_str, source.m_str);
}

//�������� = 
String& String::operator= (const String& source)
{
	cout << "Operator = " << endl;
	if (strcmp(m_str, source.m_str) != 0)
	{
		delete[] m_str;
		m_str = new char[strlen(source.m_str) + 1];
	}
	strcpy(m_str, source.m_str);
	return *this;
}

//�������� ==
bool String::operator == (const String& source)
{
	int len = strlen(source.m_str);
	if (strlen(m_str) != len) return false;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (m_str[i] != source.m_str[i]) return false;
		}
	}
	return true;
}

//�������� !=
bool String::operator != (const String& source)
{
	int len = strlen(source.m_str);
	if (strlen(m_str) != len) return true;
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (m_str[i] != source.m_str[i]) return true;
		}
	}
	return false;
}

//�������� <=
bool String::operator <= (const String& source)
{
	if (strlen(m_str) <= strlen(source.m_str)) return true;
	return false;
}

//�������� >=
bool String::operator >= (const String& source)
{
	if (strlen(m_str) >= strlen(source.m_str)) return true;
	return false;
}

//�������� +
String String::operator + (String& source)
{
	cout << "Operator + string" << endl;

	//������ ����

	//int len = (strlen(m_str) + 1 + strlen(source.m_str) + 1);	//������ ����� ���� ����� ������
	//String result;												//������ ����� ������
	//delete[] result.m_str;										//������ ������ m_str � ���� �������
	//result.m_str = new char[len];								//������� ������ ������, (��� ���� �����)
	//strcpy(result.m_str, m_str);								//�������� ������
	//strcat(result.m_str, source.m_str);
	//return result;

	String result = *this;
	int len = (strlen(m_str) + 1 + strlen(source.m_str) + 1);
	result.m_str = new char[len];
	strcpy(result.m_str, m_str);
	strcat(result.m_str, source.m_str);
	return result;



}

//�������� -
String String::operator - (char ch)
{
	cout << "Operator - char" << endl;

	/*String result;											//������ ����
	delete[] result.m_str;
	result.m_str = new char[strlen(m_str) + 1];
	strcpy(result.m_str, m_str);*/

	String result = *this;

	for (int i = 0; i < (strlen(result.m_str)+1); i++)
	{
		if (result.m_str[i] == ch)
		{
			for (int k = i; result.m_str[k] != 0; k++)
			{
				result.m_str[k] = result.m_str[k + 1];			//��������, �� ������������ �������
			}
			i--;
		}
	}
	return result;
}

//�����
void String::Print()
{
	cout << m_str << endl;
}
