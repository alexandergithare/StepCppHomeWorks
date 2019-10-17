// StepCppHomework5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getch()
#include <iomanip>  //For use setw()

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	char chv1 = 0, chv2 = 0;
	while (chv1 != '\r')
	{
		//ex0
		cout << endl << setw(40) << " Task 0. " << endl;

		do
		{
			chv2 = 0;
			int a = 1;
			char x = 'a';
			cout << " ����i�� ����i� �i���� (1.. 20): ";
			cin >> a;
			if (a < 1) a = 1;
			if (a > 20) a = 20;
			cout << " ����i�� ���i��� �i���� (a, b, c, d, e, f, g, h, i, k): ";
			cin >> x;
			cout << endl << "\t\t";
			switch (x)
			{
			case 'a':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i >= j) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'b':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i <= j) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'c':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i >= j && i<=(a-1-j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'd':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i <= j && i>=(a-1-j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'e':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i >= j && i <= (a - 1 - j) || i <= j && i >= (a - 1 - j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'f':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i <= j && i <= (a - 1 - j) || i >= j && i >= (a - 1 - j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'g':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i <= j && i <= (a - 1 - j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'h':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i >= j && i >= (a - 1 - j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'i':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i <= (a-1-j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			case 'k':
			{
				for (int j = 0; j < a; j++)
				{
					for (int i = 0; i < a; i++)
					{
						if (i >= (a-1-j)) cout << " *";
						else cout << "  ";
					}
					cout << endl << "\t\t";
				}
				break;
			}
			default: cout << " ������ ���i���� �i���� �� ��������������." << endl;
			}
			
			

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
			cout << "\b";
		} while (chv2 == 'r');

		//ex1, 2.
		cout << endl << setw(40) << " Task 1, 2. " << endl;
		int a = 0, b = 0, c = 0;
		int n0 = 0, n2 = 0, n3 = 0;
		for (int i = 100; i < 1000; i++)
		{
			a = i % 10;
			b = i / 10 % 10;
			c = i / 100;
			if ((a == b || b == c || a == c) && !(a == b && b == c)) n2 += 1;
			if (a == b && b == c) n3 += 1;
			if (a != b && b != c && a != c) n0 += 1;
		}
		cout << " �i���i��� �i��� ����� � �i������i �i� 100 �� 999, � ���� ��i ����� �i��i ���i���� " << n0 << endl;
		cout << " �i���i��� �i��� ����� � �i������i �i� 100 �� 999, � ���� ��i ����� �������i ���i���� " << n2 << endl;
		cout << " �i���i��� �i��� ����� � �i������i �i� 100 �� 999, � ���� ��� ����� �������i ���i���� " << n3 << endl;
		cout << " ������i�� ����-��� ����i��" << endl;
		_getch();
		//ex3
		cout << endl << setw(40) << " Task 3. " << endl;
		do
		{
			chv2 = 0;
			long long x;
			int n = 0, y=0;
			cout << " ����i�� ����-��� �i�� ����� :";
			cin >> x;
			n = log10(x); // number order
			//cout << n << endl << " ";
			cout << " ";
			for (int i = n; i >= 0; i--)
			{
				y = x / pow(10,i);
				if (y != 3 && y != 6) cout << y;
				x = x - y*pow(10,i);
			}

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex4
		cout << endl << setw(40) << " Task 4. " << endl;
		do
		{
			chv2 = 0;
			long long a = 0;
			int n = 0;
			cout << " ����i�� ����-��� �i�� ����� �i���� �� 0: ";
			cin >> a;
			a = abs(a);
			cout << " ����� �, ��� ���� ������� ����� �i������ �� �*� i �� �i������ �� �*�*�: " << endl;
			for (long long i = 2; i <= sqrt(a); i++)
			{
				if (a % (i * i) == 0 && a % (i * i * i) != 0)
				{
					cout << i << " ";
					n += 1;
				}
			}
			if (n == 0) cout << " ����� ����� �� ��������." << endl;
			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl << " ";
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex5
		cout << endl << setw(40) << " Task 5. " << endl;
		do
		{
			chv2 = 0;
			long a = 0, b=0, y=0;
			long long s = 0;
			int n = 1;
			cout << " ����i�� ����-��� �i�� ����� �i���� �� 0: ";
			cin >> a;
			a = abs(a);
			b = a;
			n = log10(a) + 1; // digit amount
			for (int i = n; i >= 0; i--)
			{
				y = b / pow(10, i);
				s+=y;
				b = b - y * pow(10, i);
			}
			cout << " �i���i��� ������i� n =  " << n << endl;
			cout << " ���� ���� s = " << s << endl;
			cout << " s * s * s = " << s*s*s << endl;
			cout << " a * a = " << a * a << endl;
			if (s * s * s == a * a) cout << " ��� ���� ���� ��������� ����� ���i���� ���� ��������. " << endl;
			else cout << " ��� ���� ���� ��������� ����� �� ���i���� ���� ��������. " << endl;

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
		} while (chv2 == 'r');




		//ex6

		cout << endl << setw(40) << " Task 6. " << endl;
		do
		{
			chv2 = 0;
			long long a = 0;
			int n=0;
			cout << " ����i�� �i�� �����: ";
			cin >> a;
			cout << " �����, �� ��i ������� ����� �i������ ��� �������: " << endl << " ";
			for (long long i = 1; i <= a; i++)
			{
				if (a % i == 0)
				{
					cout << " " << i;
					n += 1;
				}
			}
			if (n == 0) cout << " ����� ����� �� ��������.";

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
		} while (chv2 == 'r');

		//ex7

		cout << endl << setw(40) << " Task 7. " << endl;
		do
		{
			chv2 = 0;
			long long a = 0, b=0, c=0;
			int n = 0;
			cout << " ����i�� ��� �i��� ����� a i b: ";
			cin >> a >> b;
			if (a < b) c = a;
			else c = b;
			cout << " �����, �� ��i a i b ��������� �i������ ��� �������: " << endl << " ";
			for (long long i = 1; i <= c; i++)
			{
				if (a % i == 0 && b % i == 0)
				{
					cout << " " << i;
					n += 1;
				}
			}
			if (n == 0) cout << " ����� ����� �� ��������.";

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
		} while (chv2 == 'r');

		cout << endl << " Press \"space\" to continue or \"enter\" to exit. " << endl;
		chv1 = _getch();

	}

	//   system("pause");
	return(0);
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
