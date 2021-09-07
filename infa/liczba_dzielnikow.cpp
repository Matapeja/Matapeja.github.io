#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int n, ile_dzielnikow = 1;

int main()
{
    srand(time(NULL));

    n = 5 + rand()% 146;

   for (int i=1; i<=n/2; i++){
        if (n%i == 0) {
            cout << i << endl;
            ile_dzielnikow++;
        }
   }
   cout << n;

    cout << "\nLiczba dzielnikow wynosi " << ile_dzielnikow;

    return 0;
}
