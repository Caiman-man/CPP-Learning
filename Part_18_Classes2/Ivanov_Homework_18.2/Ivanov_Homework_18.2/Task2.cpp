#include <iostream>
#include "Matrix.h"
using namespace std;

/*2. ƒл€ класса Matrix (двумерный динамический массив) добавить следующие методы:
	 - конструкторы с параметрами и без
	 - деструктор
	 - int& operator() (int x, int y) - сеттер и геттер (меняет €чейки в массиве) - m(3, 5) = 23;
	 - print();
	 - Save(char filename[]) - сохранение матрицы в файл
	 - Load(char filename[]) - загрузка матрицы из файла*/

void main()
{
	//создание матрицы с помощью конструктора без параметров
	cout << "Example without arguments:" << endl;
	Matrix matrix;
	matrix.Print();

	//оператор ()
	matrix(1, 1) = 777;				
	matrix.Print();

	int a = matrix(1, 1);
	cout << "Middle element is: "<< a << "\n\n";

	//сохранение матрицы в файл
	matrix.Save("result.txt");

	//загрузка матрицы из файла
	cout << "Example from file:" << endl;
	matrix.Load("matrix.txt");
	matrix.Print();

	//создание матрицы с помощью конструктора с параметрами
	cout << "Example with arguments:" << endl;
	Matrix matrix2(5, 4);
	matrix2.Print();
}