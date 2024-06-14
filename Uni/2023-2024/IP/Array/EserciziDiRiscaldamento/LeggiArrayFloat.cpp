#include <iostream>

using namespace std;

int main() {
    const int N = 5;
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
    cout << " }";
}