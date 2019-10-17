// StepCppHomework4A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getch()
#include <iomanip>  //For use setw()
#include <ctime>

using namespace std;

//functions space

double myAbs(double x)
{
	return (x >= 0)? x :-x;
}

int fillArr(int A[], int sise, int minel, int maxel)
{
	srand(time(0));
	for (int i = 0; i < sise; i++) A[i] = rand() % (maxel - minel) + minel;
	return 0;
}

double myPower(double x, int n)
{
	double res = 1.0;
	if (n == 0) return 1;
	else if (n == 1) return x;
	else
	{
	int k = (n > 0) ? n : -n;
	for (int i = 1; i <= k; i++)
		{
		res *= x;
		}
	}
	return (n > 0) ? res : 1 / res;
}

long sumRange(int n1, int n2)
{
	int k = (n2 - n1) / myAbs(n2 - n1);
	long s = 0;
	for (int i = n1; i != n2 + k; i += k)
	{
		s += i;
	}
	return s;
}

int perfectNumber(int n1, int n2)
{
	if ((n1 < 0) || (n2 < 0)) return 0;
	int k = (n2 - n1) / myAbs(n2 - n1);
	long s = 0;
	int N = 0;
	for (int i = n1; i != n2 + k; i += k)
	{
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0) s += j;
		}
		if (s == i) { N += 1; cout << "\t" << i; }
		s = 0;
	}
	return N;
}

int plaingCards(bool A[], char C[])
{
	int number = 0;
	//char suit = C[2];
	int number0 = (int)C[0] - 48;
	int number1 = (int)C[1] - 48;
	if (number0 == 0 && (number1 >= 1 && number1 <= 9) || (number0 == 1 && number1 == 0))
	{
		number = ((int)C[1] - 48) + ((int)C[0] - 48) * 10;
	}
	else if ((int)C[0] == 48 && ((int)C[1] == 65 || (int)C[1] == 97)) number = 1;
	else if ((int)C[0] == 48 && ((int)C[1] == 74 || (int)C[1] == 106)) number = 11;
	else if ((int)C[0] == 48 && ((int)C[1] == 81 || (int)C[1] == 113)) number = 12;
	else if ((int)C[0] == 48 && ((int)C[1] == 75 || (int)C[1] == 107)) number = 13;

	char showNumber0 = ' ', showNumber1 = ' ', showSuit = 'S';
	for (int i = 0; i < 35; i++)A[i] = { false };
	A[0] = (number >= 4 && number <= 10);
	A[2] = (number == 2 || number == 3);
	A[4] = A[0];
	A[7] = (number == 10);
	A[10] = (number == 8 || number == 9 || number == 10);
	A[14] = A[10];
	A[15] = (number == 6 || number == 7);
	A[17] = (number < 10 && number % 2 == 1);
	A[19] = A[15];
	A[20] = A[10];
	A[24] = A[10];
	A[27] = A[7];
	A[30] = A[0];
	A[32] = A[2];
	A[34] = A[0];
	switch ((int)C[1])
	{
	case 65: case 97:  {showNumber1 = 'A';} break;
	case 50: {showNumber1 = '2';} break;
	case 51: {showNumber1 = '3';} break;
	case 52: {showNumber1 = '4';} break;
	case 53: {showNumber1 = '5';} break;
	case 54: {showNumber1 = '6';} break;
	case 55: {showNumber1 = '7';} break;
	case 56: {showNumber1 = '8';} break;
	case 57: {showNumber1 = '9';} break;
	case 48: {showNumber1 = '0';} break;
	case 74: case 106: {showNumber1 = 'J';} break;
	case 81: case 113: {showNumber1 = 'Q';} break;
	case 75: case 107: {showNumber1 = 'K';} break;
	default: {showNumber1 = 'Q';}
	}
	
	if (C[0] == '1') showNumber0 = '1';
	
	switch ((int)C[2])
	{
	case 72:
	case 104: showSuit = char(3); break;	//'H' // heart ASCII code
	case 68:
	case 100: showSuit = char(4); break;	//'D' // dimond ASCII code
	case 67:
	case 99: showSuit = char(5); break;		//'C' // club ASCII code
	case 83:
	case 115: showSuit = char(6); break;	//'S' // spade ASCII code
	default: showSuit = char(6);
	}

	cout << endl << endl << setw(31) << showNumber0 << showNumber1 << showSuit << endl;
	cout << setw(30) << " ";
	for (int i = 0; i < 35; i++)
	{
		if (A[i]) cout << setw(2) << showSuit;
		else cout << setw(2) << " ";
		if ((i+1) % 5 == 0) cout << endl << setw(30) << " ";
	}
	cout << setw(9) << showNumber0 << showNumber1 << showSuit << endl;
	return 0;
}

