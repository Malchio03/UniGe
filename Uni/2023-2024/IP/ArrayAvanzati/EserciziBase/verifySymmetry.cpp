#include <iostream>

using namespace std;

int main() {

    const int N = 3;
    float a[N][N];

    cout << "Inserisci gli elementi della matrice " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Elemento A[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    bool simmetrica = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] != a[j][i]) {
                simmetrica = false;
                break;
            } 
        }
    }
    cout << boolalpha;
    cout << "La matrice è simmetrica?: " << simmetrica;
}