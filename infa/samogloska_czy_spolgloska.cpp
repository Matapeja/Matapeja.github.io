#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    int n;
    char wybor;

    while(true){

        cout << "Program sprawdzajacy czy znak jest spolgloska czy samogloska" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "1. Start" << endl;
        cout << "2. Wyjdz z programu" << endl;

        wybor = getch();

        switch(wybor){
            case '1':
                {
                    cout << endl << "Ile znakow (liter) chcesz podac: ";
                    cin >> n;

                    if(n>=0){

                        char literka[n];

                        for(int i=0; i<n; i++){
                            cout << endl << "Podaj " << i+1 << " litere: ";
                            cin >> literka[i];
                        }

                        cout << endl << "Podane znaki: " << endl;

                        for (int i=0; i<n;i++){

                                if((literka[i] >= 'a' && literka[i] <= 'z')||(literka[i] >= 'A' && literka[i] <= 'Z')){

                                    cout << "   "<< literka[i];
                                        if((literka[i]=='a')||(literka[i]=='e')||(literka[i]=='i')||(literka[i]=='o')||(literka[i]=='u')||(literka[i]=='¹')||(literka[i]=='ê')||(literka[i]=='y')
                                         ||(literka[i]=='A')||(literka[i]=='E')||(literka[i]=='I')||(literka[i]=='O')||(literka[i]=='U')||(literka[i]=='¥')||(literka[i]=='Ê')||(literka[i]=='Y')){
                                            cout << " to samogloska" << endl;
                                        }else{
                                            cout << " to spolgloska" << endl;
                                            }

                                }else{ cout << "   "<< literka[i] << " to nie litera" << endl; }
                        }

                    }else{ cout << "Ilosc wprowadzanch znakow nie moze byc ujemna!"; }

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
