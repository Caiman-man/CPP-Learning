#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;

template <class T> class Vertex;
template <class T> class Graph;

template <class T>
class Link
{
	friend class Graph<T>;
	friend class Vertex<T>;

	// указатель на вершину, из которой идёт ребро
	Vertex<T>* from;
	// указатель на вершину, в которую идёт ребро
	Vertex<T>* to;
	// название ребра
	T link_title;
	// номер ребра
	unsigned int link_id;
	// вес ребра графа
	int link_weight;

public:

	Link(unsigned int id, const T _title, int weight, Vertex<T>* from, Vertex<T>* to)
	{
		this->link_id = id;
		this->link_weight = weight;
		this->from = from;
		this->to = to;
		this->link_title = _title;
	}

	~Link()
	{
		// удалить указатели на удаляемое ребро в смежных вершинах
		from->RemoveLink(link_id);
		to->RemoveLink(link_id);
	}

	// получить номер ребра
	unsigned int GetLinkId()
	{
		return this->link_id;
	}

	// получить название ребра
	string GetLinkTitle()
	{
		return link_title;
	}

	void Print()
	{
		cout << "LINK: " << link_title << ", From: " << from->GetVertexTitle() << ", To: " << to->GetVertexTitle() << endl;
	}
};

//----------------------------------------------------------------------------------------------------
template <class T>
class Vertex
{
	friend class Graph<T>;
	friend class Link<T>;

	// название вершины
	T vertex_title;
	// номер вершины
	unsigned int vertex_id;
	// вес вершины графа
	int vertex_weight;
	// рёбра, подходящие к данной вершине
	list<Link<T>*> links;

	// удаление ребра ТОЛЬКО у данной вершины
	bool RemoveLink(unsigned int linkId)
	{
		typename list<Link<T>*>::iterator pos;
		for (pos = links.begin(); pos != links.end(); pos++)
		{
			if ((*pos)->link_id == linkId)
			{
				links.erase(pos);
				return true;
			}
		}
		return false;
	}

	// метка вершины, нужна для работы алгоритмов поиска
	int label;

public:

	Vertex(unsigned int id, const T _title, int weight)
	{
		this->vertex_id = id;
		this->vertex_weight = weight;
		this->vertex_title = _title;
	}

	~Vertex()
	{
		// перебор всех рёбер входящих в удаляемую вершину
		typename list<Link<T>*>::iterator pos = links.begin();
		while (pos != links.end())
		{
			// указатель на текущее ребро
			Link<T>* currentLink = *(pos);

			pos++;

			// удаление текущего ребра
			delete currentLink;
		}
	}


	// получить название вершины
	T GetVertexTitle()
	{
		return vertex_title;
	}


	// получить ключ вершины
	unsigned int GetVertexId()
	{
		return this->vertex_id;
	}


	// возвращает количество входящих рёбер
	unsigned int GetLinksCount()
	{
		return links.size();
	}


	void Print()
	{
		cout << "VERTEX: " << vertex_title << endl;

		// перебрать все входящие рёбра и вызвать у них метод Print
		typename list<Link<T>*>::iterator pos;
		for (pos = links.begin(); pos != links.end(); pos++)
		{
			(*pos)->Print();
		}
		cout << endl;
	}
};

//----------------------------------------------------------------------------------------------------
template <class T>
class Graph
{
	friend class Vertex<T>;
	friend class Link<T>;

	//название графа
	T graph_title;
	// номер следующей вершины, которая будет создана
	unsigned int vertexId = 0;
	// количество вершин графа
	unsigned int vertexCount = 0;
	// номер следующего ребра, который будет создан
	unsigned int linkId = 0;
	// количество рёбер графа
	unsigned int linkCount = 0;
	// указатель на список вершин графа
	unordered_map<T, Vertex<T>*>* vertices;

public:

	// Результирующий список названий вершин - ответ алгоритмов поиска
	list<Vertex<T>*> FoundVertices;

	Graph(const T _title)
	{
		this->graph_title = _title;

		// выделение памяти под список вершин
		vertices = new unordered_map<T, Vertex<T>*>();
	}


	~Graph()
	{
		// перебор списка вершин и удаление каждой вершины
		typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->begin();
		while (pos != vertices->end())
		{
			// указатель на текущую вершину
			Vertex<T>* currentVertex = pos->second;

			// переместить указатель на следующую вершину
			pos++;

			// удалить текущую вершину
			delete currentVertex;
		}

		// удаление списка вершин графа
		delete vertices;
	}


	// находит вершину в списке вершин по её названию
	Vertex<T>* FindVertex(const T title)
	{
		typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->find(title);
		if (pos != vertices->end())
			return pos->second;

		return nullptr;
	}


	// добавление вершины в граф
	unsigned int AddVertex(const T title, unsigned int weight)
	{
		if (FindVertex(title) == 0)
		{
			Vertex<T>* vertex = new Vertex<T>(vertexId++, title, weight);
			if (vertex != nullptr)
			{
				// добавление вершины в список вершин
				vertices->insert(make_pair(title, vertex));

				// увеличить количество вершин на 1
				vertexCount++;

				// возвратить Id созданной вершины
				return vertexId - 1;
			}
		}
		return -1;
	}


	// добавление ребра, соединяющего две вершины
	unsigned int AddLink(const T from, const T to, const T title, unsigned int weight)
	{
		// получить указатели на вершины по их названиям
		Vertex<T>* vertexFrom = FindVertex(from);
		Vertex<T>* vertexTo = FindVertex(to);

		if (vertexFrom != nullptr && vertexTo != nullptr)
		{
			// создание объекта ребра
			Link<T>* link = new Link<T>(linkId++, title, weight, vertexFrom, vertexTo);
			if (link != nullptr)
			{
				// добавление указателей на созданное ребро в списки рёбер каждой из соединяемых вершин
				vertexFrom->links.push_back(link);
				vertexTo->links.push_back(link);

				// увеличить количество рёбер на 1
				linkCount++;

				// возвратить Id созданного ребра
				return linkId - 1;
			}
		}

		return -1;
	}


