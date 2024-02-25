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

    // Trovo elemento piu grande
    int max = a[0];
    
    for (int i = 0; i < N; ++i) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    bool trovato = false;
    int secondo_max = -2147483648;

    for (int i = 0; i < N; ++i) {
        if (secondo_max< a[i] && a[i] != max) {
            secondo_max = a[i];
            trovato = true;
        }
    }

    cout << "Valore massimo: " << max << endl;
    if (trovato == true) {
        cout << "Secondo massimo: " << secondo_max << endl;
    }


}