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
    int newSize = 0;

    for (int i = 0; i < N - 1; ++i) {
        if (source[i] == source[i + 1]) {
            source[i] = 0;
        }
    }

    cout << "Stampa di source" << endl;
    for (int i = 0; i < N; ++i) {
        cout << source[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < N; ++i) {
        if (source[i] != 0) {
            unique[newSize] = source[i];
            newSize++;
        }
    }

    cout << "Stampa di unique" << endl;
    for (int i = 0; i < newSize; ++i) {
        cout << unique[i] << " ";
    }
}
