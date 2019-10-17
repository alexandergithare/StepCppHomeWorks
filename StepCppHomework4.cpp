// StepCppHomework4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getche()
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
			int n = 1, h = 1, x = 0, hw = 1, hh = 1;
			const int w = 118; //line along.
			cout << " ¬ведiть кiлькiсть €русiв (1..5): ";
			cin >> n;
			if (n > 5) n = 5;
			else if (n < 1) n = 1;
			cout << " ¬ведiть висоту першого €руса (1..5): ";
			cin >> h;
			if (h > 5) h = 5;
			else if (h < 1) h = 1;
			cout << " ¬ведiть коефiцiЇнт збiльшенн€ ширини (0..5): ";
			cin >> hw;
			if (hw > 5) hw = 5;
			else if (hw < 0) hw = 0;
			cout << " ¬ведiть рiзницю висот сусiднiх €русiв (0..5): ";
			cin >> hh;
			if (hh > h) hh = h;
			else if (hh < 0) hh = 0;
			cout << " ¬ведiть розташуванн€ об'Їкта (0..118; 60 - центр): ";
			cin >> x;
			if (x > w) x = w;
			else if (x < 0) x = 0;
			cout << endl;
		
			

			for (int k = 0; k < n; k++)
			{
				for (int j = 0; j < h+k*hh; j++)
				{
					for (int i = 0; i <= x+j*(1+k*hw); i++)
					{
						if (i > w) break;
						if (i < x - j*(1+k*hw)) cout << " ";
						else cout << "*";
					}
					cout << endl;
				}

			}
			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getche();
		} while (chv2 == 'r');

		//ex1
		cout << endl << setw(40) << " Task 1. " << endl;
		int ndofm(bool leap_year, int month); //function prototipe
		do
		{
			chv2 = 0;
			const int y0 = 2019, m0 = 0, d0=1;
			int y = 0, m = 0, dy = 0, v=0, dj1=0;
			cout << "¬ведiть рiк i мiс€ць: ";
			cin >> y >> m;
			if (m < 1) m = 1;
			if (m > 12) m = 12;
			dy = y - y0; // how many years amount between of january 01, 2019 and january 01 of entering year.
			int k = 1;
			bool lyi = 0;
			if (dy < 0)
			{
				k = -1;
			}
			else k = 1;
			for (int i = y0; i != y; i += k)
			{
				if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) v += k; // how many leap years in this period
			}

			if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			{
				lyi = 1;// leap year indicator for entering year
				if (k < 0)
				{
					v += k; //+1 day if leap year
				}
			}
				else lyi = 0;
			dj1 = ((7 + (365 * dy + v) % 7) % 7 + d0)%7; // day of week january 01 of entering year.
			
			int dm1 = 0, ndm = 30;
		
			for (int i = 1; i < m; i++)
			{
				dm1 += ndofm(lyi, i);
			}
			dm1 = (dm1 + dj1) % 7; // day of week 
			ndm = ndofm(lyi, m);  // days amount
		//	cout << " " << dj1 << endl << " " << v << endl << " " << dm1 << endl << " " << ndm << endl;

			cout << endl << setw(20) << m << ", " << y << endl;
			int varsetw = 4;
			cout << endl;
			cout << setw(varsetw) << "ѕн" << setw(varsetw) << "¬т" << setw(varsetw) << "—р" << setw(varsetw) << "„т";
			cout << setw(varsetw) << "ѕт" << setw(varsetw) << "—б" << setw(varsetw) << "Ќд" << endl;
			for (int i = 0; i < dm1; i++) cout << setw(varsetw) << " ";
			for (int i = 1; i <= ndm; i++)
			{
				cout << setw(varsetw) << i;
				if ((dm1 + i) % 7 == 0) cout << endl;
			}

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getche();
		} while (chv2 == 'r');
		

		cout << endl << " Press \"space\" to continue or \"enter\" to exit. " << endl;
		chv1 = _getche();
		
	}

	//   system("pause");
	return(0);
}
int ndofm(bool leap_year = 0, int month = 1)
{
	int timevar;
	switch (month)
	{
	case 1: timevar = 31; break;
	case 2: timevar = (leap_year == 1) ? 29 : 28; break;
	case 3: timevar = 31; break;
	case 4: timevar = 30; break;
	case 5: timevar = 31; break;
	case 6: timevar = 30; break;
	case 7: timevar = 31; break;
	case 8: timevar = 31; break;
	case 9: timevar = 30; break;
	case 10: timevar = 31; break;
	case 11: timevar = 30; break;
	case 12: timevar = 31; break;
	}
	return timevar;
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
