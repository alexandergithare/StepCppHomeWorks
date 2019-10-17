// StepCppHomework7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getch()
#include <iomanip>  //For use setw()
#include <ctime>
#include <typeinfo.h>
//#include <windows.h>

using namespace std;


//Function spase.

void printNchar(int n = 50, char t = ' ')
{
	for (int i = 0; i < n; i++) cout << t;
	return;
}

template<class T>
T** createArr(T** p, int row, int col)
{
	if (p == nullptr) p = new T*[row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
	return p;
}

template<class T>
void dellArr(T* p, int row)
{
	for (int i = 0; i < row; i++)
		delete[] p[i];
	return;
}

template<class T1>
void initRandArr(T1* a, int row, int col, int min, int max)
{
	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			double x = 1.0 / ((double)RAND_MAX + 1);
			T1 y = (T1)(x * rand() * (max - min + 1) + min);
			*(a + i*col + j) = y;
		//	a++;
		}
	}
	return;
}



template<class T1>
void fillArr(T1* a, int row, int col, T1 x)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(a + i * col + j) = x;
		//	a++;
		}
	}
	return;
}

template<class T1>
void showArr(T1* a, int row, int col, int setwn = 5)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(setwn) << setprecision(3) << *(a + i * col + j);
		}
		cout << endl << endl;
	}
	return;
}

template<class T1>
void copyArr(T1* a, T1* b, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(b + i * col + j) = *(a + i * col + j);
		}
	}
	return;
}

template<class T1>
void reversCopyArr(T1* a, T1* b, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(b + i * col + j) = *(a + (row - i -1 ) * col + (col - j - 1));
		}
	}
	return;
}

template<class T1>
void selfReversArr(T1* a, int row, int col)
{
	T1 x;
	for (int i = 0; i < row*col/2; i++)
	{
		x = *(a + i);
		*(a + i) = *(a + (row*col - i - 1));
		*(a + (row * col - i - 1)) = x;
	}
	return;
}

template<class T1>
T1 sumElArr(T1* a, int row, int col)
{
	T1 s = 0;
	for (int i = 0; i < row * col; i++)
	{
		s += *(a + i);
	}
	return s;
}

//Calculator functions.
double add(double a, double b) { return a + b; };
double sub(double a, double b) { return a - b; };
double mul(double a, double b) { return a * b; };
double div(double a, double b)
{
	if (b != 0 && a != 0) return a / b;
	else if (a != 0 && b == 0) return (a / abs(a) * 1.79769e+308);
	else return 1.0;
}



typedef double (*Calcf) (double, double);
Calcf CalcFunctions[4] = { add, sub, mul, div };

void Calculator()
{
	double a = 0, b = 1;
	int stat = 0;
	int xpos = 0, ypos = 0; //cursor coordinats
	char chv1 = '+';
	cout << endl << "\tCalculator" << endl << " ";
//	xpos = _wherex(); ypos = _wherey();
	while (chv1 != ' ')
	{
		if (stat == 0)
		{
			cin >> a >> chv1 >> b;
			switch (chv1)
			{
			case '+': a = (CalcFunctions[0])(a, b); break;
			case '-': a = (CalcFunctions[1])(a, b); break;
			case '*': a = (CalcFunctions[2])(a, b); break;
			case '/': a = (CalcFunctions[3])(a, b); break;
			default: { a = 0; b = 1;} break;
			}
			cout << " " << setprecision(10) << a;
			stat = 1;
		}
		else if (stat == 1)
		{
			chv1 = _getche();
			if (chv1 == 'c' || chv1==' ')
			{
				a = 0; b = 1; stat = 0;
				cout << endl << " ";
			}
			else
			{
				cin >> b;
				switch (chv1)
				{
				case '+': a = (CalcFunctions[0])(a, b); break;
				case '-': a = (CalcFunctions[1])(a, b); break;
				case '*': a = (CalcFunctions[2])(a, b); break;
				case '/': a = (CalcFunctions[3])(a, b); break;
				default: { a = 0; b = 1; stat = 0;} break;
				}
				cout << " " << setprecision(10) << a;
			}
		}
		else { stat = 0; a = 0; b = 1; }

	}
	cout << endl << "\tEnd Calculator" << endl;
	return;
}


//End functon spase.

int main()
{
	setlocale(LC_CTYPE, "ukr");

	const int size = 20;
	const int row = 4;
	const int col = 5;

	int size1 = 20;
	int row1 = 4;
	int col1 = 5;



	int A[row][col];
	initRandArr(*A, row, col, 0, 100);
	cout << endl << endl;
	showArr(*A, row, col, 5);

	int(**B) = nullptr;
	B = createArr(B, row, col);
//	int B[row][col];
	cout << endl;
	copyArr(*A, *B, row, col);
	cout << endl;
	showArr(*B, row, col, 5);
	cout << endl;

	int C[row][col];
	cout << endl;
	reversCopyArr(*A, *C, row, col);
	showArr(*C, row, col, 5);
	cout << endl;

	selfReversArr(*C, row, col);
	cout << endl;
	showArr(*C, row, col, 5);
	cout << endl;

//	Task 6.4, 6.5, 6.6
	int* pc1 = &C[2][3]; int* pc2 = &C[5][1];
	bool b1 = (*pc1 >= *pc2);
	int x1 = (*pc1 >= *pc2) ? *pc1 : *pc2;
	cout << endl << " " << x1 << endl << " Enter the numer: ";
	int x2 = 0;
	cin >> x2;
	int* px2 = &x2;
	bool bsign = (*px2 < 0); int isign = (*px2 >= 0) ? 1 : -1;
	cout << " bsign = " << bsign << "\t" << " isign = " << isign << endl;
	cout << " *pc1 = " << *pc1 << "\t" << "*pc2 = " << *pc2 << endl;
	*pc1 += *pc2; *pc2 = *pc1 - *pc2; *pc1 -= *pc2;
	cout << " *pc1 = " << *pc1 << "\t" << "*pc2 = " << *pc2 << endl;

//	Task 6.8
	cout << endl << " The sum of elements of array C: " << sumElArr(*C, row, col) << endl;

//	dellArr(B, row);

//	Task 6.7. Calculator.
	Calculator();

	//	system("pause");
	cout << " Press any key";
	_getch();
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
