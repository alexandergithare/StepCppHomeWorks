// StepCppHomework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getch()
#include <iomanip>  //For use setw()
#include <ctime>
//#include <typeinfo.h>
#include <Windows.h>

//#include <fstream>
#include <string>

using namespace std;


//Function spase.

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void printNchar(int n = 50, char t = ' ')
{
	for (int i = 0; i < n; i++) cout << t;
	return;
}

template<class T>
T** createArr(T** p, int row, int col)
{
	if (p == nullptr) p = new T * [row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
	return p;
}

template<class T>
void dellArr(T** p, int row)
{
	for (int i = 0; i < row; i++)
		delete[] p[i];
	delete[] p;
	return;
}

template<class T1>
void initRandArr(T1** a, int row, int col, int min, int max)
{
	srand(time(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			double x = 1.0 / ((double)RAND_MAX + 1);
			T1 y = (T1)(x * rand() * (max - min + 1) + min);
			a[i][j] = y;
		}
	}
	return;
}

template<class T1>
void fillArr(T1** a, int row, int col, T1 x)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = x;
		}
	}
	return;
}

template<class T1>
void showArr(T1** a, int row, int col, int setwn = 5)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(setwn) << a[i][j];
		}
		cout << endl << endl;
	}
	return;
}

template<class T1>
void copyArr(T1** a, T1** b, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	return;
}


template<class T1>
T1* addElem(T1* a, int n, T1 b)
{
	T1* p = new T1[n + 1];
	for (int i = 0; i < n; i++)
	{
		p[i] = a[i];
	}
	p[n] = b;
	delete[]a;
	return p;
}

template<class T>
T* addElemPos(T* a, int n, T b, int pos = 0)
{
	T* p = new T[n + 1];
	for (int i = 0; i < pos; i++)
	{
		p[i] = a[i];
	}
	p[pos] = b;
	for (int i = pos + 1; i < n + 1; i++)
	{
		p[i] = a[i - 1];
	}
	delete[]a;
	return p;
}

template<class T>
T* dellElemPos(T* a, int n, int pos = 0)
{
	T* p = new T[n - 1];
	for (int i = 0; i < pos; i++)
	{
		p[i] = a[i];
	}
	for (int i = pos; i < n - 1; i++)
	{
		p[i] = a[i + 1];
	}
	delete[]a;
	return p;
}


template<class T>
T** addColArr(T** a, int row, int col, T* bcol, int pos) //bcol[] size must be equale (row)
{
	T** b = new T * [row];
	for (int i = 0; i < row; i++)
	{
		b[i] = new T[col]; // create new array b[row][col]
	}
	for (int i = 0; i < row; i++)						//copy a to b
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	for(int i = 0; i < row; i++)	b[i] = addElemPos(b[i], col, bcol[i], pos);
	return b;
}

template<class T>
T** dellColArr(T** a, int row, int col, int pos) //bcol[] size must be equale (row)
{
	T** b = new T * [row];
	for (int i = 0; i < row; i++) b[i] = new T[col]; // create new array b[row][col]
	for (int i = 0; i < row; i++)						//copy a to b
		for (int j = 0; j < col; j++) b[i][j] = a[i][j];
	for (int i = 0; i < row; i++)	b[i] = dellElemPos(b[i], col, pos);
	return b;
}

template<class T>
void shiftArr(T** A, int row, int col, int shiftx, int shifty) //bcol[] size must be equale (row)
{
	T** B = new T * [row];
	for (int i = 0; i < row; i++) B[i] = new T[col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			B[i][j] = A[(row + (i + shifty % row)) % row][(col + (j - shiftx % col)) % col];
		}
	}
	copyArr(B, A, row, col);
	for (int i = 0; i < row; i++) delete[] B[i];
	delete[] B;
	return;
}

template<class T>
T** transpMatrix(T** M, int row, int col)
{
	T** M1 = new T * [col];
	for (int i = 0; i < col; i++) M1[i] = new T[row];
	for(int i=0; i< row; i++)
		for (int j = 0; j < col; j++)
		{
			M1[j][i] = M[i][j];
		}
	return M1;
}


