#include <iostream>

using namespace std;

int main() {
    const int N = 3;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    int P = 0; 
    int D = 0; 


    for (int i = 0; i < N; ++i) {
        if (a[i] % 2 == 0) {
            P++;
        } else {
            D++;
        }
    }

    cout << "Numero di numeri pari: " << P << endl;
    cout << "Numero di numeri dispari: " << D << endl;
}