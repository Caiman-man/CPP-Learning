#include <iostream>
#include "Matrix.h"
using namespace std;

/*2. Для класса Matrix (двумерный динамический массив) добавить следующие методы:
	- Copy constr
	- operator =
	- operator ==, !=
	- operator+ (int n)		- прибавляет n ко всем числам матрицы
	- operator+ (Matrix m)	- складывает 2 матрицы поэлементно, если размеры равны*/

void main()
{
	//конструктор без параметров
	cout << "Example without arguments:" << endl;
	Matrix matrix;
	matrix.Print();

	//конструктор с параметрами
	cout << "Example with arguments:" << endl;
	Matrix matrix2(3, 4);
	matrix2.Print();

	//конструктор копирования
	Matrix copy = matrix2;
	copy.Print();

	//оператор =
	Matrix assign;
	assign = copy;
	assign.Print();

	//операторы сравнения
	cout << (matrix == matrix2) << endl;
	cout << (matrix != matrix2) << endl;

	//оператор + n
	Matrix add;
	add = matrix2 + 3;
	add.Print();

	//оператор + Matrix n
	Matrix addMatrix;
	addMatrix = matrix2 + matrix2;
	addMatrix.Print();
}