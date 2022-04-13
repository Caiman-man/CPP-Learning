#pragma once
class Matrix
{
	int** m_matr;
	int m_rows, m_cols;
	void Fill_Matrix();
public:
	Matrix();
	Matrix(int rows, int cols);
	~Matrix();
	int& operator() (int x, int y);
	void Load(const char filename[]);
	void Save(const char filename[]);
	void Print();
};

