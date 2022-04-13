#include <iostream>
#include "Vector.h"
using namespace std;

/*2. Разработать класс Vector, который содержит в себе одномерный статический массив
	 и имеет следующие члены класса:
	 - int v[5]																	
	 - конструктор без параметров												
	 - конструктор с параметрами (число, для заполнения массива)			
	 - print() - печать на экран												
	 - set(int index, int n) - занесение числа n в ячейку с номером index		
	 - get(int index) - возврат значения элемента массива с номером index*/

void main()
{
	//Вызов конструктора по умолчанию
	cout <<"First object: " <<endl;
	Vector vector1;
	vector1.Print();
	cout << endl;

	//Вызов конструктора с параметрами
	cout << "Second object: " << endl;
	Vector vector2(777);
	vector2.Print();
	cout << endl;

	//Изменение элемента массива с помощью сеттера
	vector2.set_Number(0, 555);
	vector2.Print();
	cout << endl;

	//Использование геттера для получения данных
	int index, get;
	cout << "Enter an index: " << endl;
	cin >> index;
	if (index < 5)												//проверку сделал здесь в main'e
	{
		get = vector2.get_Number(index);
		cout << get << endl;
	}
	else cout << "Error index" << endl;
















}