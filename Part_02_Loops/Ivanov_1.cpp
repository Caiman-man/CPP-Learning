#include <iostream>
using namespace std;
void main()
{
	//1. ÷икл выводит такую последовательность чисел : 1 2 3 5 6 8 9

	for (int i = 1; i <= 9; i++)
	{
		if (i != 4 && i != 7) cout << i << endl;
	}

}