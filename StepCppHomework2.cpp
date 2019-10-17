// StepCppHomework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getche()
#include <iomanip>  //For use setw()
//#define і i ????
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
		cout << " Введiть цiле число:  ";
		cin >> number;
		cout << " Ви ввели ";
		if (number == 0) cout << "нуль - ";
		else if (number > 0)	cout << "додатнє ";
		else cout << "вiд'ємне ";
		if (number % 2 == 0) cout << "парне ";
		else cout << "непарне ";
		cout << "число." << endl;
		}
	//ex1
		cout << endl << setw(40) << "Task 1." << endl;
		cout << setw(45) << "Distance determination" << endl;
		{int A, B, C, BA, CA;
		cout << " Введiть координати A, B, C: ";
		cin >> A >> B >> C;
		BA = abs(B - A);
		CA = abs(C - A);
		if (BA > CA)
		{
			cout << " Точка С розташована ближче до точки А, нiж точка В." << endl;
			cout << " Координати точки С: " << C << endl;
			cout << " Вiдстань вiд С до А: " << CA << endl;
		}
		else if (BA < CA)
		{
			cout << " Точка B розташована ближче до точки А, нiж точка C." << endl;
			cout << " Координати точки B: " << B << endl;
			cout << " Вiдстань вiд B до А: " << BA << endl;
		}
		else
		{
			cout << " Вiдстань вiд А до В i вiд А до С однакова i дорiвнює " << BA << endl;
		}
		}
		//ex2
		cout << endl << setw(40) << "Task 2." << endl;
		cout << setw(43) << "Gerontologic." << endl;
		{int years_old, yl = 0, yh = 0;
		char T1[] = "рiк.", T2[] = "роки.", T3[] = "рокiв.";
			cout << " Введiть свiй вiк: ";
			cin >> years_old;
			if (years_old >= 20 && years_old <= 69)
			{
				yl = years_old % 10;
				yh = years_old / 10;
				cout << " Вам ";
				switch (yh)
				{
					case 2: cout << "двадцять ";
						break;
					case 3: cout << "тридцять ";
						break;
					case 4: cout << "сорок ";
						break;
					case 5: cout << "п'ятдесят ";
						break;
					case 6: cout << "шiстдесят ";
						break;
					default: cout << endl << " Помилка" << endl;
				}
				switch (yl)
				{
				case 1: cout << "один " << T1 << endl;
					break;
				case 2: cout << "два " << T2 << endl;
					break;
				case 3: cout << "три " << T2 << endl;
					break;
				case 4: cout << "чотири " << T2 << endl;
					break;
				case 5: cout << "п'ять " << T3 << endl;
					break;
				case 6: cout << "шiсть " << T3 << endl;
					break;
				case 7: cout << "сiм " << T3 << endl;
					break;
				case 8: cout << "вiсiм " << T3 << endl;
					break;
				case 9: cout << "дев'ять " << T3 << endl;
					break;
				default: cout << T3 << endl;
				}
			}
			else cout << " Вибачте, але Ви не пiдходите для нашого дослiдження." << endl;
		}
		//ex3
		cout << endl << setw(40) << "Task 3." << endl;
		cout << setw(50) << "Chess. Black or White." << endl;
		{int x, y;
		cout << " Введiть координати поля шахiвницi (1..8) (1..8): ";
		cin >> x >> y;
		if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
		{
			if ((x + y) % 2 == 0) cout << " Ви ввели координати чорного поля." << endl;
			else cout << " Ви ввели координати бiлого поля." << endl;
		}
		else cout << " Невiрнi координати." << endl;
		}
		//ex4,5,6,7,8,9
		cout << endl << setw(40) << "Task 4, 5, 6, 7, 8, 9." << endl;
		cout << setw(37) << "Chess. Continue." << endl << endl;
		do
		{
			chv2 = 0;
			{int x1, y1, x2, y2;
			bool b1 = 0, b2 = 0, l = 0, d = 0;
			cout << " Введiть координати початкового поля (1..8) (1..8): ";
			cin >> x1 >> y1; // При введенні некоректного символа (char замість int) відбувається збій.
			cout << " Введiть координати кiнцевого поля (1..8) (1..8): "; //Поки не розібрався.
			cin >> x2 >> y2;
			if (!(x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && x2 >= 1 && x2 <= 8 && y2 >= 1 && y2 <= 8))
			{
				cout << " Невiрнi координати." << endl;
			}
			else if (x1 == x2 && y1 == y2)
			{
				cout << " Координати клiтин спiвпадають." << endl;
			}
			else
			{
				b1 = ((x1 + y1) % 2 == 0); //color1
				b2 = ((x2 + y2) % 2 == 0); //color2
				if (b1) cout << " Клiтина1 чорна." << endl;	//color1
				else cout << " Клiтина1 бiла." << endl;
				if (b2) cout << " Клiтина2 чорна." << endl; //color2
				else cout << " Клiтина2 бiла." << endl;
				if (b1 == b2) cout << " Колiр клiтин спiвпадає." << endl; //matching colors
				else cout << " Колiр клiтин не спiвпадає." << endl;
				if ((x1 == x2) && (y1 != y2) || (x1 != x2) && (y1 == y2))
				{
					cout << " Тура може перейти за один хiд з одного поля на iнше." << endl; //Rook moving
					l = 1; // moving the rook is possible
				}
				else cout << " Тура НЕ може перейти за один хiд з одного поля на iнше." << endl;
				if ((abs(x2 - x1) - abs(y2 - y1)) == 0)
				{
					d = 1; // bishop moving is possible
					cout << " Слон може перейти за один хiд з одного поля на iнше." << endl;
				}
				else cout << " Слон НЕ може перейти за один хiд з одного поля на iнше." << endl;
				if (((abs(x2 - x1) + abs(y2 - y1)) == 3) && (x2 != x1) && (y2 != y1)) // Knight moving
					cout << " Кiнь може перейти за один хiд з одного поля на iнше." << endl;
				else cout << " Кiнь НЕ може перейти за один хiд з одного поля на iнше." << endl;
				if (l || d) //Quin move like Rook or Bishop 
					cout << " Ферзь може перейти за один хiд з одного поля на iнше." << endl;
				else cout << " Ферзь НЕ може перейти за один хiд з одного поля на iнше." << endl;
				if ((abs(x2 - x1) <= 1) && (abs(y2 - y1) <= 1)) //King move not more 1 cell
					cout << " Король може перейти за один хiд з одного поля на iнше." << endl;
				else cout << " Король НЕ може перейти за один хiд з одного поля на iнше." << endl;

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
