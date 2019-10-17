// StepCppHomework6.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void initMatrix(T1* a, int row, int col, int min, int max)
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
void showMatrix(int row, int col, T1 *a)
{
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(10) << setprecision(3) << *(a + i * col + j);
		}
		cout << endl;
	}
	return;
}

template<class T1>
T1 maxMainDiagElemOfMatrix(int row, int col, T1* a)
{
	T1 amax = *a; int imax = 0; int jmax = 0;
	for (int i = 0; i < row; i++)
	{
		T1 x = *(a + i * (col + 1));
		if (x > amax) amax = x;
		imax = i;
	}
	return amax;
}

template<class T1>
T1 maxSlaveDiagElemOfMatrix(int row, int col, T1* a)
{
	T1 amax = *a; int imax = 0; int jmax = 0;
	for (int i = 0; i < row; i++)
	{
		T1 x = *(a + i * col + col - i - 1);
		if (x > amax) amax = x;
		imax = i;
	}
	return amax;
}

template<class T1>
T1 minMainDiagElemOfMatrix(int row, int col, T1* a)
{
	T1 amin = *a; int imin = 0; int jmin = 0;
	for (int i = 0; i < row; i++)
	{
		T1 x = *(a + i * (col + 1));
		if (x < amin) amin = x;
		imin = i;
	}
	return amin;
}

template<class T1>
T1 minSlaveDiagElemOfMatrix(int row, int col, T1* a)
{
	T1 amin = *a; int imin = 0; int jmin = 0;
	for (int i = 0; i < row; i++)
	{
		T1 x = *(a + i * col + col - i - 1);
		if (x < amin) amin = x;
		imin = i;
	}
	return amin;
}

template<class T1>
void sortMatrixString(int row, int col, T1* a)
{
	for (int i = 0; i < row; i++)
	{
		for (int k = col - 1; k > 0; k--)
		{
			T1 x = 0, y = 0;
			for (int j = 0; j < k; j++)
			{
				x = *(a + i * col + j);
				y = *(a + i * col + j + 1);
				if (x > y)
				{
					*(a + i * col + j + 1) = x;
					*(a + i * col + j) = y;
				}
			}
		}
	}
	return;
}

template<class T1>
T1 maxMatrixElement(int row, int col, T1 *a)
{
	T1 amax = *a;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (*(a + i * col + j) > amax)
			{
				amax = *(a + i * col + j);
			}
		}
	
	}
	return amax;
}



//End function spase

int main()
{
	setlocale(LC_CTYPE, "ukr");

	const int row = 8, col = 8;
	float A[row][col];
	initMatrix(*A, row, col, 0, 100 );

	cout << endl << endl;
	showMatrix(row, col, *A);

	cout << endl << endl << "\t Main diagonale Amax = " << maxMainDiagElemOfMatrix(row, col, *A) <<  endl;
	cout << "\t Slave diagonale Amax = " << maxSlaveDiagElemOfMatrix(row, col, *A) << endl;
	cout << "\tMain diagonale Amin = " << minMainDiagElemOfMatrix(row, col, *A) << endl;
	cout << "\tSlave diagonale Amin = " << minSlaveDiagElemOfMatrix(row, col, *A) << endl;
	cout << "\tMatrix Amax = " << maxMatrixElement(row, col, *A) << endl;
	cout << "\tFirst row one sise array (1 X 8) Amax = " << maxMatrixElement(1, col, *A) << endl;
	float *ptr = (NULL); ptr = &A[1][0];
	cout << "\tSecond row two sise array (3 X 8) Amax = " << maxMatrixElement(3, col, ptr) << endl;

	sortMatrixString(row, col, *A);
	cout << endl;
	showMatrix(row, col, *A);

   
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
