#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    float v[N];
    float* p = v;

    // *** Inserimento Valori Array ***
    for (int i = 0; i <= N - 1; ++i) {
        cin >> *p;
        p++;
    }

    // *** Stampa Valori Array ***
    cout << "Stampa valori:" << endl;
    p = v;
    for (int i = 0; i <= N - 1; ++i) cout << *p++ << endl;

    // *** Calcolo Media ***
    float sum = 0;
    p = v;
    for (int i = 0; i <= N - 1; ++i) {
        sum += *p;
        p++;
    }

    // *** Stampa Media ***
    cout << "Media: " << sum / N;

}