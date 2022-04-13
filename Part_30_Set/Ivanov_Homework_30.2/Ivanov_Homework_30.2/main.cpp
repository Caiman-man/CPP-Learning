#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

/*Пользователь вводит название текстового файла.
  Программа удаляет из файла повторяющиеся слова. Порядок других слов не меняется.*/

void main()
{
    string str, file_name;
    vector <string> v;
    set <string> duplicates;
    cout << "Enter source file name: \n";
    cin >> file_name;

    //открываем файл для чтения
    fstream file_in(file_name, ios::in);

    if (!file_in.fail())
    {
        //определяем размер файла
        file_in.seekg(0, ios::end);
        long v_size = file_in.tellg();
        file_in.seekg(0, ios::beg);

        //исходя из размера файла, резервируем память под вектор
        v.reserve(v_size);

        while (!file_in.eof())
        {
            //сначала считываем слово в строку
            file_in >> str;
            //а потом добавляем в вектор
            v.push_back(str);
        }
        file_in.close();
    }
    else cout << "Error opening file!" << endl;

    //вывод до преобразования
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    //удаляем дубликаты с помощью множества и лямбда-функции
    auto it = remove_if(v.begin(), v.end(), [&](const string s) { return !duplicates.insert(s).second; });
    v.erase(it, v.end());

    //вывод после преобразования
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}