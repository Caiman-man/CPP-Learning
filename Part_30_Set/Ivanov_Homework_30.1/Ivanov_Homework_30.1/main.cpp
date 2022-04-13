#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

/*Пользователь вводит названия 3-х текстовых файлов. 
  Программа находит в файлах слова и сохраняет их в файле результате в отсортированном виде без повторений в столбик.*/

void main()
{
    //переменная для хранения имени файлов
    char file_name[1024];
    //множество для хранения и автоматической сортировки слов
    set <string> str_set;
    //переменная в которую изначально считываются слова
    string str;

    //чтение из файлов во множество
    for (size_t i = 1; i <= 3; i++)
    {
        cout << "Enter source file name #" << i << ": \n";
        cin.getline(file_name, 1024);

        //открываем поток для чтения из исходного файла
        fstream file_in(file_name, ios::in);

        if (!file_in.fail())
        {
            while (!file_in.eof())
            {
                //считываем слова
                file_in >> str;
                //удаляем все знаки препинания в словах
                auto it = remove_if(str.begin(), str.end(), [](char c) { return ispunct(c); });
                str.erase(it, str.end());
                //удаляем все цифры в словах
                auto it_2 = remove_if(str.begin(), str.end(), [](char c) { return isdigit(c); });
                str.erase(it_2, str.end());
                //помещаем слова во множество
                str_set.insert(str);
            }
            file_in.close();
        }
        else cout << "Error opening file!" << endl;
    }

    //открываем поток для записи в результирующий файл
    fstream file_out("result.txt", ios::out);

    set <string>::iterator i;
    for (i = str_set.begin(); i != str_set.end(); i++)
    {
        file_out << *i << endl;
    }

    file_out.close();    
}