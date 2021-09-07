#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    int suma, n, liczba;
    char wybor;

    while(true){

        cout << "Program obliczajacy sume liczb podzielnych przez 7" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Wyjdz z programu" << endl;

        wybor = getch();

        switch(wybor){
            case '1':
                system("cls");
                suma=0;

                cout << "Podaj ilosc wprowadzanych liczb: ";
                cin >> n;
                cout << endl;

                if(n>=0){

                    for(int i=0; i<n; i++){
                        cout << "Podaj " << i+1 << " liczbe: ";
                        cin >> liczba;
                        if(liczba%7==0) suma+=liczba;
                    }

                    cout << endl << "Suma liczb podzielnych przez 7 wynosi: " << suma;

                }else{ cout << "Ilosc wprowadzanych liczb nie moze byc ujemna!"; }

                getchar(); getchar();
                system("cls");
                break;


            case '2': exit(0); break;
            default: system("cls");

            }
        }
    return 0;
}