//Phonebook through multidimensional arrays

char** createContact()
{
	char bufname[20];
	char bufnumber[20];
	cout << endl << "Enter new name: ";
	cin.getline(bufname, 20);
	cout << "Enter new number: ";
	cin.getline(bufnumber, 20);
	char** contact = new char* [2];
	contact[0] = new char[strlen(bufname) + 1]; //name
	contact[1] = new char[strlen(bufnumber) + 1]; //number
	strcpy(contact[0], bufname);
	strcpy(contact[1], bufnumber);
	return contact;
}

char*** addContact(char*** a, int* size, int pos = 0)
{
	if (pos > *size) pos = *size;
	char** p = nullptr;
	p = createContact();
	char*** ph1 = new char** [*size+1];
	for (int i = 0; i < pos; i++)
	{
		ph1[i] = new char*[2];
		ph1[i][0] = new char[strlen(a[i][0]) + 1]; //name copy from phonebook
		ph1[i][1] = new char[strlen(a[i][1]) + 1]; //number copy from phonebook
		strcpy(ph1[i][0], a[i][0]);
		strcpy(ph1[i][1], a[i][1]);
	}
	ph1[pos] = new char* [2];
	ph1[pos][0] = new char[strlen(p[0]) + 1]; //name copy from created contact
	ph1[pos][1] = new char[strlen(p[1]) + 1]; //number copy from created contact
	strcpy(ph1[pos][0], p[0]);
	strcpy(ph1[pos][1], p[1]);
	for (int i = pos+1; i <= *size; i++)
	{
		ph1[i] = new char* [2];
		ph1[i][0] = new char[strlen(a[i-1][0]) + 1]; //name copy from phonebook
		ph1[i][1] = new char[strlen(a[i-1][1]) + 1]; //number copy from phonebook
		strcpy(ph1[i][0], a[i-1][0]);
		strcpy(ph1[i][1], a[i-1][1]);
	}
	for (int i = 0; i < *size; i++)
	{
		delete[] a[i][0];
		delete[] a[i][1];
		delete[] a[i];
	}
	delete[] a;
	delete[] p[0];
	delete[] p[1];
	delete[] p;
	*size += 1;
	return ph1;
}

char*** delContact(char*** a, int* size, int pos = 0)
{
	if (pos >= *size) pos = *size - 1;
	char*** ph1 = new char** [*size -1];
	for (int i = 0; i < pos; i++)
	{
		ph1[i] = new char* [2];
		ph1[i][0] = new char[strlen(a[i][0]) + 1]; //name copy from phonebook
		ph1[i][1] = new char[strlen(a[i][1]) + 1]; //number copy from phonebook
		strcpy(ph1[i][0], a[i][0]);
		strcpy(ph1[i][1], a[i][1]);
	}
	for (int i = pos; i < *size-1; i++)
	{
		ph1[i] = new char* [2];
		ph1[i][0] = new char[strlen(a[i + 1][0]) + 1]; //name copy from phonebook
		ph1[i][1] = new char[strlen(a[i + 1][1]) + 1]; //number copy from phonebook
		strcpy(ph1[i][0], a[i + 1][0]);
		strcpy(ph1[i][1], a[i + 1][1]);
	}
	for (int i = 0; i < *size; i++)
	{
		delete[] a[i][0];
		delete[] a[i][1];
		delete[] a[i];
	}
	delete[] a;
	*size -= 1;
	return ph1;

	return a;
}

int findContact(char*** a, int* size)
{
	int index = -1;
	int findrez = -1; //find result
	char nameornumber[20];
	cout << "Enter the name or phone number: ";
	cin.getline(nameornumber, 20);
	for (int i = 0; i < *size; i++)
	{
		findrez = strcmp(a[i][0], nameornumber);
		if (findrez == 0)
		{
			index = i;
			return index;
		}
	}
	for (int i = 0; i < *size; i++)
	{
		findrez = strcmp(a[i][1], nameornumber);
		if (findrez == 0)
		{
			index = i;
			return index;
		}
	}
	return index;  //return index of array; -1 if not find
}

