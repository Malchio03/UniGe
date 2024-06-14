#include <iostream>
using namespace std;

int main() {
    cout << "Inserisci dimensione array: ";
    int N;
    do {
        cin >> N;
        if (N < 0) {
            cout << "Errore: Dimensione negativa, riprova: ";
        }
    } while (N < 0);

    // Array di dimensione N
    int source[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore di a[" << i << "] ";
        cin >> source[i];
    }

    // Array ausiliario per memorizzare gli elementi non ripetuti
    int unique[N];
    int newSize = 1; // Nuova dimensione dell'array unique

    unique[0] = source[0]; // Copia il primo elemento in unique

    for (int i = 1; i < N; ++i) {
        if (source[i] != source[i - 1]) {
            unique[newSize] = source[i];
            newSize++;
        }
    }

    // Copia gli elementi unici da unique a source
    for (int i = 0; i < newSize; ++i) {
        source[i] = unique[i];
    }

    // Azzerare gli elementi rimanenti in source
    for (int i = newSize; i < N; ++i) {
        source[i] = 0;
    }

    // Stampare gli elementi non zero in source
    for (int i = 0; i < N; ++i) {
        if (source[i] != 0) {
            cout << source[i] << " ";
        }
    }
}