	// удаление вершины по Id
	bool RemoveVertex(unsigned int vertexId)
	{
		// перебор списка вершин
		typename unordered_map<T, Vertex<T>*>::iterator pos;
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			Vertex<T>* currentVertex = pos->second;

			// если найдена нужная вершина
			if (currentVertex->vertex_id == vertexId)
			{
				// из общего количества рёбер графа вычесть количество рёбер, подходящее к удаляемой вершине
				linkCount -= currentVertex->GetLinksCount();

				// уменьшить количество вершин на 1
				vertexCount--;

				// удаление вершины
				delete currentVertex;

				vertices->erase(pos);

				return true;
			}
		}

		return false;
	}


	// удаление вершины по названию
	bool RemoveVertex(const T title)
	{
		typename unordered_map<T, Vertex<T>*>::iterator pos;
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			Vertex<T>* currentVertex = pos->second;

			if (currentVertex->id == title)
			{
				linkCount -= currentVertex->GetLinksCount();
				vertexCount--;

				vertices->erase(pos);

				delete currentVertex;

				return true;
			}
		}

		return false;
	}

	void Print()
	{
		cout << "GRAPH: " << graph_title << endl;
		cout << "Vertices: " << vertexCount << " Links: " << linkCount << endl << endl;

		// перебрать список вершин и напечатать все вершины
		typename unordered_map<T, Vertex<T>*>::iterator pos;
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			pos->second->Print();
		}
	}

	// волновой алгоритм для невзвешенного графа
	void GetRoute(T from, T to)
	{

		// очистить предыдущий результат
		FoundVertices.clear();

		// Список текущих просмотренных вершин, обрабатываемых на текущей итерации
		list<Vertex<T>*> oldFront;

		// Список текущих помеченных вершин, обрабатываемых на следующей итерации
		list<Vertex<T>*> newFront;

		// Дискретное время (номер итерации)
		int t = 0;

		Vertex<T>* vertexFrom = FindVertex(from);
		Vertex<T>* vertexTo = FindVertex(to);

		// если начальная и конечная вершины совпадают
		if (from == to)
		{
			FoundVertices.push_back(vertexFrom);
			return;
		}

		// Если начальная и конечная вершины присутствуют в графе
		if (vertexFrom != nullptr && vertexTo != nullptr)
		{
			// Перебрать множество вершин и пометить их как непосещённые
			for (typename unordered_map<T, Vertex<T>*>::iterator i = vertices->begin(); i != vertices->end(); i++) 
			{
				i->second->label = -1;
			}

			// Пометить начальную вершину как посещённую и поместить в список для текущей обработки
			vertexFrom->label = 0;
			oldFront.push_back(vertexFrom);

			// Пока не закончились помеченные вершины с необработанными соседями
			while (oldFront.size() > 0) {

				// Перебрать все помеченные вершины с необработанными соседями (перебрать все вершины в oldFront)
				for (Vertex<T>* vertex : oldFront)
				{
					// Для текущей вершины перебрать множество соседних вершин
					for (Link<T>* link : vertex->links) 
					{

						// найти указатель на соседнюю вершину
						Vertex<T>* current = link->to;

						// Если текущая вершина оказалась искомой
						if (current == vertexTo) 
						{

							current->label = t + 1;
							Vertex<T>* reverse = current;

							// Цикл по вершинам для возврата назад
							while (reverse->label > 0)
							{
								FoundVertices.push_back(reverse);

								// перебрать все соседние вершины для текущей на пути назад
								for (Link<T>* link : reverse->links)
								{
									// если у текущей соседней вершины номер метки на 1 меньше метки вершины reverse
									if (link->from->label == reverse->label - 1)
									{
										// продвинуться на 1 шаг назад
										reverse = link->from;
										break;
									}
								}
							}

							// добавление начальной вершины в ответ
							FoundVertices.push_back(vertexFrom);

							// переворот списка результирующих вершин
							FoundVertices.reverse();

							// Конец алгоритма
							return;
						}

						// если текущая соседняя вершина не помечена
						if (current->label == -1)
						{
							// то пометить её номером шага алгоритма
							current->label = t + 1;

							// добавить найденную вершину в "новый фронт волны"
							newFront.push_back(current);
						}
					}

				}

				// перемещение вершин из нового фронта волны в старый (который будет обрабатываться на следующем шаге)
				oldFront.clear();
				copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
				newFront.clear();

				// увеличить номер шага
				t++;
			}
		}
		throw exception("Incorrect vertex names!");
	}

	// печать результата поиска
	void PrintFoundPath()
	{
		for (typename list<Vertex<T>*>::iterator i = FoundVertices.begin(); i != FoundVertices.end(); i++)
		{
			cout << (*i)->vertex_title << " ";
		}
	}
};


void main()
{
	Graph<string> graph("test");

	//cout << graph.graph_title << endl;		//работает только если делаю graph_title public
	graph.AddVertex("A", 10);
	graph.AddVertex("B", 20);
	graph.AddVertex("C", 30);
	graph.AddVertex("D", 25);
	graph.AddVertex("E", 21);
	graph.AddLink("A", "B", "link1", 12);
	graph.AddLink("B", "C", "link2", 23);
	graph.AddLink("D", "E", "link3", 2);
	graph.AddLink("C", "D", "link4", 21);
	graph.Print();

	graph.GetRoute("A", "E");
	graph.PrintFoundPath();
}