void showContact(char*** a,  int index)
{
	cout << endl << setw(4) << index + 1 << setw(20) << a[index][0] << setw(20) << a[index][1] << endl;
}

void showPhoneBook(char*** a, int* size)
{
	if (*size == 0)
	{
		cout << endl << "The Phonebook is empty." << endl;

	} else	
		for (int i = 0; i < *size; i++)
		{
			showContact(a, i);
		}
	cout << " Press any key";
	_getch();
	return;
}

char*** phoneBookMenu(char*** a, int* size, bool& f )
{
	char chv1 = 0;
	system("cls");
	gotoxy(10, 1);
	cout << "Phone Book Menu" << endl;
	cout << endl << " 1-Find Contact\n 2-Add Contact\n 3-Show PhoneBook\n 4-Exit\n" << endl;
	chv1 = _getche();
	switch (chv1)
	{
	case '1':
	{
		int index = -1;
		char chv2 = 0;
		index = findContact(a, size);
		if (index < 0 || index >= *size)
		{
			cout << " Contact not found. Press any key.";
			_getch();
		}
		else
		{
			showContact(a, index);
			cout << " 1-Edit Contact\n 2-Delete Contact\n";
			chv2 = _getche();
			switch (chv2)
			{
			case '1':
			{
				a = delContact(a, size, index);
				a = addContact(a, size, index);
				cout << " Contact changed. Press any key.";
				_getch();
			}
			break;
			case '2':
			{
				a = delContact(a, size, index);
				cout << " Contact deleted. Press any key.";
				_getch();
			}
			break;
			default:
			{

			}
			}
		}
			f = 1;
	}
		break;
	case '2':
	{
		a = addContact(a, size, *size);
		cout << " Contact added. Press any key";
		f = 1;
		_getch();
	}
		break;
	case '3':
	{
		showPhoneBook(a, size);
		f = 1;
	}
		break;
	case '4'://8:
	{ f = 0; return a; }//exit(0)
		//break;
	default: 
	{ f = 0; return a; }
		//break;
	}
	return a;
}

void phoneBook(char*** phb, int* size )
{
	bool f1 = 1;
	do
	phb = phoneBookMenu(phb, size, f1);
	while (f1);
	for (int i = 0; i < *size; i++)
	{
		delete[] phb[i][0];
		delete[] phb[i][1];
		delete[] phb[i];
	}
	delete[] phb;
	return;
}

int main()
{
	cout << " Create 2-dimensional array." << endl;
	int row = 6, col = 9;
	int** A1 = nullptr;
	int** B1 = nullptr;
	int** C1 = nullptr;
	A1 = createArr(A1, row, col);
	initRandArr(A1, row, col, -100, 100);
	showArr(A1, row, col);

	cout << endl << " Create 1-col array, showed as 1 row." << endl;
	int** X1 = nullptr;
	X1 = createArr(X1, row, 1);
 	fillArr(X1, 1, row, 55);
	showArr(X1, 1, row);

	cout << endl << " Paste 1-column array in 2-dimensional array." << endl;
	B1 = addColArr(A1, row, col, X1[0], row / 2);
	showArr(B1, row, col+1);

	cout << endl << " Delete column in 2-dimensional array." << endl;
	C1 = dellColArr(B1, row, col+1, row / 2);
	showArr(C1, row, col);

	cout << endl << " Shift column and row in 2-dimensional array." << endl;
	shiftArr(C1, row, col, 1, 2);
	showArr(C1, row, col);

	cout << endl << " Transposition of the matrix." << endl;
	int** D = nullptr;
	D = transpMatrix(C1, row, col);
	showArr(D, col, row);

	dellArr(A1, row);
	dellArr(B1, row);
	dellArr(C1, row);
	dellArr(D, col);
	cout << endl << " Press any key";
	_getche();

	int phonebook1size = 0;
	int* phb1sizeptr = &phonebook1size;
	char*** phonebook1 = new char** [phonebook1size];
	phoneBook(phonebook1, phb1sizeptr);




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
