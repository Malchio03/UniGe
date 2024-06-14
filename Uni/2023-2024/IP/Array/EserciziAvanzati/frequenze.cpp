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
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore di a[" << i << "] ";
        cin >> a[i];
    }

    // Array bool per poi contare le frequenze
    bool b[N];

    // Inizializzo tutti gli elementi dell'array contati a false
    for (int i = 0; i < N; ++i) {
        b[i] = false;
    }

    for (int i = 0; i < N; ++i) {
        if (!b[i]) {
            int cont = 1;  // Conteggio per le frequenze
            for (int j = i + 1; j < N; ++j) {
                if (a[i] == a[j]) {
                    cont++;
                    b[j] = true;
                }
            }
            cout << a[i] << " compare " << cont << " volte" << endl;
            b[i] = true;
        }
    }
}
