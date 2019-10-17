// StepCppHomework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getche()
#include <iomanip>  //For use setw()
//#define � i ????
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	char chv1 = 0, chv2 = 0;
	while (chv1 != '\r')
	{
	//ex0
		cout << endl << setw(40) << " Task 0. " << endl;
		cout << setw(45) << "Number Analisis" << endl;
		{int number = 0;
		cout << " ����i�� �i�� �����:  ";
		cin >> number;
		cout << " �� ����� ";
		if (number == 0) cout << "���� - ";
		else if (number > 0)	cout << "������ ";
		else cout << "�i�'���� ";
		if (number % 2 == 0) cout << "����� ";
		else cout << "������� ";
		cout << "�����." << endl;
		}
	//ex1
		cout << endl << setw(40) << "Task 1." << endl;
		cout << setw(45) << "Distance determination" << endl;
		{int A, B, C, BA, CA;
		cout << " ����i�� ���������� A, B, C: ";
		cin >> A >> B >> C;
		BA = abs(B - A);
		CA = abs(C - A);
		if (BA > CA)
		{
			cout << " ����� � ����������� ������ �� ����� �, �i� ����� �." << endl;
			cout << " ���������� ����� �: " << C << endl;
			cout << " �i������ �i� � �� �: " << CA << endl;
		}
		else if (BA < CA)
		{
			cout << " ����� B ����������� ������ �� ����� �, �i� ����� C." << endl;
			cout << " ���������� ����� B: " << B << endl;
			cout << " �i������ �i� B �� �: " << BA << endl;
		}
		else
		{
			cout << " �i������ �i� � �� � i �i� � �� � �������� i ���i���� " << BA << endl;
		}
		}
		//ex2
		cout << endl << setw(40) << "Task 2." << endl;
		cout << setw(43) << "Gerontologic." << endl;
		{int years_old, yl = 0, yh = 0;
		char T1[] = "�i�.", T2[] = "����.", T3[] = "���i�.";
			cout << " ����i�� ��i� �i�: ";
			cin >> years_old;
			if (years_old >= 20 && years_old <= 69)
			{
				yl = years_old % 10;
				yh = years_old / 10;
				cout << " ��� ";
				switch (yh)
				{
					case 2: cout << "�������� ";
						break;
					case 3: cout << "�������� ";
						break;
					case 4: cout << "����� ";
						break;
					case 5: cout << "�'������� ";
						break;
					case 6: cout << "�i������� ";
						break;
					default: cout << endl << " �������" << endl;
				}
				switch (yl)
				{
				case 1: cout << "���� " << T1 << endl;
					break;
				case 2: cout << "��� " << T2 << endl;
					break;
				case 3: cout << "��� " << T2 << endl;
					break;
				case 4: cout << "������ " << T2 << endl;
					break;
				case 5: cout << "�'��� " << T3 << endl;
					break;
				case 6: cout << "�i��� " << T3 << endl;
					break;
				case 7: cout << "�i� " << T3 << endl;
					break;
				case 8: cout << "�i�i� " << T3 << endl;
					break;
				case 9: cout << "���'��� " << T3 << endl;
					break;
				default: cout << T3 << endl;
				}
			}
			else cout << " �������, ��� �� �� �i������� ��� ������ ����i������." << endl;
		}
		//ex3
		cout << endl << setw(40) << "Task 3." << endl;
		cout << setw(50) << "Chess. Black or White." << endl;
		{int x, y;
		cout << " ����i�� ���������� ���� ���i����i (1..8) (1..8): ";
		cin >> x >> y;
		if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
		{
			if ((x + y) % 2 == 0) cout << " �� ����� ���������� ������� ����." << endl;
			else cout << " �� ����� ���������� �i���� ����." << endl;
		}
		else cout << " ���i��i ����������." << endl;
		}
		//ex4,5,6,7,8,9
		cout << endl << setw(40) << "Task 4, 5, 6, 7, 8, 9." << endl;
		cout << setw(37) << "Chess. Continue." << endl << endl;
		do
		{
			chv2 = 0;
			{int x1, y1, x2, y2;
			bool b1 = 0, b2 = 0, l = 0, d = 0;
			cout << " ����i�� ���������� ����������� ���� (1..8) (1..8): ";
			cin >> x1 >> y1; // ��� ������� ������������ ������� (char ������ int) ���������� ���.
			cout << " ����i�� ���������� �i������� ���� (1..8) (1..8): "; //���� �� ���������.
			cin >> x2 >> y2;
			if (!(x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && x2 >= 1 && x2 <= 8 && y2 >= 1 && y2 <= 8))
			{
				cout << " ���i��i ����������." << endl;
			}
			else if (x1 == x2 && y1 == y2)
			{
				cout << " ���������� ��i��� ��i��������." << endl;
			}
			else
			{
				b1 = ((x1 + y1) % 2 == 0); //color1
				b2 = ((x2 + y2) % 2 == 0); //color2
				if (b1) cout << " ��i����1 �����." << endl;	//color1
				else cout << " ��i����1 �i��." << endl;
				if (b2) cout << " ��i����2 �����." << endl; //color2
				else cout << " ��i����2 �i��." << endl;
				if (b1 == b2) cout << " ���i� ��i��� ��i�����." << endl; //matching colors
				else cout << " ���i� ��i��� �� ��i�����." << endl;
				if ((x1 == x2) && (y1 != y2) || (x1 != x2) && (y1 == y2))
				{
					cout << " ���� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl; //Rook moving
					l = 1; // moving the rook is possible
				}
				else cout << " ���� �� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				if ((abs(x2 - x1) - abs(y2 - y1)) == 0)
				{
					d = 1; // bishop moving is possible
					cout << " ���� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				}
				else cout << " ���� �� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				if (((abs(x2 - x1) + abs(y2 - y1)) == 3) && (x2 != x1) && (y2 != y1)) // Knight moving
					cout << " �i�� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				else cout << " �i�� �� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				if (l || d) //Quin move like Rook or Bishop 
					cout << " ����� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				else cout << " ����� �� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				if ((abs(x2 - x1) <= 1) && (abs(y2 - y1) <= 1)) //King move not more 1 cell
					cout << " ������ ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;
				else cout << " ������ �� ���� ������� �� ���� �i� � ������ ���� �� i���." << endl;

			}
			}
			cout << endl << " Press \"r\" to repeat or any other key to exit." << endl;
			chv2 = _getche();
		}
		while (chv2 == 'r');

		cout << endl << " Press \"space\" to continue or \"enter\" to exit. " << endl;
		chv1 = _getche();
	}

	//   system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
