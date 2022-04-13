#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

//Заполнение матрицы
void Matrix::Fill_Matrix()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_matr[i][k] = i + 1;
		}
	}
}

//Конструктор без параметров
Matrix::Matrix()
{
	m_rows = 3;
	m_cols = 3;
	m_matr = new int* [m_rows];							
	for (int i = 0; i < m_rows; i++)						
	{
		m_matr[i] = new int[m_cols];
	}
	Fill_Matrix();
}

//Конструктор с параметрами
Matrix::Matrix(int rows, int cols)
{
	m_matr = new int* [rows];
	this->m_rows = rows;
	this->m_cols = cols;
	for (int i = 0; i < rows; i++)
	{
		m_matr[i] = new int[cols];
	}
	Fill_Matrix();
}

//Деструктор
Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; i++)								
	{
		delete[] m_matr[i];
	}

	delete[] m_matr;
}

//Оператор () - сеттер и геттер
int& Matrix::operator() (int i, int k)
{
	if (i >= 0 && i < m_rows && k >= 0 && k < m_cols) return m_matr[i][k];
	else return m_matr[0][0];													//аварийное значение
}

//Загрузка матрицы из файла (использовал ifstream)
void Matrix::Load(const char filename[])
{
	ifstream f1;
	f1.open(filename);
	if (f1.is_open())
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int k = 0; k < m_cols; k++)
			{
				f1 >> m_matr[i][k];
			}
		}
		f1.close();
	}
	else
		cout << "Error opening file!" << endl;
}

//Сохранение матрицы в файл (использовал ofstream)
void Matrix::Save(const char filename[])
{
	ofstream f2;
	f2.open(filename);
	if (f2.is_open())
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int k = 0; k < m_cols; k++)
			{
				f2 << m_matr[i][k] << "\t";
			}
			f2 << "\n";
		}
		f2.close();
	}
	else
		cout << "Error opening file!" << endl;
}

//Вывод
void Matrix::Print()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			cout << m_matr[i][k] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}