bool happyNumber(int number)
{
	if (number < 100000 && number > 999999) return false;
	else if (number / 100000 + number % 100000 / 10000 + number % 10000 / 1000 == number % 1000 / 100 + number % 100 / 10 + number % 10) return true;
	else return false;
}

bool leapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int dayOfMonthAmount(int month, int year)
{
	int timevar;
	switch (month)
	{
	case 1: timevar = 31; break;
	case 2: timevar = (leapYear(year)) ? 29 : 28; break;
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
	default: timevar = 30;
	}
	return timevar;
}

int date2dateDaysAmount(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int daysamount = 0;
	if (m1 < 1) m1 = 1;
	if (m1 > 12) m1 = 12;
	if (m2 < 1) m2 = 1;
	if (m2 > 12) m2 = 12;
	if (d1 < 1) d1 = 1;
	if (d2 < 1) d2 = 1;
	if (d1 > dayOfMonthAmount(m1, y1)) d1 = dayOfMonthAmount(m1, y1);
	if (d2 > dayOfMonthAmount(m2, y2)) d2 = dayOfMonthAmount(m2, y2);
	int ymin = y1;
	int ymax = y2;
	int mmin = m1;
	int mmax = m2;
	int dmin = d1;
	int dmax = d2;
	if (y1 >= y2) { ymin = y2; ymax = y1; mmin = m2; mmax = m1; dmin = d2; dmax = d1; }
	daysamount = (ymax - ymin)*365; // how many days amount between of january 01, year1 and january 01 of year2.
	int somedaysamount = 0;
	for (int i = ymin; i < ymax; i++)
	{
		if (leapYear(i)) somedaysamount++; // how many leap years in this period
	}
	daysamount += somedaysamount;
	somedaysamount = 0;
	for (int i = 1; i < mmin; i++) somedaysamount += dayOfMonthAmount(i, ymin);
	for (int i = 1; i < mmax; i++) somedaysamount -= dayOfMonthAmount(i, ymin);
	daysamount = daysamount + somedaysamount - dmin + dmax;
	daysamount = myAbs(daysamount);
	return daysamount;
}

int midArray(int A[], int sise)
{
	int s = 0;
	for (int i = 0; i < sise; i++) s += A[i];
	return s / sise;
}

int mpzArray(int A[], int sise, int B[3])
{
	int sp = 0, sm = 0, sz = 0;
	for (int i = 0; i < sise; i++)
	{
		if (A[i] > 0) sp++;
		if (A[i] < 0) sm++;
		if (A[i] == 0) sz++;
	}
	B[0] = sp; B[1] = sm; B[2] = sz;
	return 0;
}

