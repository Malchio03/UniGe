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
    }while(N < 0);

    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore di a[" << i << "] ";
        cin >> a[i];
    }

    int b[N];

    bool palyndrome = true;

    for (int i = 0; i < N; ++i) {
        b[i] = a[N - i - 1];
    }

    for (int i = 0; i < N; ++i) {
        if (b[i] != a[i]) {
            palyndrome = false;
            break;
        }
    }
    cout << boolalpha;
    cout << "L'array è palindromo: " << palyndrome;

    


}