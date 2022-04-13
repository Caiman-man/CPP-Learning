#include <iostream>
using namespace std;
void main()
{
	/*5. Пользователь вводит 5 чисел, программа подсчитывает количество 
	положительных, отрицательных чисел и нулей и выводит на экран*/

	int a;
	int pos = 0, neg = 0, zer = 0;		//счетчики
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (a > 0) pos++;
		if (a < 0) neg++;
		if (a == 0) zer++;
	}
	cout << "Positives: " << pos<< endl;
	cout << "Negatives: " << neg<< endl;
	cout << "Zeros: " << zer<< endl;

	system("pause");

}