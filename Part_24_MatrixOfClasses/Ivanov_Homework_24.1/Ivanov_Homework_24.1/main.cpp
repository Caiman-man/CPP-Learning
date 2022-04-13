#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

/*1. ����������� ����� Group, ������� �������� ������������ ������ ��������� (����� Student), � ����� ��������� ������:
	 - ����������� �� ���������						+
	 - ����������� � �����������					+
	 - ������ �����������							+
	 - ����������									+
	 - op = ��� ����������� �����					+
	 - op + ��� ���������� ���������				+
	 - op += st ��� ���������� ���������			+
	 - op += gr2 ��� ���������� �����				�� ��������
	 - op == ��� ��������� �����					+
	 - op >= ��� ��������� �����					+
	 - op[] ��� ��������� ������� � ��������		+
	 - op() ��� ���������� ��������� � ������		�� ������
	 - Add(Student) - ���������� ��������			+
	 - Print										+
	 - Save											+
	 - Load											�� ������																																	*/

void main()
{
	//������ ��������� �������� ������ Student (�����������)
	Student* s1 = new Student("Alex", "Petrov", 19, "Lenina st. 12", 23, 3.5);
	Student* s2 = new Student("Ivan", "Demidoff", 21, "Mayakovskogo st. 14", 24, 3.7);
	Student* s3 = new Student("Vasya", "Demidoff", 25, "Ostrovskogo st. 15", 25, 4.7);
	Student* s4 = new Student("Lena", "Petrova", 27, "Moskovskaya st. 16", 27, 4.8);
	Student* s5 = new Student("Anna", "Karenina", 24, "Donetskay st. 17", 26, 3.1);
	Student* s6 = new Student("Oleg", "Sergeev", 18, "Ilyicha st. 18", 34, 3.9);
	Student* s7 = new Student("Igor", "Karkarov", 17, "Cheluskintsev st. 19", 29, 3.2);
	Student* s8 = new Student("Vasiliy", "Makarevich", 20, "Mira st. 20", 39, 3.6);

	//1. �������� ����� ������, � ���������� ���������
	Group g;
	g.Add(s1);
	g.Add(s2);
	g.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//2. �������� ������ ������, � ����� ������������ �����������
	Group g2 = g;
	g2.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//3. �������� ������� ������, � ����� ��������� =
	Group g3;
	g3 = g;
	g3.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//4. ����� ��������� +=  ��� ���������� ��������� � ������
	g3 += s3;
	g3 += s4;
	g3.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//5. ����� ��������� +  ��� ���������� ��������� � ������
	//(� ������ ���������, ������ �� �����������, � ��� ������� ���������� ������� 6�� �������� - ������������� ����������)
	try
	{
		g3 + s5;
		g3 + s6;
	}
	catch (const char* exception)
	{
		cout << "ERROR! " << exception << endl;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}
	g3.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//6. ����� ��������� ==
	cout << (g == g2) << endl;	//��� ������ ����� 1, ��� ��� ������ �����
	cout << (g == g3) << endl;	//��� ������ ����� 0, ��� ��� ������ �� �����
	cout << "---------------------------------------------------------------------------------------\n";


	//7. ����� ��������� >=
	cout << (g >= g2) << endl;	//��� ������ ����� 1, ��� ��� ������ �����
	cout << (g >= g3) << endl;	//��� ������ ����� 0, ��� ��� g3 ������ ��� g
	cout << "---------------------------------------------------------------------------------------\n";


	//8. ����� ���������[]
	//������� ��������� ������ Student � ����������� ��� 2�� �������� �� 1� ������
	Student* s9 = g[1];			//��� "Ivan Demidoff"
	s9->Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//9. ����� ��������� += ��� ���������� ������ (�� ��������!)
	//������� ��� ���� ������ � ��������� ���� ���������
	Group g4;
	g4.Add(s7);
	g4.Add(s8);
	//�������� �������� += � ������� �� ����� ������ (�� ����� ��������� ������ �������� �� ������ ������������ ������)
	g += g4;
	g.Print();
	cout << "---------------------------------------------------------------------------------------\n";


	//10. ���������� 1� ������ � ����
	g3.Save("result.txt");
}



