#include <iostream>
#include <fstream>
using namespace std;

/*2.Пользователь вводит количество частей и имена файлов. Программа объединяет их в один файл*/

//Обьединение файлов
void merge_files()
{
    int number_of_parts;
    char file_name[128];
    cout << "Enter the number of parts: \n";
    cin >> number_of_parts;
    cin.get();

    //открываем поток для записи в результирующий файл
    fstream file_out("result.dat", ios::out | ios::binary);

    //
    for (size_t i = 0; i < number_of_parts; i++)
    {
        cout << "Enter source file name #" << i + 1 << ": \n";
        cin.getline(file_name, 128);

        //открываем поток для чтения из исходного файла
        fstream file_in(file_name, ios::in | ios::binary);

        long file_size;
        long buffer_size;
        if (!file_in.fail())
        {
            //вычисляем размер файла
            file_in.seekg(0, ios::end);
            file_size = file_in.tellg();
            file_in.seekg(0, ios::beg);

            char* buffer = new char[file_size];

            //читаем и сразу записываем в файл
            file_in.read(buffer, file_size);
            file_out.write(buffer, file_size);

            file_in.close();
        }
    }
    file_out.close();
}


void main()
{
    merge_files();
}