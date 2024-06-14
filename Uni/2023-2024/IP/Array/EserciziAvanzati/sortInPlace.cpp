#include <iostream>
using namespace std;

int main() {
    cout << "Inserisci dimensione array: ";
    int N;
    do {
        cin >> N;
        if ( N < 0 ) {
            cout << "Errore: Dimensione negativa, riprova: ";
        }
    } while(N < 0);

    // Array di dimensione N
    int source[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore di a[" << i << "] ";
        cin >> source[i];    
    }
    // Ordino in modo crescente usando l'algoritmo selection sort
    int index;
    for (int i = 0; i < N; ++i){
        index = i;
        for (int j = i + 1; j < N; j++) {
            if (source[j] < source[index]) {
                index = j;
            }
        }
        int temp = source[i];
        source[i] = source[index];
        source[index] = temp;
    }

    // Stampa
    cout << "Array ordinato in modo crescente: " << endl;

    cout << "{ ";
    for (int i = 0; i < N; ++i) {
        cout << source[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }";
}