int main()
{
	//setlocale(LC_CTYPE, "ukr");
	char chv1 = 0, chv2 = 0;
	srand(time(0));
	while (chv1 != '\r')
	{
		//goto exf1;
		//ex1:
		cout << endl << endl << setw(40) << " DoubleArr1. " << endl << endl;

		do
		{
			chv2 = 0;
			const int row = 4, col = 5;
			float number;
			float denom;
			float Arr[row][col];
			cout << " Enter first number and denominator: ";
			cin >> number >> denom;
			cout << endl;
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					Arr[i][j] = number;
					number *= denom;
					cout << setw(16) << Arr[i][j];
				//	cout << " " << Arr[i][j] << endl;   //for output in one column
				}
				cout << endl;
			}


			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex2:
		cout << endl << setw(40) << " DoubleArr2. " << endl << endl;
		do
		{
			chv2 = 0;

			const int row = 4, col = 5;
			int number, step;
			int Arr[row][col];
			cout << " Enter first number and step: ";
			cin >> number >> step;
			cout << endl;
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					Arr[i][j] = number;
					number += step;
					cout << setw(8) << Arr[i][j];
				}
				cout << endl;
			}

			cout <<  endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex3:
		cout << endl << setw(40) << " DoubleArr3. " << endl << endl;
		do
		{
			chv2 = 0;

			const int row = 4, col = 5;
			int shiftX, shiftY;
			int A[row][col];
			int B[row][col];
			cout << " Enter shift x (-x or 0 or x) and shift y(-y or 0 or y): ";
			//+x = "right"; -x = "left"; +y = "up"; -y = "down"
			//example: 2 0 = shift right for 2 positions; 0 -3 = shift down for 3 positions
			cin >> shiftX >> shiftY;
			cout << endl;
			//srand(time(0));
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					A[i][j] = rand()%100-50;
					cout << setw(4) << A[i][j];
				}
				cout << endl;
			}
			cout << endl << endl;
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					B[i][j] = A[(row+(i+shiftY%row))%row][(col+(j-shiftX%col))%col];
					cout << setw(4) << B[i][j]; //shiftY%row & shiftX%col for creating multiple cycle offsets
				}								// if shiftY > row or shiftX > col
				cout << endl;
			}
			cout << endl;

			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex4:
		cout << endl  << endl << setw(40) << " DoubleArr4. " << endl << endl;
		const int row = 6, col = 9;
		int A[row][col] = {0};
		int minel = 0, maxel = 100;
		do
		{
			chv2 = 0;
		//	srand(time(0));
		//	const int row = 6, col = 3;
		//	int A[row][col];
		//	int minel = 0, maxel = 100;
			int s = 0, Amax = minel-1, Amin = maxel+1;
			int imax = 0, jmax = 0, imin = 0, jmin = 0;

			for (int i = 0; i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					A[i][j] = rand() % (maxel-minel) + minel;
					s += A[i][j];
					if (A[i][j] < Amin) { Amin = A[i][j]; imin = i; jmin = j; }
					if (A[i][j] > Amax) { Amax = A[i][j]; imax = i; jmax = j; }
					cout << setw(4) << A[i][j];
				}
				cout << endl;
			}
			cout << endl << " s = " << s << endl << " sm = " << s/(row*col*1.0) << endl;
			cout << " Amin = A[" << imin << "][" << jmin << "] = " << Amin << endl;
			cout << " Amax = A[" << imax << "][" << jmax << "] = " << Amax << endl;

			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex5:
		cout << endl << endl << setw(40) << " DoubleArr5. " << endl << endl;
		do
		{
			chv2 = 0;
			int s_row[row] = { 0 };
			int s_col[col] = { 0 };
			int s_all = 0;
			int sise_setw = 5;
			int line_long = (col + 2) * sise_setw;

			for (int i = 0; i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
				cout << setw(sise_setw) << A[i][j];		//A array from the previous task.
				s_all += A[i][j];
				s_row[i] += A[i][j];
				s_col[j] += A[i][j];
				}
				cout << setw(sise_setw) << "|" << setw(sise_setw) << s_row[i] << endl;
			}
			for (int i = 0; i <= line_long; i++) cout << "-";
			cout << endl;
			for (int i = 0; i < col; i++) cout << setw(sise_setw) << s_col[i];
			cout << setw(sise_setw) << "|" << setw(sise_setw) << s_all << endl;


			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//ex6:
		cout << endl << setw(40) << " DoubleArr6. " << endl << endl;
		do
		{
			chv2 = 0;
			const int row = 5, col = 10;
			int min_el = 0, max_el = 100;
			int sise_setw = 5;
			int A[row][col] = { 0 };
			int B[row][col / 2] = { 0 };
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					A[i][j] = rand() % (max_el - min_el) + min_el;
					cout << setw(sise_setw) << A[i][j];
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < row; i++)
			{
				int k = 0;
				for (int j = 0; j < col; j += 2, k++)
				{
					B[i][k] = A[i][j] + A[i][j + 1];
					cout << setw(sise_setw) << B[i][k];
				}
				cout << endl;
			}
			cout << endl;


			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl;
			chv2 = _getch();
		} while (chv2 == 'r');

