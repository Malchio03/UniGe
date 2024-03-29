// File: shiftN.cpp
#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore per a[" << i << "]: ";
        cin >> a[i];
    }

    int shiftBy;
    cout << "Inserisci il numero di posizioni di traslazione: ";
    cin >> shiftBy;

    if (shiftBy < 0) {
        shiftBy = -shiftBy; // Prendi il valore assoluto di shiftBy
        // Traslazione degli elementi del vettore verso sinistra
        for (int i = 0; i < N - shiftBy; ++i) {
            a[i] = a[i + shiftBy];
        }
        // Rimpiazzo degli ultimi shiftBy elementi con 0
        for (int i = N - shiftBy; i < N; ++i) {
            a[i] = 0;
        }
    } else if (shiftBy > 0) {
        shiftBy = shiftBy % N; // Gestisci il caso in cui shiftBy > N
        // Traslazione degli elementi del vettore verso destra
        for (int i = N - 1; i >= shiftBy; --i) {
            a[i] = a[i - shiftBy];
        }
        // Rimpiazzo dei primi shiftBy elementi con 0
        for (int i = 0; i < shiftBy; ++i) {
            a[i] = 0;
        }
    }

    // Stampare il risultato
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
}

