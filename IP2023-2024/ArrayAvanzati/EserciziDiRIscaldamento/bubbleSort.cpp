#include <iostream>

using namespace std;

int main() {
    const int N = 6;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    bool scambiati;
    for (int i = 1; i < N; ++i) {
        scambiati = false;
        for (int j = 0; j < N - i; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                scambiati = true;
            }
        }
        if (!scambiati) {       // Se non ci sono stati scambi, l'array è già ordinato
            break;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }

}