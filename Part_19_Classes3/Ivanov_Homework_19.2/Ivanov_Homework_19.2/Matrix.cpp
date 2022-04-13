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

//Конструктор копирования
Matrix::Matrix(const Matrix& source)
{
	cout << "Copy Constr" << endl;

	//присваиваю размеры и выделяю память
	this->m_rows = source.m_rows;
	this->m_cols = source.m_cols;
	m_matr = new int* [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_matr[i] = new int[m_cols];
	}
	//заполнение (копирование)
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_matr[i][k] = source.m_matr[i][k];
		}
	}
}

//Оператор = 
Matrix& Matrix::operator = (const Matrix& source)
{
	cout << "Operator =" << endl;

	//если размеры матриц не равны
	if (m_rows != source.m_rows || m_cols != source.m_cols)
	{
		//то очищаю память 
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_matr[i];
		}
		delete[] m_matr;

		//и выделяю заново, с новыми размерами
		m_rows = source.m_rows;
		m_cols = source.m_cols;
		m_matr = new int* [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_matr[i] = new int[m_cols];
		}
	}
	//заполнение (копирование)
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_matr[i][k] = source.m_matr[i][k];
		}
	}
	return *this;
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

//Оператор ==
bool Matrix::operator == (Matrix& source)
{
	if (m_rows != source.m_rows || m_cols != source.m_cols) return false;
	else
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int k = 0; k < m_cols; k++)
			{
				if (m_matr[i][k] != source.m_matr[i][k]) return false;
			}
		}
		return true;
	}
}

//Оператор !=
bool Matrix::operator != (Matrix& source)
{
	if (m_rows != source.m_rows || m_cols != source.m_cols) return true;
	else
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int k = 0; k < m_cols; k++)
			{
				if (m_matr[i][k] != source.m_matr[i][k]) return true;
			}
		}
		return false;
	}
}

//Оператор + n
Matrix Matrix::operator + (int n)
{
	cout << "\nOperator + n" << endl;

	Matrix result;
	//если размеры матрицы result и входящей матрицы - не равны
	if (result.m_rows != m_rows || result.m_cols != m_cols)
	{
		//то очищаю память матрицы result
		for (int i = 0; i < result.m_rows; i++)
		{
			delete[] result.m_matr[i];
		}
		delete[] result.m_matr;

		//и выделяю заново, с новыми размерами
		result.m_rows = m_rows;
		result.m_cols = m_cols;
		result.m_matr = new int* [result.m_rows];
		for (int i = 0; i < result.m_rows; i++)
		{
			result.m_matr[i] = new int[result.m_cols];
		}
	}
	//заполнение (копирование)
	for (int i = 0; i < result.m_rows; i++)
	{
		for (int k = 0; k < result.m_cols; k++)
		{
			result.m_matr[i][k] = m_matr[i][k] + n;
		}
	}
	return result;
}

//Оператор + Matrix n
Matrix Matrix::operator + (Matrix& source)
{
	cout << "\nOperator + Matrix" << endl;

	Matrix result;
	//если размеры матриц равны
	if (m_rows == source.m_rows && m_cols == source.m_cols)
	{
		//то очищаю память матрицы result
		for (int i = 0; i < result.m_rows; i++)
		{
			delete[] result.m_matr[i];
		}
		delete[] result.m_matr;

		//и выделяю заново, с новыми размерами
		result.m_rows = m_rows;
		result.m_cols = m_cols;
		result.m_matr = new int* [result.m_rows];
		for (int i = 0; i < result.m_rows; i++)
		{
			result.m_matr[i] = new int[result.m_cols];
		}

		//заполняю
		for (int i = 0; i < result.m_rows; i++)
		{
			for (int k = 0; k < result.m_cols; k++)
			{
				result.m_matr[i][k] = m_matr[i][k] + source.m_matr[i][k];
			}
		}
	}
	/*возврат работает не совсем корерктно. 
	При равных размерах оператор отработает правильно, и прибавит элементы матриц,
	но если размеры матриц не равны, то return просто вернет обьект result*/
	return result;
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