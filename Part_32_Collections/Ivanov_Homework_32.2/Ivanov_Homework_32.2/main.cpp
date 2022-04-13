#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <ctime>
using namespace std;

/*2. Построить частотный словарь слов на основе одного заданного файла. 
	 Вычислить время работы в каждом отдельном случае до сохранения словарей в файл.
	 Использовать резличные виды коллекций:
	 - vector
	 - list
	 - map
	 - unordered_map*/

void main()
{
	//1. ---------------------------------------VECTOR----------------------------------------------------------------
	unsigned int v_start_time = clock();

	//вектор для хранения пар из слов и их кол-ва
	vector <pair<string, size_t>> v;
	//переменная для хранения считанных слов
	string v_word;

	//открываем файл для чтения
	fstream v_file_in("eng_text.txt", ios::in);

	//определяем размер файла
	v_file_in.seekg(0, ios::end);
	long v_size = v_file_in.tellg();
	v_file_in.seekg(0, ios::beg);

	//исходя из размера файла, резервируем память под вектор
	v.reserve(v_size);

	if (!v_file_in.fail())
	{
		while (!v_file_in.eof())
		{
			//сначала считываем слово в строку
			v_file_in >> v_word;

			//удаляем все знаки препинания в словах с помощью лямбда-функции
			auto it = remove_if(v_word.begin(), v_word.end(), [](char c) { return ispunct(c); });
			v_word.erase(it, v_word.end());
			//удаляем все цифры в словах с помощью лямбда-функции
			auto it_2 = remove_if(v_word.begin(), v_word.end(), [](char c) { return isdigit(c); });
			v_word.erase(it_2, v_word.end());

			bool exist = false;

			//проверяем, есть ли уже подобная строка в векторе, если нет - то добавляем
			for (size_t i = 0; i < v.size(); i++) 
			{
				if (v[i].first == v_word)
					{
						exist = true;
						v[i].second++;
						break;
					}
				
			}
			if (exist == false)
				v.push_back(pair <string, size_t>(v_word, 1));

		}
		v_file_in.close();
	}
	else cout << "Error opening file!" << endl;

	//вывод на экран 
	/*for (const auto& pair : v)
	{
		cout << pair.second << " -> " << pair.first << endl;
	}*/

	//вычисляем время работы части кода
	unsigned int v_end_time = clock();
	unsigned int v_search_time = v_end_time - v_start_time;
	cout << "1. Vector runtime = " << v_search_time / 1000.0 << " sec\n";

	//открываем поток для записи в результирующий файл
	fstream v_file_out("1. vector_result.txt", ios::out);

	for (const auto& pair : v)
	{
		v_file_out << pair.second << " -> " << pair.first << endl;
	}
	v_file_out.close();


	//2. ----------------------------------------LIST------------------------------------------------------------------
	unsigned int l_start_time = clock();

	//list для хранения пар из слов и их кол-ва
	list <pair<string, size_t>> l;
	//переменная для хранения считанных слов
	string l_word;

	//открываем файл для чтения
	fstream l_file_in("eng_text.txt", ios::in);

	if (!l_file_in.fail())
	{
		while (!l_file_in.eof())
		{
			//сначала считываем слово в строку
			l_file_in >> l_word;

			//удаляем все знаки препинания в словах с помощью лямбда-функции
			auto it = remove_if(l_word.begin(), l_word.end(), [](char c) { return ispunct(c); });
			l_word.erase(it, l_word.end());
			//удаляем все цифры в словах с помощью лямбда-функции
			auto it_2 = remove_if(l_word.begin(), l_word.end(), [](char c) { return isdigit(c); });
			l_word.erase(it_2, l_word.end());

			bool exist = false;

			//проверяем, есть ли уже подобная строка в списке, если нет - то добавляем
			list<pair<string, size_t>>::iterator pos;

			//перебор всех элементов списка от начала до конца
			for (pos = l.begin(); pos != l.end(); pos++)
			{
				if (pos->first == l_word)
				{
					exist = true;
					pos->second++;
					break;
				}
			}
			if (exist == false)
				l.push_back(pair <string, size_t>(l_word, 1));

		}
		l_file_in.close();
	}
	else cout << "Error opening file!" << endl;

	//вывод на экран 
	/*for (const auto& pair : l)
	{
		cout << pair.second << " -> " << pair.first << endl;
	}*/

	//вычисляем время работы части кода
	unsigned int l_end_time = clock();
	unsigned int l_search_time = l_end_time - l_start_time;
	cout << "2. List runtime = " << l_search_time / 1000.0 << " sec\n";

	//открываем поток для записи в результирующий файл
	fstream l_file_out("2. list_result.txt", ios::out);

	for (const auto& pair : l)
	{
		l_file_out << pair.second << " -> " << pair.first << endl;
	}
	l_file_out.close();


	//3. ----------------------------------------MAP-------------------------------------------------------------------
	unsigned int m_start_time = clock();
	//map для хранения пар из слов и их кол-ва
	map <string, size_t> m;
	//переменная для хранения считанных слов
	string m_word;

	//открываем поток для чтения из исходного файла
	fstream m_file_in("eng_text.txt", ios::in);

	if (!m_file_in.fail())
	{
		while (!m_file_in.eof())
		{
			//считываем слова в строку
			m_file_in >> m_word;

			//удаляем все знаки препинания в словах с помощью лямбда-функции
			auto it = remove_if(m_word.begin(), m_word.end(), [](char c) { return ispunct(c); });
			m_word.erase(it, m_word.end());
			//удаляем все цифры в словах с помощью лямбда-функции
			auto it_2 = remove_if(m_word.begin(), m_word.end(), [](char c) { return isdigit(c); });
			m_word.erase(it_2, m_word.end());

			//добавляем значение в map, если ключ 'm_word' уже существует, то значение увеличится на 1
			m[m_word]++;
		}
		m_file_in.close();
	}
	else cout << "Error opening file!" << endl;

	//вывод на экран
	/*map <string, size_t>::iterator pos;
	for (pos = m.begin(); pos != m.end(); pos++)
	{
		cout << pos->second << " -> " << pos->first << endl;
	}*/

	//вычисляем время работы части кода
	unsigned int m_end_time = clock();
	unsigned int m_search_time = m_end_time - m_start_time;
	cout << "3. Map runtime = " << m_search_time / 1000.0 << " sec\n";

	//открываем поток для записи в результирующий файл
	fstream m_file_out("3. map_result.txt", ios::out);

	for (const auto& pair : m)
	{
		m_file_out << pair.second << " -> " << pair.first << endl;
	}
	m_file_out.close();


	//4. ------------------------------------UNORDERED_MAP--------------------------------------------------------------
	unsigned int m2_start_time = clock();
	//unordered_map для хранения пар из слов и их кол-ва
	unordered_map <string, size_t> m2;
	//переменная для хранения считанных слов
	string m2_word;

	//открываем поток для чтения из исходного файла
	fstream m2_file_in("eng_text.txt", ios::in);

	if (!m2_file_in.fail())
	{
		while (!m2_file_in.eof())
		{
			//считываем слова в строку
			m2_file_in >> m2_word;

			//удаляем все знаки препинания в словах с помощью лямбда-функции
			auto it = remove_if(m2_word.begin(), m2_word.end(), [](char c) { return ispunct(c); });
			m2_word.erase(it, m2_word.end());
			//удаляем все цифры в словах с помощью лямбда-функции
			auto it_2 = remove_if(m2_word.begin(), m2_word.end(), [](char c) { return isdigit(c); });
			m2_word.erase(it_2, m2_word.end());

			//добавляем значение в map, если ключ 'm_word' уже существует, то значение увеличится на 1
			m2[m2_word]++;
		}
		m2_file_in.close();
	}
	else cout << "Error opening file!" << endl;

	//вывод на экран
	/*unordered_map <string, size_t>::iterator pos;
	for (pos = m2.begin(); pos != m2.end(); pos++)
	{
		cout << pos->second << " -> " << pos->first << endl;
	}*/

	//вычисляем время работы части кода
	unsigned int m2_end_time = clock();
	unsigned int m2_search_time = m2_end_time - m2_start_time;
	cout << "4. Unordered_map runtime = " << m2_search_time / 1000.0 << " sec\n";

	//открываем поток для записи в результирующий файл
	fstream m2_file_out("4. unordered_map_result.txt", ios::out);

	for (const auto& pair : m2)
	{
		m2_file_out << pair.second << " -> " << pair.first << endl;
	}
	m2_file_out.close();
}