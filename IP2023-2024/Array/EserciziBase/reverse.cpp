#include <iostream>

using namespace std;

int main() {
    const int N = 3;
    int source[N];

    // Inserimento elementi di source
    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> source[i];
    }
    int dest[N];
    // Copia elementi di source a dest in ordine inverso
    for (int i = 0; i < N; ++i) {
        dest[i] = source[N - 1 - i];
    }

     // Output di source e dest
    cout << "Array originale (source): ";
    for (int i = 0; i < N; ++i) {
        cout << source[i] << " ";
    }
    cout << endl;

    cout << "Array inverso (dest): ";
    for (int i = 0; i < N; ++i) {
        cout << dest[i] << " ";
    }
    cout << endl;


}