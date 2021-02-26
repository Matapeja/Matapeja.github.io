#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Podaj gorny zakres: ";
    cin >> n;

    int T[n+1];

    for (int i = 2; i <= n+1; i++) {
        T[i] = 1;
        cout << T[i] << " ";
    }
    cout << endl;
    for (int i = 2; i <= n+1; i++) {
        if (T[i] == 1) {
            for (int j = 2*i; j < n; j+=i) {
                T[j] = 0;
            }

        }
        cout << T[i] << " ";
    }
    cout << endl;
    for (int x=2; x <n; x++){
        if (T[x] != 0) cout << x << " ";
    }

    return 0;
}
