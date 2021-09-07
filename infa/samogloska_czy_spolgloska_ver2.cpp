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
    char wybor, l;

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

                        for(int i=0; i<n; i++){
                            cout << endl << "Podaj " << i+1 << " litere: ";
                            cin >> l;

                            if((l >= 'a' && l <= 'z')||(l >= 'A' && l <= 'Z')){

                                    cout << "   "<< l;

                                        if((l=='a')||(l=='e')||(l=='i')||(l=='o')||(l=='u')||(l=='¹')||(l=='ê')||(l=='y')
                                         ||(l=='A')||(l=='E')||(l=='I')||(l=='O')||(l=='U')||(l=='¥')||(l=='Ê')||(l=='Y')){
                                            cout << " to samogloska" << endl;
                                        }else{
                                            cout << " to spolgloska" << endl;
                                            }

                            }else{ cout << "   "<< l << " to nie litera" << endl; }
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

