#include <iostream>
#include <fstream>
using namespace std;

/*1.������������ ������ ��� ����� � ���������� ������, �� ������� ���� ���� ����� �������.
	��������� ����� ����� ���� �������� �������. ���� ���� ������ ���������, �� ����� � ������.*/

//������� ������
void split_file(const char* file_name, int number_of_parts)
{
    
    //��������� ����� ��� ������ �� ��������� �����
    fstream file_in(file_name, ios::in | ios::binary);

    if (!file_in.fail())
    {
        //��������� ������ �����
        file_in.seekg(0, ios::end);
        long file_size = file_in.tellg();
        file_in.seekg(0, ios::beg);

        //���� ������ ������ ������ ��� ������ �����, �� ����� � ������
        if (number_of_parts > file_size)
        {
            cout << "File size too small!" << endl;
            return;
        }

        //��������� ������ �������� ������
        //long size_of_part = file_size / number_of_parts; // - ��� ����� ������� ����� ��������
        long size_of_part = (int)ceil((double)file_size / number_of_parts);

        //������� �����
        char* buffer = new char[size_of_part];
        //������ ��� �������� ����� ��������������� �����
        char name[128] = "";
        //���������� ��� �������� ������� ���������� �����
        int size_remaining = file_size;

        //���� ��� �������� ������ � ������ � ��� ������
        for (int i = 1; i <= number_of_parts; i++)
        {
            //������ ����� ��� ��� ������ �� �������������� ������ (�� ���� �������� ���� ����)
            strcpy(name, file_name);
            //������� ���������� �����
            strtok(name, ".");
            //��������� ����� � ����� ����������
            sprintf(name, "%s_%d.dat", name, i);

            //��������� ������ ��� i-� ����� �����
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

            //������ � ����� � ���������� � ����
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