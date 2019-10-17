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
	//    SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), 10);//8 это для Win7, для ХР будет 10


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
			cout << setw(50) << "Як умру, то поховайте" << endl;
			cout << setw(50) << "Мене на могилi" << endl;
			cout << setw(50) << "Серед степу широкого" << endl;
			cout << setw(50) << "На Вкраїнi милiй." << endl;
			cout << setw(50) << "Щоб лани широкополi," << endl;
			cout << setw(50) << "I Днiпро, i кручi" << endl;
			cout << setw(50) << "Стали вам поперек горла," << endl;
			cout << setw(50) << "........................" << endl;
			cout << endl << endl << setw(60) << "Тарас Шевченко." << endl;
			chv2 = 0;
		}
		//ex1
		cout << endl << setw(40) << "Part one." << endl;
		cout << setw(40) << "REINBOW" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			cout << endl << "\t Каждый\n\t\t Охотник\n\t\t\t Желает\n\t\t\t\t Знать\n\t\t\t\t\t Где\n\t\t\t\t\t\t Сидит\n\t\t\t\t\t\t\t Фазан" << endl;
		}
		//ex2
		cout << endl << setw(40) << "Part two." << endl;
		cout << setw(40) << "Объявление." << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			cout << endl << setw(40) << "Объявление." << endl;
			cout << setw(35) << "КУПЛЮ ЯХТУ!" << endl;
			cout << "\t Куплю парусную яхту, тримаран, водоизмещением от 15 до 25 т. " << endl;
			cout << "\tВ хорошем состоянии. Цена до 1 000 000 $ " << endl;
			cout << "\t ТЕЛЕФОН: +38 063 765 43 21" << endl;
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
		cout << "\t Вычисление величины параллельного сопротивления. ";
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float R1, R2, R3;
			float Result = 0;
			cout << "\t Введите величины трех соединенных параллельно сопротивлений" << endl;
			cout << "\tв формате: R1 R2 R3 (три числа через пробел) и нажмите \"enter\"" << endl;
			cout << " Пожалуйста, проследите, что вводятся десятичные числа," << endl;
			cout << "чтобы я не заморачивался с отфильтровыванием некорректных символов" << endl;
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
			if (Result == 0) { cout << endl << "Общее сопротивление равно 0 Ом" << endl; }
			else
			{
				Result = 1 / Result;
				cout << " Общее сопротивление равно " << setprecision(7) << Result << " Ом" << endl;
			}
			if (Result < 0) { cout << " Поздравляем, у Вас получился Perpetum Mobile!" << endl; }
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
			cout << endl << " Введите длину окружности:  ";
			cin >> L;
			R = L / (2 * pi);
			S = pi * R * R;
			cout << endl << " Радиус окружности: " << R;
			cout << endl << "     Площадь круга: " << S << endl;				
		}
		//ex5
		cout << endl << setw(40) << "Part five." << endl;
		cout << setw(50) << "Evenly accelerated movement" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float V, a, t;
			cout << " Введите скорость, ускорение, время (через пробел): ";
			cin >> V >> a >> t;
			cout << endl << " Пройденное расстояние: " << (float)(V* t + (a * t * t) / 2) << endl;
		}
		//ex6
		cout << endl << setw(40) << "Part six." << endl;
		cout << setw(40) << "Airport" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float S, t;
			cout << " Введите расстояние до аэропорта: ";
			cin >> S;
			cout << endl << " Введите требуемое время: ";
			cin >> t;
			cout << endl << "Необходимая скорость: " << S / t;
		}
		//ex7
		cout << endl << setw(40) << "Part seven." << endl;
		cout << setw(45) << "Telephone call" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			const float Minut_Price = 0.3; // Стоимость одной минуты в гривнах.
			int H1, H2, M1, M2, S1, S2;
			float P; // Стоимость разговора.
			cout << " Введите время начала разговора (ЧЧ ММ СС): ";
			cin >> H1 >> M1 >> S1;
			cout << endl << " Введите время окончания разговора (ЧЧ ММ СС): ";
			cin >> H2 >> M2 >> S2;
			P = (float)((abs(H2 - H1) * 3600 + abs(M2 - M1) * 60 + (S2 - S1)) * Minut_Price / 60);
			cout << " Стоимость разговора: " << setprecision(4) << P << " грн." << endl;
		}
		//ex8
		cout << endl << setw(40) << "Part eight." << endl;
		cout << setw(40) << "Car travel" << endl;
		cout << " Click Y to continue or N to skip." << endl;
		chv2 = _getche();
		if ((chv2 == 'y') || (chv2 == 'Y'))
		{
			float Na, Nb, Nc; // Расход бензина А, В и С на 100 км.
			float Pa, Pb, Pc; // Цена за 1 литр.
			float S;
			float SPa, SPb, SPc;
			cout << " Расчет стоимости поездки при использованием разных видов бензина." << endl;
			cout << " Введите расход бензина А (л./100 км.): ";
			cin >> Na;
			cout << endl << " Введите расход бензина B (л./100 км.): ";
			cin >> Nb;
			cout << endl << " Введите расход бензина C (л./100 км.): ";
			cin >> Nc;
			cout << endl << " Введите стоимость бензина А (грн./л.): ";
			cin >> Pa;
			cout << endl << " Введите стоимость бензина В (грн./л.): ";
			cin >> Pb;
			cout << endl << " Введите стоимость бензина С (грн./л.): ";
			cin >> Pc;
			cout << endl << " Введите расстояние (км.): ";
			cin >> S;
			cout << endl;
			SPa = S * (Na / 100) * Pa;
			SPb = S * (Nb / 100) * Pb;
			SPc = S * (Nc / 100) * Pc;
			cout << " Таблица 1. Сравнение стоимости поезки на трех видах бензина." << endl;
			cout << " Расстояние " << S << " км." << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "|" << setw(15) << "Бензин А|" << setw(15) << "Бензин В|" << setw(15) << "Бензин С|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "Расход|" << setw(14) << Na << "|" << setw(14) << Nb << "|" << setw(14) << Nc << "|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "Цена|" << setw(14) << Pa << "|" << setw(14) << Pb << "|" << setw(14) << Pc << "|" << endl;
			cout << "-------------------------------------------------------------" << endl;
			cout << "|" << setw(15) << "Стоимость|" << setw(14) << SPa << "|" << setw(14) << SPb << "|" << setw(14) << SPc << "|" << endl;
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
