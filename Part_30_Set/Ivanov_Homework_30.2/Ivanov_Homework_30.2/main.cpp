#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

/*������������ ������ �������� ���������� �����.
  ��������� ������� �� ����� ������������� �����. ������� ������ ���� �� ��������.*/

void main()
{
    string str, file_name;
    vector <string> v;
    set <string> duplicates;
    cout << "Enter source file name: \n";
    cin >> file_name;

    //��������� ���� ��� ������
    fstream file_in(file_name, ios::in);

    if (!file_in.fail())
    {
        //���������� ������ �����
        file_in.seekg(0, ios::end);
        long v_size = file_in.tellg();
        file_in.seekg(0, ios::beg);

        //������ �� ������� �����, ����������� ������ ��� ������
        v.reserve(v_size);

        while (!file_in.eof())
        {
            //������� ��������� ����� � ������
            file_in >> str;
            //� ����� ��������� � ������
            v.push_back(str);
        }
        file_in.close();
    }
    else cout << "Error opening file!" << endl;

    //����� �� ��������������
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    //������� ��������� � ������� ��������� � ������-�������
    auto it = remove_if(v.begin(), v.end(), [&](const string s) { return !duplicates.insert(s).second; });
    v.erase(it, v.end());

    //����� ����� ��������������
    cout << "---------------------------------------------------\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}