//exf1:
		cout << endl << setw(40) << " Functions 1, 2. " << endl << endl;
		do
		{

			double x = 1;
			int n = 1;
			cout << " Enter the basis and exponent: ";
			cin >> x >> n;
			cout << "\t" << "myPower(x, n) = " << setprecision(10) << myPower(x, n) << endl << endl;

			int n1 = 0, n2 = 0;
			cout << " Enter int n1 and n2: ";
			cin >> n1 >> n2;
			cout << endl << "\t" << "sumRange(n1, n2) = " << setprecision(10) << sumRange(n1, n2) << endl << endl;

			cout << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');



		//exf3:
		cout << endl << setw(40) << " Functions 3. " << endl << endl;
		do
		{
			chv2 = 0;

			int n1 = 0, n2 = 0;
			cout << " Enter int n1 and n2: ";
			cin >> n1 >> n2;
			cout << endl << "\t" << "Perfect numbers amount = " << perfectNumber(n1, n2) << endl << endl;
					
		
			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//exf4:
		cout << endl << setw(40) << " Functions 4. " << endl << endl;
		do
		{
			chv2 = 0;
			cout << " Enter the number and suit of the plaing card (like 7h or 10S and 'enter'): ";
		
			char C[3] = { '1', '1', '1' };
			int k = 0;
			do
			{
				chv2 = _getche();
				C[k] = chv2;
				if(chv2 !='\r') k++;
			} while ((k <= 2) && chv2 != '\r');
			chv2 = 0;

			if (k == 2)
			{
				C[2] = C[1]; C[1] = C[0]; C[0] = '0';
			}
	
			//cout << endl << "\t" << k << "\t" << C[0] << "\t" << C[1] << "\t" << C[2] << endl;
					   				
			bool A[35] = { 0 };
			plaingCards(A, C);


			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');

		//exf5:
		cout << endl << setw(40) << " Functions 5. " << endl << endl;
		do
		{
			chv2 = 0;
			int number = 0;
			cout << " Enter the number (6 digits) :";
			cin >> number;
			cout << endl;
			if (happyNumber(number)) cout << " You are happy.";
			else cout << " Not in this time.";

			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');


		//exf6:
		cout << endl << setw(40) << " Functions 6. " << endl << endl;
		do
		{
			chv2 = 0;
			int d1, d2, m1, m2, y1, y2;
			cout << " Enter 2 dates (d1 m1 y1 d2 m2 y2): ";
			cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
			cout << endl << endl << "\t" << date2dateDaysAmount(d1, m1, y1, d2, m2, y2) << endl;

			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
			chv2 = _getch();
		} while (chv2 == 'r');

		//exf7:
		cout << endl << setw(40) << " Functions 7, 8. " << endl << endl;
		do
		{
			chv2 = 0;

			const int SiseArr = 10;
			int A[] = { 0 };
			int B[3] = { 0 };
			fillArr(A, SiseArr, 0, 100);
			mpzArray(A, SiseArr, B);
			for (int i = 0;i < SiseArr; i++) cout << "\t" << A[i];
			cout << endl << endl << "\t" << midArray(A, SiseArr) << "\t" << B[0] << "\t" << B[1] << "\t" << B[2];


			cout << endl << endl << " Press \"r\" to repeat or any other key to continue." << endl << endl;
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
