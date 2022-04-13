#include "Strings.h"
#include "StringsException.h"
#include <iostream>
#include <fstream>
using namespace std;

//������������� ������������ ���� ������
int Strings::count = 0;

//����������� �� ���������
Strings::Strings()
{
	cout << "constr" << "\n";
	max_lines_count = 10;
	reserve_size = 5;
	fill_count = 0;
	str = new char* [max_lines_count];
	//����������� ������� ���-�� �������� 
	count++;
}

//����������� � �����������
Strings::Strings(size_t lines)
{
	cout << "Constr" << "\n";
	max_lines_count = lines;
	reserve_size = 5;
	fill_count = 0;
	str = new char* [max_lines_count];
	//����������� ������� ���-�� �������� 
	count++;
}

//����������� �����������
Strings::Strings(const Strings& source)
{
	cout << "Copy constr" << "\n";
	max_lines_count = source.max_lines_count;
	fill_count = source.fill_count;
	str = new char* [max_lines_count];

	for (size_t i = 0; i < fill_count; i++)
	{
		str[i] = new char[strlen(source.str[i]) + 1];
		strcpy(str[i], source.str[i]);
	}
	//����������� ������� ���-�� �������� 
	count++;
}

//�������� =
Strings& Strings::operator= (const Strings& source)
{
	if (max_lines_count != source.max_lines_count)
	{
		for (size_t i = 0; i < fill_count; i++)
		{
			delete[] str[i];
		}
		delete[] str;

		max_lines_count = source.max_lines_count;
		fill_count = source.fill_count;
		str = new char* [max_lines_count];
	}

	for (size_t i = 0; i < fill_count; i++)
	{
		str[i] = new char[strlen(source.str[i]) + 1];
		strcpy(str[i], source.str[i]);
	}

	return *this;
}

//�������� new
void* Strings::operator new(size_t t)
{
	void* p = malloc(t);
	cout << "operator new, Size = " << t << "\n";
	return  p;
}

//�������� delete
void Strings::operator delete(void* p)
{
	cout << "operator delete" << "\n";
	free(p);
}

//�������� new[]
void* Strings::operator new[](size_t t)
{
	void* p = malloc(t);
	cout << "operator new[], Size = " << t << "\n";
	return  p;
}

//�������� delete[]
void Strings::operator delete[](void* p)
{
	cout << "operator delete[]" << "\n";
	free(p);
}

//operator[]
char* Strings::operator[](int pos)
{
	if (pos >= 0 && pos < fill_count)
	{
		return str[pos];
	}
	else return 0;
}

//�������� +=
Strings& Strings::operator+= (const char* s)
{
	//� ������, ���� ���-�� ������� ����� ������ ��� ������������, �� �������� ����� Stretch_lines()
	if (fill_count >= max_lines_count)
		Stretch_lines();

	str[fill_count] = new char[strlen(s) + 1];
	strcpy(str[fill_count], s);
	fill_count++;

	return *this;
}

//�������� -=
Strings& Strings::operator-= (const char* s)
{
	for (size_t i = 0; i < fill_count; i++)
	{
		//���� ����� �������� ���-�� ����������� ����� ���� ����������� �� ������� 's'
		if (strcmp(str[i], s) == 0)
		{
			for (int k = i; k < fill_count - 1; k++)
			{
				//������� ������ ��������� ������
				delete[] str[k];
				//�������� ������ ������ ������� ��� ������� (������ ��������� ������)
				str[k] = new char[strlen(str[k + 1]) + 1];
				//�������� ��������� ������ �� ����� �������, � �������� ������
				strcpy(str[k], str[k + 1]);
			}
			i--;
			fill_count--;
		}
	}
	return *this;
}

//����� Add (���������� ������)
void Strings::Add(const char* s)
{
	if (fill_count >= max_lines_count)
		throw new StringsException(1, "The current lines number is greater than the maximum!");

	str[fill_count] = new char[strlen(s) + 1];
	strcpy(str[fill_count], s);
	fill_count++;
}

//����� Save
void Strings::Save(const char filepath[])
{
	ofstream f1;
	f1.open(filepath);
	if (f1.is_open())
	{
		for (size_t i = 0; i < fill_count; i++)
		{
			f1 << str[i] << "\n";
		}
		f1.close();
		cout << "The file saved successfully!" << "\n";
	}
	else
		throw new StringsException(2, "Error opening file for saving!");
}

//����� Load
void Strings::Load(const char filepath[])
{
	ifstream f2;
	f2.open(filepath);
	if (f2.is_open())
	{
		//���� ������� ���-�� ����� ������ ����, �� ������ ��� ������, � ������� fill_count
		if (fill_count > 0)
		{
			for (size_t i = 0; i < fill_count; i++)
			{
				delete[] str[i];
			}
		}
		fill_count = 0;

		//���� ���� �� ���������� ����
		while (!f2.eof())
		{
			/*������ ��� str[i] ���������� �������� �������, ������� �������� ���� � ������ � �����
			��� ���������� ��������� ���-�� �������� � ������ � �����, �� ���� ��� �������� ������ � �� ����
			������� � ������ ��������� �� ������ ����� "buffer", ���� �������� ������*/
			char* buffer = new char[1024];
			f2.getline(buffer, 1024);
			//����� �������� � ������� strlen ������� ��������� ��������, � ��������� ��� �������� ��� ��������� ������ ��� str[i]
			str[fill_count] = new char[strlen(buffer) + 1];
			//����� ������� ������ �� ������ � str[i] � ������ �����
			strcpy(str[fill_count], buffer);
			delete[] buffer;

			fill_count++;
			//� ������, ���� ���-�� ����� � ����� ������ ��� ������������, �� �������� ����� Stretch_lines()
			if (fill_count >= max_lines_count)
				Stretch_lines();
		}
		f2.close();
		cout << "The file loaded successfully!" << "\n";
	}
	else
		throw new StringsException(3, "Error opening load file!");
}

//����� ���������� ������������� ���-�� �����
void Strings::Stretch_lines()
{
	cout << "Stretch_lines" << endl;
	char** new_str = new char* [max_lines_count + reserve_size];

	for (size_t i = 0; i < max_lines_count; i++)
	{
		new_str[i] = str[i];
	}

	delete[] str;
	str = new_str;
	max_lines_count += reserve_size;
}

//����������
Strings::~Strings()
{
	cout << "destr" << "\n";
	for (size_t i = 0; i < fill_count; i++)
	{
		delete[] str[i];
	}
	delete[] str;
	//��������� ������� ���-�� �������� 
	count--;
}

//�����
void Strings::Print()
{
	cout << endl;
	for (size_t i = 0; i < fill_count; i++)
	{
		cout << str[i] << endl;
	}
	//������� ������� � ������������ ���-�� �����
	cout << "\nfill_count = " << fill_count << "\n";
	cout << "max_lines_count = " << max_lines_count << "\n\n";
}

//����������� ����� �������� �������� count
int Strings::Get_count()
{
	return count;
}