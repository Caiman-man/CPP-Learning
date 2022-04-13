#include <iostream>
#include "Stack.h"
using namespace std;

/*1. Разработать класс Stack, который имеет следующие методы:
	 - Stack(size) - конструктор
	 - деструктор
	 - Push - положить в стек
	 - Pop - вынуть в стека (удалить из стека и вернуть удалённый элемент)
	 - Clear - очистить стек
	 - Length - получить размер стека
	 - CurrentCount - получить количество элементов в стеке
	 - Peek - вернуть крайний элемент стека
	 - выброс exception "Stack overflow"*/

void main()
{
	Stack stack(5);
	
	//1. PUSH
	cout << "1. PUSH\n";
	try
	{
		stack.Push(11);
		stack.Push(22);
		stack.Push(33);
		stack.Push(44);
		stack.Push(55);
		stack.Push(66);
	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!\n";
	}
	cout << "---------------------\n";
	stack.Print();


	//2. POP
	cout << "\n\n\n2. POP\n";
	try
	{
		cout << stack.Pop() << " - deleted element\n";
		cout << stack.Pop() << " - deleted element\n";
		cout << stack.Pop() << " - deleted element\n";
		cout << stack.Pop() << " - deleted element\n";
		cout << stack.Pop() << " - deleted element\n";
		cout << stack.Pop() << " - deleted element\n";
	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!\n";
	}
	cout << "---------------------\n";
	stack.Print();


	//3. LENGTH
	cout << "\n\n3. LENGTH\n";
	cout << "Stack length = " << stack.Length() << endl;


	//4. CurrentCount
	cout << "\n\n4. CurrentCount\n";
	stack.Push(111);
	stack.Push(222);
	stack.Push(333);
	cout << "Amount of Stack elements = " << stack.CurrentCount() << endl;


	//5. PEEK
	cout << "\n\n5. PEEK\n";
	cout << "Last element is: " << stack.Peek() << endl;


	//6. CLEAR
	cout << "\n\n6. CLEAR\n";
	stack.Clear();
	cout << "---------------------\n";
	stack.Print();
}