// StepCppHomework7A.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
T* createArr(T* p, int size)
{
	if (p == nullptr) p = new T[size];
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
			*(a + i * col + j) = y;
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

template<class T>
void copyArr(T* a, T* b, int size)
{
	for (int i = 0; i < size; i++) *(b + i) = *(a + i);
	return;
}

template<class T>
T* addArr(T* a, int sizea, T* b, int sizeb, T* c)
{
	c = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++) *(c + i) = *(a + i);
	for (int i = 0; i < sizeb; i++) *(c + sizea + i) = *(b + i);
	return c;
}

template<class T1>
T1* addElem(T1* a, int n, T1 b)
{
	T1* p = new T1[n + 1];
	for (int i = 0; i < n; i++) p[i] = a[i];
	p[n] = b;
	delete[]a;
	return p;
}

template<class T>
T* addElemPos(T* a, int n, T b, int pos = 0)
{
	T* p = new T[n + 1];
	for (int i = 0; i < pos; i++) p[i] = a[i];
	p[pos] = b;
	for (int i = pos + 1; i < n + 1; i++) p[i] = a[i - 1];
	delete[]a;
	return p;
}

template<class T>
T* dellElemPos(T* a, int n, int pos = 0)
{
	T* p = new T[n - 1];
	for (int i = 0; i < pos; i++) p[i] = a[i];
	for (int i = pos; i < n - 1; i++) p[i] = a[i + 1];
	delete[]a;
	return p;
}



int main()
{
	//	Task 7.1
	int sizea = 11, sizeb = 8;
	cout << " Enter the size of array A: ";
	cin >> sizea; cout << endl;
	int(*A1) = nullptr;
	A1 = createArr(A1, sizea);
	initRandArr(A1, 1, sizea, -100, 100);
	cout << endl;
	showArr(A1, 1, sizea, 5);
//	A1 = addElemPos(A1, sizea, 11, 4);
//	cout << endl;
//	showArr(A1, 1, sizea+1, 5);

	cout << " Enter the size of array B: ";
	cin >> sizeb; cout << endl;
	//	srand(time(0));
	int(*B1) = nullptr;
	B1 = createArr(B1, sizeb);
	initRandArr(B1, 1, sizeb, -100, 100);
	cout << endl;
	showArr(B1, 1, sizeb, 5);
//	B1 = dellElemPos(B1, sizeb, 5);
//	cout << endl;
//	showArr(B1, 1, sizeb-1, 5);

	_getche();

	int n = 0; bool bo1 = 1;
	int(*C1) = nullptr;
	C1 = createArr(C1, n);
	for (int i = 0; i < sizea; i++)
	{
		bo1 = 1;
		for (int j = 0; j < sizeb; j++)
		{
			if (A1[i] == B1[j]) { bo1 = 0; break; }
		}
		for (int j = 0; j <= n; j++)
		{
			if (bo1 == 0) break;
			if (A1[i] == C1[j]) { bo1 = 0; break; }
		}
		if (bo1 == 1)
		{
			C1 = addElem(C1, n, A1[i]);
			n++;
		}
	}
	cout << endl;
	showArr(C1, 1, n);
	
	_getche();

	//	Task 7.2
	int(*C2) = nullptr;
	C2 = createArr(C2, n);
	copyArr(C1, C2, n);
	for (int i = 0; i < sizeb; i++)
	{
		bo1 = 1;
		for (int j = 0; j < n; j++)
		{
			if (B1[i] == C1[j])
			{
				bo1 = 0;
				break;
			}
		}
		if (bo1 == 1)
		{
			C2 = addElem(C2, n, B1[i]);
			n++;
		}
	}
	cout << endl;
	showArr(C2, 1, n);

	_getche();

// Task 7.3
	int(*C3) = nullptr;
	C3 = addArr(A1, sizea, B1, sizeb, C3);
	cout << endl;
	showArr(C3, 1, sizea + sizeb);

	_getche();

//	Task 7.4
	n = 0;
	int (*C4) = nullptr;
	C4 = createArr(C4, n);
	for (int i = 0; i < sizea; i++)
	{
		bo1 = 1;
		for (int j = 0; j < sizeb; j++)
		{
			if (A1[i] == B1[j])
			{
				for (int k = 0; k <= n; k++)
				{
					bo1 = (A1[i] == C4[k]) ? 0 : 1;
				}
			}
			if (bo1)
			{
				C4 = addElem(C4, n++, A1[i]);
				break;
			}
		}
	}
	cout << endl;
	showArr(C4, 1, n);

	_getche();

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
