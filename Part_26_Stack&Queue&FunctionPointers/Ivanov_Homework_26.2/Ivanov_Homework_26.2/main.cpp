#include <iostream>
#include "Queue.h"
using namespace std;

/*2. Разработать класс Queue, который имеет следующие методы:
	 - Queue(size) - конструктор
	 - деструктор
	 - Enqueue - поставить в очередь
	 - Dequeue - вынуть из очереди (удалить из очереди и вернуть удалённый элемент)
	 - Clear - очистить очередь
	 - Length - получить размер очереди
	 - Peek - вернуть крайний элемент очереди (первый)*/

void main()
{
	Queue queue(5);

	//1. ENQUEUE
	cout << "1. ENQUEUE\n";
	try
	{
		queue.Enqueue(11);
		queue.Enqueue(22);
		queue.Enqueue(33);
		queue.Enqueue(44);
		queue.Enqueue(55);
		queue.Enqueue(66);
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
	queue.Print();


	//2. DEQUEUE
	cout << "\n\n2. DEQUEUE\n";
	try
	{
		cout << queue.Dequeue() << " - deleted element\n";
		cout << queue.Dequeue() << " - deleted element\n";
		cout << queue.Dequeue() << " - deleted element\n";
		cout << queue.Dequeue() << " - deleted element\n";
		cout << queue.Dequeue() << " - deleted element\n";
		cout << queue.Dequeue() << " - deleted element\n";
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
	queue.Print();


	//3. LENGTH
	cout << "\n\n3. LENGTH\n";
	cout << "Queue length = " << queue.Length() << endl;


	//4. CurrentCount
	cout << "\n\n4. CurrentCount\n";
	queue.Enqueue(111);
	queue.Enqueue(222);
	cout << "Amount of Queue elements = " << queue.CurrentCount() << endl;


	//5. PEEK
	cout << "\n\n5. PEEK\n";
	cout << "Last element is: " << queue.Peek() << endl;


	//6. CLEAR
	cout << "\n\n6. CLEAR\n";
	queue.Clear();
	cout << "---------------------\n";
	queue.Print();
}