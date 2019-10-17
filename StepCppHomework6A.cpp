// StepCppHomework6A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getch()
#include <iomanip>  //For use setw()
#include <ctime>
#include <typeinfo.h>

using namespace std;

//Function spase

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
			*a = y;
			a++;
		}
	}
	return;
}


template<class T1>
void fillArr(T1* a, int row, int col, T1 x)
{
	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*a = x;
			a++;
		}
	}
	return;
}

template<class T1>
void showArr(int row, int col, T1* a, int setwn = 5)
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

int recLargComDiv(int n1, int n2)
{
	if (n1 == 0) return n2;
	return recLargComDiv(n2 % n1, n1);
}

int compareBullCow(int A[4], int B[4], int *n)
{
	(*n)++;
	cout << endl << " n = " << *n;
	int* C;
	C = new int[4];
	for (int i = 0; i < 4;i++) C[i] = A[i];			//auxiliar copy A to C
	if (*n > 100)
	{
		cout << endl << " The game is over. You are lost." << endl;
		delete[] C;
		return *n;
	}
	int N, nbull = 0, ncow = 0;
	cout << endl << " Enter the number: ";
	cin >> N;
	B[0] = N % 10000 / 1000;
	B[1] = N % 1000 / 100;
	B[2] = N % 100 / 10;
	B[3] = N % 10;
	for (int i = 0; i < 4; i++)
	{
		if (A[i] == B[i]) ncow++;
	}
	if (ncow == 4)
	{
		cout << endl << " The game is over. You are win." << endl;
		delete[] C;
		return *n;
	}
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (B[j] == C[i])
			{
				nbull++;
				B[j] = 33;	//exclude this pair from further search
				C[i] = 55;
				break;
			}
		}
	}
	cout << "nbul = " << nbull << ", ncow = " << ncow << endl;
	//n = compareBullCow(A, B, n);
	compareBullCow(A, B, n);
	delete[] C;
	return *n;
}

void bullsNcows()
{
	srand(time(0));
	int countbullcow = 0;			//recursion counter
	int* np = &countbullcow;
	int *A;
	A = new int[4];
	for (int i = 0; i < 4;i++) A[i] = rand() % 10;
//	for (int i = 0; i < 4; i++) cout << A[i];		//for debug only
	int* B;
	B = new int[4];
	//B = { 0 };
	compareBullCow(A, B, np);
	delete[] A;
	delete[] B;
	cout << endl << " ";
//	for (int i = 0; i < 4; i++) cout << A[i];		//for debug only
	cout << endl << " count = " << countbullcow << endl;
	return;
}

bool singleKnightMoov(int x, int y, int sise, long long *prec, int *pmoov, int *A)
{
	bool km = 0;
	(*prec)++;
//	gotoxy(70, 70); //?
//	cout << *prec;
	if (x<0 || x>(sise - 1) || y<0 || y>(sise - 1)) return 0; //border control
	if (*(A + x * sise + y) == 0)
	{
		(*pmoov)++;
		*(A + x * sise + y) = *pmoov;
		if (*pmoov >= (sise * sise)) return 1;
		else if (singleKnightMoov((x - 1), (y - 2), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x - 2), (y - 1), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x - 2), (y + 1), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x - 1), (y + 2), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x + 1), (y + 2), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x + 2), (y + 1), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x + 2), (y - 1), sise, prec, pmoov, A)) return 1;
		else if (singleKnightMoov((x + 1), (y - 2), sise, prec, pmoov, A)) return 1;
		else
		{
			(*pmoov)--;
			*(A + x * sise + y) = 0;
			return 0;
		}

	}
	else return 0;
}

void KnightMoovRec(int x=0, int y=1, int sise = 6)
{
	long long reccounter = 0;
	int moovnumber = 0;
	long long* prec = &reccounter;
	int* pmoov = &moovnumber;
	int* A;
	A = new int[sise*sise];
	fillArr(A, sise, sise, 0);
	showArr(sise, sise, A);
	cout << endl << endl;
	if (singleKnightMoov(x, y, sise, prec, pmoov, A))
	{
		showArr(sise, sise, A);
	}
	else cout << endl << endl << " Solve not found.";

	cout << endl << endl << " reccounter = " << reccounter << endl;

	delete[] A;
	return;
}

double myRecPower(double x, int y)
{
	double res = 1.0;
	if (x == 0) return 0;
	if (y == 0) return 1;
	if (y > 0) return x * myRecPower(x, y - 1);
	if (y < 0) return myRecPower(x, y + 1) / x;
}

void recCharLine(int n, char c)
{
	if (n >= 1)
	{
		cout << c;
		recCharLine(n - 1, c);
	}
	else return;
}

long recSum(int a, int b)
{
	if (a < b) return a + recSum(a + 1, b);
	if (a > b) return a + recSum(a - 1, b);
	if (a == b) return a;
}

long minSumPos(int A[], int sise, int lng, int a = 0)
{
	long s = 0, s1 = 0, smin =0 ;
	if (a >= (sise - lng)) return LONG_MAX;
	for (int i = a; i < a + lng; s += A[i], i++);
//	cout << "\t" << a << "\t" << s << endl;		//for debug only
	s1 = minSumPos(A, sise, lng, a + 1);
	if (s <= s1)
	{
		A[sise] = a;
		smin = s;
	}
	else 
	{
		//A[sise] = a + 1;
		smin = s1;
	}
	return smin;
}

//End function spase

int main()
{
	setlocale(LC_CTYPE, "ukr");


	cout << " The largest common divisor of two numbers" << endl;
	int x, y, sise;
	cout << " Enter two numbers: ";
	cin >> x >> y;
	cout << endl << "\t" << recLargComDiv(x, y) << endl << endl << endl;

	cout << " Bulls and Cows is a folk game." << endl << " You need to guess the four-digit number." << endl;
	bullsNcows();

	cout << " Enter x, y, sise: ";
	cin >> x >> y >> sise;
	cout << endl;
	KnightMoovRec(x, y, sise);

	cout << endl << "5.2^4 = " << myRecPower(5.2, 4) << endl;
	cout << endl << "4^(-5) = " << myRecPower(4, -5) << endl;
	cout << endl << "-3^4 = " << myRecPower(-3, 4) << endl;
	cout << endl << "-2^-5 = " << myRecPower(-2, -5) << endl << endl;

	cout << " Enter simbol and long: ";
	char sim; int lng;
	cin >> sim >> lng;
	cout << endl << endl;
	recCharLine(lng, sim);
	cout << endl << endl;

	cout << recSum(4, 11) << endl;
	cout << recSum(6, -2) << endl;
	cout << recSum(0, 5) << endl;

	long summa = 0;
	const int sise1 = 100;
	int A[sise1 + 1];
	initRandArr(A, 1, sise1 + 1, 0, 100);
	cout << endl << endl;
	showArr(1, sise1, A);
	summa = minSumPos(A, sise1, 10);
	cout << endl << endl << " MinSumPos = " << A[sise1] << endl << " Min_Summa = " << summa << endl << endl;

	system("pause");
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
