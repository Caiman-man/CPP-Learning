#pragma once
class Matrix
{
	int** m_matr;
	int m_rows, m_cols;
	void Fill_Matrix();
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& source);
	Matrix& operator = (const Matrix& source);
	~Matrix();
	bool operator == (Matrix& source);
	bool operator != (Matrix& source);
	Matrix operator + (int n);
	Matrix operator + (Matrix& source);
	void Print();
};

