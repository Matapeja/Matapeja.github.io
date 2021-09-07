#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int nwd (int licz, int mian);

int main()
{
    int l, m;
    char wybor;

    while(true){

        cout << "Program skracajacy ulamki zwykle" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Wyjdz z programu" << endl;

        wybor = getch();

        switch(wybor){
            case '1':
                {
                    cout << endl << "Podaj licznik: ";
                    cin >> l;
                    cout << endl << "Podaj mianownik: ";
                    cin >> m;

                    cout << endl << "Ulamek po skroceniu:";
                    cout << endl << "   " <<  l/nwd(l, m);
                    cout << endl << "   "  << "---";
                    cout << endl << "   "  <<  m/nwd(l, m);

                    getchar(); getchar();
                    system("cls");
                    break;
                }

            case '2': exit(0); break;

            default: system("cls");
            }
        }
    return 0;
}

int nwd (int licz, int mian){
    if (mian==0) return licz;
    return nwd(mian,licz%mian);
}
