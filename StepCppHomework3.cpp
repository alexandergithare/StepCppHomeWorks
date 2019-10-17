// StepCppHomework3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getche()
#include <iomanip>  //For use setw()
//#define i i ????
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	char chv1 = 0, chv2 = 0;
	while (chv1 != '\r')
	{
		//ex0
		cout << endl << setw(40) << " Task 0. " << endl;
	//	{int a = 0, b = 0, k = 1, s = 0;
		do
		{
			int k = 1, n = 0;
			long a = 0, b = 0, s = 0;
			chv2 = 0;
			cout << " Введiть цiле число:  ";
			cin >> a;
			b = a;
			if (a <= 500) k = 1; //increment direction
			else k = -1;		 //for a>500
			while (b != 500)
			{
				s += b;
				b += k;
				n += 1;
			} 
			s += 500;
			n += 1;
			cout << " Сума чисел вiд " << a << " до 500 дорiвнює " << s << endl;
			cout << " Кiлькiсть доданкiв: " << n << endl;
			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
	//	}
		//ex1
		cout << endl << setw(40) << "Task 1." << endl;
		do
		{
			chv2 = 0;
			long double x = 0, y = 0, p1 = 0, p2 = 0;
			cout << setw(20) << " Введiть основу, x: ";
			cin >> x;
			cout << setw(20) << " Введiть ступiнь, у: ";
			cin >> y;
			cout << setw(20) << " pow(x,y) = " <</*setprecision(10) <<*/ pow(x, y) << endl;
			cout << setw(20) << " exp(y * log(x)) = " <</*setprecision(10) <<*/ exp(y * log(x)) << endl;

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
		
		//ex2
		cout << endl << setw(40) << "Task 2." << endl;
		{
			int i=1, s=0;
			for (i = 1; i <= 1000; i++)
			{
				s += i;
			}
			s /= i;
			cout << endl << " Середнє арифметичне всiх цiлих чисел вiд 1 до 1000 дорiвнює " << s << endl;
		}
		//ex3
		cout << endl << setw(40) << "Task 3." << endl;
		do
		{
			int a, n = 0;
			long long p = 1;
			chv2 = 0;
			cout << " Введiть число а вiд 1 до 20: ";
			cin >> a;
			if (a < 1 || a>20)
				cout << " Введене число не вiдповiдає завданим умовам." << endl;
			else
			{
				for (int i = a; i <= 20; i++)
				{
					p *= i;
					n += 1;
				}
				cout << " Добуток всiх цiлих чисел вiд " << a << " до 20 дорiвнює " << p << endl;
				cout << " Кiлькiсть множникiв дорiвнює " << n << endl;
			}
			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
		//ex4
		cout << endl << setw(40) << "Task 4" << endl;
		cout << setw(45) << "Таблиця множення." << endl << endl;
		do
		{
			int k;
			chv2 = 0;
			cout << " Введiть цiле число вiд 0 до 9: ";
			cin >> k;
			cout << endl;
			if(k<0 || k>9)
				cout << " Введене число не вiдповiдає завданим умовам." << endl;
			else
			{
				for (int i = 0; i < 5; i++)
				{
					cout << setw(20) << k << " x " << i << " = " << setw(2) << (k * i);
					cout << setw(20) << k << " x " << i+5 << " = " << setw(2) << (k * (i+5)) << endl;
				}
			}
			cout << endl << " Press \"r\" to repeat or any other key to exit." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
		//ex5
		cout << endl << setw(40) << "Task 5" << endl;
		do
		{
			int n, inp=0;
			chv2 = 0;
			cout << " Введiть цiле число:  ";
			cin >> n;
			cout << " Для виведення чергового числа натиснiть пробiл, для припинення натиснiть ESC." << endl << endl << " ";
			for (int i = 0; i <= n; i++)
			{
				inp = _getch();   //wait keyboard
				if (inp == 27) break; //stop if ESC (code 27) - because very long time for output big number.
				if(inp==32)			 //print number if SPACE (code 32) - output numbers while 'SPACE' pressed.
				cout << i << " ";
			}
			cout << endl << endl << " Press \"r\" to repeat or any other key to exit." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
		//ex6, ex7
		cout << endl << setw(40) << "Task 6, 7." << endl;
		do
		{
			int a, b, c=0;
			long s = 0;
			chv2 = 0;
			cout << " Введiть межi дiапазона цiлих чисел а i в: ";
			cin >> a >> b;
			cout << endl << " ";
			if (a > b)
			{
				c = a;
				a = b;
				b = c;
			}
			if (a % 2 == 0)
			{
				cout << " Парнi числа дiапазона:" << endl << " ";
				for (int i = a; i <= b; i += 2) cout << i << " ";
				cout << endl << " Непарнi числа дiапазона:" << endl << " ";
				for (int i = a + 1; i <= b; i += 2) cout << i << " ";
			}
			else
			{
				cout << " Парнi числа дiапазона:" << endl << " ";
				for (int i = a+1; i <= b; i += 2) cout << i << " ";
				cout << endl << " Непарнi числа дiапазона:" << endl << " ";
				for (int i = a; i <= b; i += 2) cout << i << " ";
			}
			cout << endl << " Числа дiапазону, кратнi до 7:" << endl << " ";
			for (int i = a; i <= b; i++)
			{
				s += i;
				if (i % 7 == 0) cout << i << " ";
			}
			cout << endl << endl << " Сума всiх чисел дiапазону дорiвнює " << s << endl;

			cout << endl << " Press \"r\" to repeat or any other key to exit." << endl;
			chv2 = _getche();
			cout << "\r " << endl;
		} while (chv2 == 'r');
	//	ex8
		cout << endl << setw(40) << "Task 8" << endl;
		do
		{
			int n=1, s = 0;
			chv2 = 0;
			cout << " Вводьте числа: " << endl << " ";
			while (n!=0)
			{
				cin >> n;
				s += n;
				cout << " ";
			}
			cout << endl << " Сума введених чисел дорiвнює " << s << endl;
			cout << endl << " Press \"r\" to repeat or any other key to exit." << endl;
			chv2 = _getche();
		} while (chv2 == 'r');


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
