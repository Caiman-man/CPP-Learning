#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

//���������� �������
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

//����������� ��� ����������
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

//����������� � �����������
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

//����������� �����������
Matrix::Matrix(const Matrix& source)
{
	cout << "Copy Constr" << endl;

	//���������� ������� � ������� ������
	this->m_rows = source.m_rows;
	this->m_cols = source.m_cols;
	m_matr = new int* [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_matr[i] = new int[m_cols];
	}
	//���������� (�����������)
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_matr[i][k] = source.m_matr[i][k];
		}
	}
}

//�������� = 
Matrix& Matrix::operator = (const Matrix& source)
{
	cout << "Operator =" << endl;

	//���� ������� ������ �� �����
	if (m_rows != source.m_rows || m_cols != source.m_cols)
	{
		//�� ������ ������ 
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_matr[i];
		}
		delete[] m_matr;

		//� ������� ������, � ������ ���������
		m_rows = source.m_rows;
		m_cols = source.m_cols;
		m_matr = new int* [m_rows];
		for (int i = 0; i < m_rows; i++)
		{
			m_matr[i] = new int[m_cols];
		}
	}
	//���������� (�����������)
	for (int i = 0; i < m_rows; i++)
	{
		for (int k = 0; k < m_cols; k++)
		{
			m_matr[i][k] = source.m_matr[i][k];
		}
	}
	return *this;
}

//����������
Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_matr[i];
	}

	delete[] m_matr;
}

//�������� ==
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

//�������� !=
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

//�������� + n
Matrix Matrix::operator + (int n)
{
	cout << "\nOperator + n" << endl;

	Matrix result;
	//���� ������� ������� result � �������� ������� - �� �����
	if (result.m_rows != m_rows || result.m_cols != m_cols)
	{
		//�� ������ ������ ������� result
		for (int i = 0; i < result.m_rows; i++)
		{
			delete[] result.m_matr[i];
		}
		delete[] result.m_matr;

		//� ������� ������, � ������ ���������
		result.m_rows = m_rows;
		result.m_cols = m_cols;
		result.m_matr = new int* [result.m_rows];
		for (int i = 0; i < result.m_rows; i++)
		{
			result.m_matr[i] = new int[result.m_cols];
		}
	}
	//���������� (�����������)
	for (int i = 0; i < result.m_rows; i++)
	{
		for (int k = 0; k < result.m_cols; k++)
		{
			result.m_matr[i][k] = m_matr[i][k] + n;
		}
	}
	return result;
}

//�������� + Matrix n
Matrix Matrix::operator + (Matrix& source)
{
	cout << "\nOperator + Matrix" << endl;

	Matrix result;
	//���� ������� ������ �����
	if (m_rows == source.m_rows && m_cols == source.m_cols)
	{
		//�� ������ ������ ������� result
		for (int i = 0; i < result.m_rows; i++)
		{
			delete[] result.m_matr[i];
		}
		delete[] result.m_matr;

		//� ������� ������, � ������ ���������
		result.m_rows = m_rows;
		result.m_cols = m_cols;
		result.m_matr = new int* [result.m_rows];
		for (int i = 0; i < result.m_rows; i++)
		{
			result.m_matr[i] = new int[result.m_cols];
		}

		//��������
		for (int i = 0; i < result.m_rows; i++)
		{
			for (int k = 0; k < result.m_cols; k++)
			{
				result.m_matr[i][k] = m_matr[i][k] + source.m_matr[i][k];
			}
		}
	}
	/*������� �������� �� ������ ���������. 
	��� ������ �������� �������� ���������� ���������, � �������� �������� ������,
	�� ���� ������� ������ �� �����, �� return ������ ������ ������ result*/
	return result;
}

//�����
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