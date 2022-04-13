#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

/*������������ ������ �������� 3-� ��������� ������. 
  ��������� ������� � ������ ����� � ��������� �� � ����� ���������� � ��������������� ���� ��� ���������� � �������.*/

void main()
{
    //���������� ��� �������� ����� ������
    char file_name[1024];
    //��������� ��� �������� � �������������� ���������� ����
    set <string> str_set;
    //���������� � ������� ���������� ����������� �����
    string str;

    //������ �� ������ �� ���������
    for (size_t i = 1; i <= 3; i++)
    {
        cout << "Enter source file name #" << i << ": \n";
        cin.getline(file_name, 1024);

        //��������� ����� ��� ������ �� ��������� �����
        fstream file_in(file_name, ios::in);

        if (!file_in.fail())
        {
            while (!file_in.eof())
            {
                //��������� �����
                file_in >> str;
                //������� ��� ����� ���������� � ������
                auto it = remove_if(str.begin(), str.end(), [](char c) { return ispunct(c); });
                str.erase(it, str.end());
                //������� ��� ����� � ������
                auto it_2 = remove_if(str.begin(), str.end(), [](char c) { return isdigit(c); });
                str.erase(it_2, str.end());
                //�������� ����� �� ���������
                str_set.insert(str);
            }
            file_in.close();
        }
        else cout << "Error opening file!" << endl;
    }

    //��������� ����� ��� ������ � �������������� ����
    fstream file_out("result.txt", ios::out);

    set <string>::iterator i;
    for (i = str_set.begin(); i != str_set.end(); i++)
    {
        file_out << *i << endl;
    }

    file_out.close();    
}