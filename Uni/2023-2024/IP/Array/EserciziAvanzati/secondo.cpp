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

     // Caso particolare in cui la dimensione vale solo 2
     if (N == 2) {
        cout << "Elemento piu grande: " << max << endl;
        return 30;
     }

    // Trovo secondo elemento piu grande
    int min = -2147483648; // Valore minimo rappresentabile per un intero a 32 bit

    bool esiste = false;

    for (int i = 0; i < N; ++i) {
        if (min < a[i] && a[i] != max) {
            min = a[i];
            esiste = true;
        } else if(min == max){
            esiste = false;
        }else if (min >= a[i] && a[i] != max) {
            esiste = true;
        }
        }
    cout << "Elemento piu grande: " << max << endl;
    if (esiste) {
        cout << "Il secondo valore piu grande e: " << min << endl;
    }

}