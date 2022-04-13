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

	// ��������� �� �������, �� ������� ��� �����
	Vertex<T>* from;
	// ��������� �� �������, � ������� ��� �����
	Vertex<T>* to;
	// �������� �����
	T link_title;
	// ����� �����
	unsigned int link_id;
	// ��� ����� �����
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
		// ������� ��������� �� ��������� ����� � ������� ��������
		from->RemoveLink(link_id);
		to->RemoveLink(link_id);
	}

	// �������� ����� �����
	unsigned int GetLinkId()
	{
		return this->link_id;
	}

	// �������� �������� �����
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

	// �������� �������
	T vertex_title;
	// ����� �������
	unsigned int vertex_id;
	// ��� ������� �����
	int vertex_weight;
	// ����, ���������� � ������ �������
	list<Link<T>*> links;

	// �������� ����� ������ � ������ �������
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

	// ����� �������, ����� ��� ������ ���������� ������
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
		// ������� ���� ���� �������� � ��������� �������
		typename list<Link<T>*>::iterator pos = links.begin();
		while (pos != links.end())
		{
			// ��������� �� ������� �����
			Link<T>* currentLink = *(pos);

			pos++;

			// �������� �������� �����
			delete currentLink;
		}
	}


	// �������� �������� �������
	T GetVertexTitle()
	{
		return vertex_title;
	}


	// �������� ���� �������
	unsigned int GetVertexId()
	{
		return this->vertex_id;
	}


	// ���������� ���������� �������� ����
	unsigned int GetLinksCount()
	{
		return links.size();
	}


	void Print()
	{
		cout << "VERTEX: " << vertex_title << endl;

		// ��������� ��� �������� ���� � ������� � ��� ����� Print
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

	//�������� �����
	T graph_title;
	// ����� ��������� �������, ������� ����� �������
	unsigned int vertexId = 0;
	// ���������� ������ �����
	unsigned int vertexCount = 0;
	// ����� ���������� �����, ������� ����� ������
	unsigned int linkId = 0;
	// ���������� ���� �����
	unsigned int linkCount = 0;
	// ��������� �� ������ ������ �����
	unordered_map<T, Vertex<T>*>* vertices;

public:

	// �������������� ������ �������� ������ - ����� ���������� ������
	list<Vertex<T>*> FoundVertices;

	Graph(const T _title)
	{
		this->graph_title = _title;

		// ��������� ������ ��� ������ ������
		vertices = new unordered_map<T, Vertex<T>*>();
	}


	~Graph()
	{
		// ������� ������ ������ � �������� ������ �������
		typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->begin();
		while (pos != vertices->end())
		{
			// ��������� �� ������� �������
			Vertex<T>* currentVertex = pos->second;

			// ����������� ��������� �� ��������� �������
			pos++;

			// ������� ������� �������
			delete currentVertex;
		}

		// �������� ������ ������ �����
		delete vertices;
	}


	// ������� ������� � ������ ������ �� � ��������
	Vertex<T>* FindVertex(const T title)
	{
		typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->find(title);
		if (pos != vertices->end())
			return pos->second;

		return nullptr;
	}


	// ���������� ������� � ����
	unsigned int AddVertex(const T title, unsigned int weight)
	{
		if (FindVertex(title) == 0)
		{
			Vertex<T>* vertex = new Vertex<T>(vertexId++, title, weight);
			if (vertex != nullptr)
			{
				// ���������� ������� � ������ ������
				vertices->insert(make_pair(title, vertex));

				// ��������� ���������� ������ �� 1
				vertexCount++;

				// ���������� Id ��������� �������
				return vertexId - 1;
			}
		}
		return -1;
	}


	// ���������� �����, ������������ ��� �������
	unsigned int AddLink(const T from, const T to, const T title, unsigned int weight)
	{
		// �������� ��������� �� ������� �� �� ���������
		Vertex<T>* vertexFrom = FindVertex(from);
		Vertex<T>* vertexTo = FindVertex(to);

		if (vertexFrom != nullptr && vertexTo != nullptr)
		{
			// �������� ������� �����
			Link<T>* link = new Link<T>(linkId++, title, weight, vertexFrom, vertexTo);
			if (link != nullptr)
			{
				// ���������� ���������� �� ��������� ����� � ������ ���� ������ �� ����������� ������
				vertexFrom->links.push_back(link);
				vertexTo->links.push_back(link);

				// ��������� ���������� ���� �� 1
				linkCount++;

				// ���������� Id ���������� �����
				return linkId - 1;
			}
		}

		return -1;
	}


	// �������� ������� �� Id
	bool RemoveVertex(unsigned int vertexId)
	{
		// ������� ������ ������
		typename unordered_map<T, Vertex<T>*>::iterator pos;
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			Vertex<T>* currentVertex = pos->second;

			// ���� ������� ������ �������
			if (currentVertex->vertex_id == vertexId)
			{
				// �� ������ ���������� ���� ����� ������� ���������� ����, ���������� � ��������� �������
				linkCount -= currentVertex->GetLinksCount();

				// ��������� ���������� ������ �� 1
				vertexCount--;

				// �������� �������
				delete currentVertex;

				vertices->erase(pos);

				return true;
			}
		}

		return false;
	}


	// �������� ������� �� ��������
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

		// ��������� ������ ������ � ���������� ��� �������
		typename unordered_map<T, Vertex<T>*>::iterator pos;
		for (pos = vertices->begin(); pos != vertices->end(); pos++)
		{
			pos->second->Print();
		}
	}

	// �������� �������� ��� ������������� �����
	void GetRoute(T from, T to)
	{

		// �������� ���������� ���������
		FoundVertices.clear();

		// ������ ������� ������������� ������, �������������� �� ������� ��������
		list<Vertex<T>*> oldFront;

		// ������ ������� ���������� ������, �������������� �� ��������� ��������
		list<Vertex<T>*> newFront;

		// ���������� ����� (����� ��������)
		int t = 0;

		Vertex<T>* vertexFrom = FindVertex(from);
		Vertex<T>* vertexTo = FindVertex(to);

		// ���� ��������� � �������� ������� ���������
		if (from == to)
		{
			FoundVertices.push_back(vertexFrom);
			return;
		}

		// ���� ��������� � �������� ������� ������������ � �����
		if (vertexFrom != nullptr && vertexTo != nullptr)
		{
			// ��������� ��������� ������ � �������� �� ��� ������������
			for (typename unordered_map<T, Vertex<T>*>::iterator i = vertices->begin(); i != vertices->end(); i++) 
			{
				i->second->label = -1;
			}

			// �������� ��������� ������� ��� ���������� � ��������� � ������ ��� ������� ���������
			vertexFrom->label = 0;
			oldFront.push_back(vertexFrom);

			// ���� �� ����������� ���������� ������� � ��������������� ��������
			while (oldFront.size() > 0) {

				// ��������� ��� ���������� ������� � ��������������� �������� (��������� ��� ������� � oldFront)
				for (Vertex<T>* vertex : oldFront)
				{
					// ��� ������� ������� ��������� ��������� �������� ������
					for (Link<T>* link : vertex->links) 
					{

						// ����� ��������� �� �������� �������
						Vertex<T>* current = link->to;

						// ���� ������� ������� ��������� �������
						if (current == vertexTo) 
						{

							current->label = t + 1;
							Vertex<T>* reverse = current;

							// ���� �� �������� ��� �������� �����
							while (reverse->label > 0)
							{
								FoundVertices.push_back(reverse);

								// ��������� ��� �������� ������� ��� ������� �� ���� �����
								for (Link<T>* link : reverse->links)
								{
									// ���� � ������� �������� ������� ����� ����� �� 1 ������ ����� ������� reverse
									if (link->from->label == reverse->label - 1)
									{
										// ������������ �� 1 ��� �����
										reverse = link->from;
										break;
									}
								}
							}

							// ���������� ��������� ������� � �����
							FoundVertices.push_back(vertexFrom);

							// ��������� ������ �������������� ������
							FoundVertices.reverse();

							// ����� ���������
							return;
						}

						// ���� ������� �������� ������� �� ��������
						if (current->label == -1)
						{
							// �� �������� � ������� ���� ���������
							current->label = t + 1;

							// �������� ��������� ������� � "����� ����� �����"
							newFront.push_back(current);
						}
					}

				}

				// ����������� ������ �� ������ ������ ����� � ������ (������� ����� �������������� �� ��������� ����)
				oldFront.clear();
				copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
				newFront.clear();

				// ��������� ����� ����
				t++;
			}
		}
		throw exception("Incorrect vertex names!");
	}

	// ������ ���������� ������
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

	//cout << graph.graph_title << endl;		//�������� ������ ���� ����� graph_title public
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


