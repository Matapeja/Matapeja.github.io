#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int licz1, licz2;

int nwd (int licz, int mian);
int nww (int licz, int mian);
int wylaczenie (int licz, int mian); //skrocenie i wylaczenie
void wspolny (int l1, int m1, int l2, int m2); //sprowadzenie do wspolnego mianownika

int main()
{
    int l1, m1, l2, m2;
    char wybor;

    while(true){

        cout << "Operacje arytmetyczne na ulamkach" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Wyjdz z programu" << endl;

        wybor = getch();

        switch(wybor){
            case '1':
                {
                    cout << endl << "Podaj ulamki, na ktorych chesz wykonac dzialania." << endl << endl;
                    cout << "Ulamek 1: " << endl;
                    cout << " Licznik: ";
                    cin >> l1;
                    cout << " Mianownik: ";
                    cin >> m1;
                    cout << endl << "Ulamek 2: " << endl;
                    cout << " Licznik: ";
                    cin >> l2;
                    cout << " Mianownik: ";
                    cin >> m2;
                    cout << endl;

                    char wybor2;

                    cout << "Jakie dzialanie chcesz wykonac?" << endl;
                    cout << "1. Dodawanie" << endl;
                    cout << "2. Odejmowanie" << endl;
                    cout << "3. Mnozenie" << endl;
                    cout << "4. Dzielenie" << endl;
                    cout << "5. Wszystko" << endl;

                    wybor2 = getch();
                    cout << endl;

                    switch(wybor2){
                        case '1':
                            {
                                wspolny(l1, m1, l2, m2);
                                wylaczenie(licz1+licz2, nww(m1, m2)); break;
                            }
                        case '2':
                            {
                                wspolny(l1, m1, l2, m2);
                                wylaczenie(licz1-licz2, nww(m1, m2)); break;
                            }
                        case '3': wylaczenie(l1*l2, m1*m2); break;
                        case '4': wylaczenie(l1*m2, m1*l2); break;
                        case '5':
                            {
                                wspolny(l1, m1, l2, m2);
                                cout << endl << "Dodawanie:" << endl ;
                                wylaczenie(licz1+licz2, nww(m1, m2));
                                cout << endl << "Odejmowanie:" << endl;
                                wylaczenie(licz1-licz2, nww(m1, m2));
                                cout << endl << "Mnozenie:" << endl;
                                wylaczenie(l1*l2, m1*m2);
                                cout << endl << "Dzielenie:" << endl;
                                wylaczenie(l1*m2, m1*l2);
                                break;
                            }
                    }
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

int nww (int licz, int mian){
    return licz*mian/nwd(licz, mian);
}


int wylaczenie (int licz, int mian){
    int nwd_temp = nwd(licz, mian);
    licz = licz/nwd_temp;
    mian = mian/nwd_temp;


    int calosc = licz/mian;
    if(licz-(calosc*mian) == 0)
    {
        cout << calosc << endl;
    }else if(licz>=mian){
        cout << "   " << licz-(calosc*mian) << endl;
        cout << calosc << "  " << "---" << endl;
        cout << "   " << mian;
    }else{
        cout << "   " << licz << endl;
        cout << "   " << "---" << endl;
        cout << "   " << mian;
    }

}

void wspolny (int l1, int m1, int l2, int m2){
    licz1=(nww(m1, m2)/m1)*l1;
    licz2=(nww(m1, m2)/m2)*l2;
}

