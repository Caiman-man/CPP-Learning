#include <iostream>
#include <fstream>
using namespace std;

/*3. Имеются билеты с шестизначными номерами от 000000 до 999999
Нужно определить сколько из них счастливые.
Счастливыми билетами можно считать билеты в соответствии с определёнными
критериями : 123321, 123123, 123456, 101010, 987654
Счастливость билета определяется специальными "Функциями Определения Счастья",
которые принимают номер и возвращают булевское значение.

Реализовать задачу через указатели на функции

LuckyCriteria - базовый класс для всех детекторов счастья(метод Check)
Наследники : LuckySums, LuckySequence

Сохранить все счастливые билеты в файл.*/


//объявление типа данных lucky_type
typedef bool (*lucky_type)(int, int, int, int, int, int);

//ФУНКЦИИ СЧАСТЬЯ - 10 типов:
//1. сумма трех цифр
bool func1(int a, int b, int c, int d, int e, int f)
{
	if (a + b + c == d + e + f)
	{
		return true;
	}
	else return false;
}

//2. 111111
bool func2(int a, int b, int c, int d, int e, int f)
{
	if (a == b && b == c && c == d && d == e && e == f)
	{
		return true;
	}
	else return false;
}

//3. 123456
bool func3(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1 && f == e + 1)
	{
		return true;
	}
	else return false;
}

//4. 987654
bool func4(int a, int b, int c, int d, int e, int f)
{
	if (b == a - 1 && c == b - 1 && d == c - 1 && e == d - 1 && f == e - 1)
	{
		return true;
	}
	else return false;
}

//5. 123123
bool func5(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == a && e == b && f == c)
	{
		return true;
	}
	else return false;
}

//6. 123321
bool func6(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == b + 1 && d == c && e == b && f == a)
	{
		return true;
	}
	else return false;
}

//7. 010101
bool func7(int a, int b, int c, int d, int e, int f)
{
	if (b == a + 1 && c == a && d == b && e == a && f == b)
	{
		return true;
	}
	else return false;
}

//8. 101010
bool func8(int a, int b, int c, int d, int e, int f)
{
	if (b == a - 1 && c == a && d == b && e == a && f == b)
	{
		return true;
	}
	else return false;
}

//9. 111222
bool func9(int a, int b, int c, int d, int e, int f)
{
	if (a == b && b == c && d == e && e == f)
	{
		return true;
	}
	else return false;
}

//10. 112233
bool func10(int a, int b, int c, int d, int e, int f)
{
	if (a == b && c == d && e == f)
	{
		return true;
	}
	else return false;
}

//Выход
bool quit(int a, int b, int c, int d, int e, int f)
{
	exit(0);
	return true;
}

void main()
{
	int count = 0;
	int menu_index;

	// массив указателей на функции счастья
	lucky_type menu[11] = { func1, func2, func3, func4, func5, func6, func7, func8, func9, func10, quit };

	//удаляю файл, что бы при новом запуске программы, не накапливались старые данные
	remove("result.txt");

	do 
	{
		cout << "1. - sum of three numbers" << endl;
		cout << "2. - 111111" << endl;
		cout << "3. - 123456" << endl;
		cout << "4. - 987654" << endl;
		cout << "5. - 123123" << endl;
		cout << "6. - 123321" << endl;
		cout << "7. - 010101" << endl;
		cout << "8. - 101010" << endl;
		cout << "9. - 111222" << endl;
		cout << "10. - 112233" << endl;
		cout << "11. - exit" << endl;

		cout << "Enter menu number:" << "\n";
		cin >> menu_index;

		//если номер меню не правильный - то выводим соответствующее сообщение
		if (menu_index <= 0 || menu_index > 11)
		{
			cout << "WRONG MENU NUMBER!" << "\n";
			system("pause");
			system("cls");
		}
		else
		{
			//сразу же открываю поток для записи в файл
			ofstream file;
			file.open("result.txt", ios_base::app);
			if (file.is_open())
			{
				//вложенные циклы для перебора чисел и вызова необходимой функции счастья
				for (int a = 0; a <= 9; a++)
				for (int b = 0; b <= 9; b++)
				for (int c = 0; c <= 9; c++)
				for (int d = 0; d <= 9; d++)
				for (int e = 0; e <= 9; e++)
				for (int f = 0; f <= 9; f++)
				{
					//функция счастья выбирается в зависимости от выбранного номера в меню
					//если функция вернет true, то комбинация чисел выведется на экран, запишется в файл, и посчитаются кол-во билетов
					if (menu[menu_index - 1](a, b, c, d, e, f))
					{
						cout << a << b << c << d << e << f << "\n";
						file << a << b << c << d << e << f << "\n";
						count++;
					}
				}
				file << "\n";
				file.close();

				cout << "Tickets saved successfully!" << "\n";
				cout << "Amount of lucky tickets = " << count << "\n";

				system("pause");
				system("cls");
			}
			else
				cout << "Error opening file!" << "\n";
		}
	} while (true);
}