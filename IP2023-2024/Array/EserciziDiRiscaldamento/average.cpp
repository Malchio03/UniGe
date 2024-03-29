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
    cout << " }" << endl;

    float sum = 0;

    for (int i = 0; i < N; i++) {
        sum += a[i];
    }

    float average =  sum / N;

    cout << "La media dei valori contenuti nell'array a è: " << average; 
}