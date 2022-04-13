#include <iostream>
#include <fstream>
using namespace std;

/*1.Пользователь вводит имя файла и количество частей, на которое этот файл нужно разбить.
	Последняя часть может быть меньшего размера. Если файл сильно маленький, то отказ в работе.*/

//Деление файлов
void split_file(const char* file_name, int number_of_parts)
{
    
    //открываем поток для чтения из исходного файла
    fstream file_in(file_name, ios::in | ios::binary);

    if (!file_in.fail())
    {
        //вычисляем размер файла
        file_in.seekg(0, ios::end);
        long file_size = file_in.tellg();
        file_in.seekg(0, ios::beg);

        //если размер частей больше чем размер файла, то отказ в работе
        if (number_of_parts > file_size)
        {
            cout << "File size too small!" << endl;
            return;
        }

        //вычисляем размер основных частей
        //long size_of_part = file_size / number_of_parts; // - два байта исчезли после разбивки
        long size_of_part = (int)ceil((double)file_size / number_of_parts);

        //создаем буфер
        char* buffer = new char[size_of_part];
        //строка для хранения имени результирующего файла
        char name[128] = "";
        //переменная для хранения размера оставшейся части
        int size_remaining = file_size;

        //цикл для создания файлов и записи в них данных
        for (int i = 1; i <= number_of_parts; i++)
        {
            //задаем новое имя для одного из результирующих файлов (по сути копируем весь путь)
            strcpy(name, file_name);
            //удаляем расширение файла
            strtok(name, ".");
            //добавляем цифру и новое расширение
            sprintf(name, "%s_%d.dat", name, i);

            //вычисляем размер для i-й части файла
            int part_size;
            if (size_remaining > size_of_part)
            {
                part_size = size_of_part;
                size_remaining -= part_size;
            }
            else
            {
                part_size = size_remaining;
            }

            //читаем в буфер и записываем в файл
            fstream file_out(name, ios::out | ios::binary);
            if (!file_out.fail())
            {
                file_in.read(buffer, part_size);
                file_out.write(buffer, part_size);
            }
            else 
                cout << "Error opening result file!" << endl;

            cout << "File: " << name << " has saved successfully!" <<endl;
            file_out.close();
        }
        file_in.close();
        delete[] buffer;
    }
    else 
        cout << "Error opening source file!" << endl;
}


void main() 
{
    char name[128];
    int parts;
    cout << "Enter the file name: \n";
    cin.getline(name, 128);
    cout << "Enter the number of parts: \n";
    cin >> parts;

    split_file(name, parts);
}