// File: rotateN.cpp
#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore per a[" << i << "]: ";
        cin >> a[i];
    }

    int rotateBy;
    cout << "Inserisci il numero di posizioni di rotazione: ";
    cin >> rotateBy;

    rotateBy = rotateBy % N; // Gestisci il caso in cui rotateBy > N

    if (rotateBy < 0) {
        rotateBy = -rotateBy; // Prendi il valore assoluto di rotateBy
        // Rotazione degli elementi del vettore verso sinistra
        for (int i = 0; i < rotateBy; ++i) {
            int temp = a[0];
            for (int j = 0; j < N - 1; ++j) {
                a[j] = a[j + 1];
            }
            a[N - 1] = temp;
        }
    } else if (rotateBy > 0) {
        // Rotazione degli elementi del vettore verso destra
        for (int i = 0; i < rotateBy; ++i) {
            int temp = a[N - 1];
            for (int j = N - 1; j > 0; --j) {
                a[j] = a[j - 1];
            }
            a[0] = temp;
        }
    }

    // Stampare il risultato
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
}
