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

   for (int i = 0; i < N - 1; ++i) {
    if (source[i] == source[i + 1]) {
        source[i] = 0;
        //break;
    }
}

    for (int i = 0; i < N; ++i) {
        if (source[i] != 0) {
            cout << source[i] << " ";
    }
}
}