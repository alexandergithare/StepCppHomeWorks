// StepCppHomework1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>  //For uses cout, cin, endl
#include <cmath>
#include <conio.h>   //For uses _getche()
#include <iomanip>   //For uses setw()
//#include "windows.h"


using namespace std;

int main()  /*Ask for main function arguments*/
{
  //  std::cout << "Hello World!\n";
	setlocale(LC_CTYPE, "ukr");

	//   setlocale(LC_ALL, "Ukrainian");
	//    typedef UINT (CALLBACK* TImportFunc)(HANDLE, UINT);
	//    HINSTANCE hInst = GetModuleHandle("kernel32.dll");
	//    TImportFunc SetConsoleFont = (TImportFunc)GetProcAddress(hInst, "SetConsoleFont");
	//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//    SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 10);//8 ��� ��� Win7, ��� �� ����� 10


	//   SetConsoleCP(1251);
	//   SetConsoleOutputCP(1251);

	char chv1 = 0, chv2 = 0;

	while (chv1 != '\r')
	{
		//ex0
		cout << endl << setw(40) << "Part zero." << endl;
		cout << "\t Now there will be a poem. You are ready? Click Y if agree or N to skip." << endl;
		chv2 = _getche();  //Program continues without wait press "enter"
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			cout << endl << endl;
			cout << setw(50) << "�� ����, �� ���������" << endl;
			cout << setw(50) << "���� �� �����i" << endl;
			cout << setw(50) << "����� ����� ��������" << endl;
			cout << setw(50) << "�� �����i ���i�." << endl;
			cout << setw(50) << "��� ���� ���������i," << endl;
			cout << setw(50) << "I ��i���, i ����i" << endl;
			cout << setw(50) << "����� ��� ������� �����," << endl;
			cout << setw(50) << "........................" << endl;
			cout << endl << endl << setw(60) << "����� ��������." << endl;
			chv2 = 0;
		}
		//ex1
		cout << endl << setw(40) << "Part one." << endl;
		cout << setw(40) << "REINBOW" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			cout << endl << "\t ������\n\t\t �������\n\t\t\t ������\n\t\t\t\t �����\n\t\t\t\t\t ���\n\t\t\t\t\t\t �����\n\t\t\t\t\t\t\t �����" << endl;
		}
		//ex2
		cout << endl << setw(40) << "Part two." << endl;
		cout << setw(40) << "����������." << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			cout << endl << setw(40) << "����������." << endl;
			cout << setw(35) << "����� ����!" << endl;
			cout << "\t ����� �������� ����, ��������, �������������� �� 15 �� 25 �. " << endl;
			cout << "\t� ������� ���������. ���� �� 1 000 000 $ " << endl;
			cout << "\t �������: +38 063 765 43 21" << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
			int i;
			for (i = 0; i < 10; i++)
			{
				cout << setw(8) << "+38 |";
			}
			cout << endl;
			for (i = 0; i < 10; i++)
			{
				cout << setw(8) << "063 |";
			}
			cout << endl;
			for (i = 0; i < 10; i++)
			{
				cout << setw(8) << "765 |";
			}
			cout << endl;
			for (i = 0; i < 10; i++)
			{
				cout << setw(8) << "43 |";
			}
			cout << endl;
			for (i = 0; i < 10; i++)
			{
				cout << setw(8) << "21 |";
			}
			cout << endl;

		}
		//ex3
		cout << endl << setw(40) << "Part three." << endl;
		cout << "\t ���������� �������� ������������� �������������. ";
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float R1, R2, R3;
			float Result = 0;
			cout << "\t ������� �������� ���� ����������� ����������� �������������" << endl;
			cout << "\t� �������: R1 R2 R3 (��� ����� ����� ������) � ������� \"enter\"" << endl;
			cout << " ����������, ����������, ��� �������� ���������� �����," << endl;
			cout << "����� � �� ������������� � ����������������� ������������ ��������" << endl;
			cin >> R1 >> R2 >> R3;
			float R_Arr[] = { R1, R2, R3 };
			int i = 0;
			for (i = 0; i < 3; i++)
			{
				if (R_Arr[i] == 0)
				{
					Result = 0;
					break;
				}
				Result = Result + 1 / R_Arr[i];
			}
			if (Result == 0) { cout << endl << "����� ������������� ����� 0 ��" << endl; }
			else
			{
				Result = 1 / Result;
				cout << " ����� ������������� ����� " << setprecision(7) << Result << " ��" << endl;
			}
			if (Result < 0) { cout << " �����������, � ��� ��������� Perpetum Mobile!" << endl; }
		}
		//ex4
		cout << endl << setw(40) << "Part four." << endl;
		cout << setw(40) << "Circumreference" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			const float pi = 3.14;
			float R, S, L;
			cout << endl << " ������� ����� ����������:  ";
			cin >> L;
			R = L / (2 * pi);
			S = pi * R * R;
			cout << endl << " ������ ����������: " << R;
			cout << endl << "     ������� �����: " << S << endl;				
		}
		//ex5
		cout << endl << setw(40) << "Part five." << endl;
		cout << setw(50) << "Evenly accelerated movement" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float V, a, t;
			cout << " ������� ��������, ���������, ����� (����� ������): ";
			cin >> V >> a >> t;
			cout << endl << " ���������� ����������: " << (float)(V* t + (a * t * t) / 2) << endl;
		}
		//ex6
		cout << endl << setw(40) << "Part six." << endl;
		cout << setw(40) << "Airport" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float S, t;
			cout << " ������� ���������� �� ���������: ";
			cin >> S;
			cout << endl << " ������� ��������� �����: ";
			cin >> t;
			cout << endl << "����������� ��������: " << S / t;
		}
		//ex7
		cout << endl << setw(40) << "Part seven." << endl;
		cout << setw(45) << "Telephone call" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			const float Minut_Price = 0.3; // ��������� ����� ������ � �������.
			int H1, H2, M1, M2, S1, S2;
			float P; // ��������� ���������.
			cout << " ������� ����� ������ ��������� (�� �� ��): ";
			cin >> H1 >> M1 >> S1;
			cout << endl << " ������� ����� ��������� ��������� (�� �� ��): ";
			cin >> H2 >> M2 >> S2;
			P = (float)((abs(H2 - H1) * 3600 + abs(M2 - M1) * 60 + (S2 - S1)) * Minut_Price / 60);
			cout << " ��������� ���������: " << setprecision(4) << P << " ���." << endl;
		}
		//ex8
		cout << endl << setw(40) << "Part eight." << endl;
		cout << setw(40) << "Car travel" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float Na, Nb, Nc; // ������ ������� �, � � � �� 100 ��.
			float Pa, Pb, Pc; // ���� �� 1 ����.
			float S;
			float SPa, SPb, SPc;
			cout << " ������ ��������� ������� ��� �������������� ������ ����� �������." << endl;
			cout << " ������� ������ ������� � (�./100 ��.): ";
			cin >> Na;
			cout << endl << " ������� ������ ������� B (�./100 ��.): ";
			cin >> Nb;
			cout << endl << " ������� ������ ������� C (�./100 ��.): ";
			cin >> Nc;
			cout << endl << " ������� ��������� ������� � (���./�.): ";
			cin >> Pa;
			cout << endl << " ������� ��������� ������� � (���./�.): ";
			cin >> Pb;
			cout << endl << " ������� ��������� ������� � (���./�.): ";
			cin >> Pc;
			cout << endl << " ������� ���������� (��.): ";
			cin >> S;
			cout << endl;
			SPa = S * (Na / 100) * Pa;
			SPb = S * (Nb / 100) * Pb;
			SPc = S * (Nc / 100) * Pc;
			cout << " ������� 1. ��������� ��������� ������ �� ���� ����� �������." << endl;
			cout << " ���������� " << S << " ��." << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "|" << setw(15) << "������ �|" << setw(15) << "������ �|" << setw(15) << "������ �|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "������|" << setw(14) << Na << "|" << setw(14) << Nb << "|" << setw(14) << Nc << "|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "����|" << setw(14) << Pa << "|" << setw(14) << Pb << "|" << setw(14) << Pc << "|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "���������|" << setw(14) << SPa << "|" << setw(14) << SPb << "|" << setw(14) << SPc << "|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			
		}


		cout << endl << endl << " Press \"space\" to continue or \"enter\" to exit " << endl << endl << endl;
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
