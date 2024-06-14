#include <iostream>

using namespace std;

int main() {
    const int N = 3;
    float a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore float per a[" << i << "]: ";
        cin >> a[i];
    }

    cout << "I valori contenuti nell'array a sono: { ";
    for (int i = 0; i < N; ++i) {
        cout << a[i];
        if (i < N - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    // Inverti l'ordine degli elementi nell'array
    for (int i = 0; i < N / 2; ++i) {
        float temp = a[i];
        a[i] = a[N - 1 - i];
        a[N - 1 - i] = temp;
    }

    cout << "I valori contenuti nell'array a in ordine inverso sono: { ";
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << " }" << endl;

    return 0;
}
