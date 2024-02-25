#include <iostream>

using namespace std;

int main() {

    const int N = 2;
    float a[N][N];

   cout << "Inserisci gli elementi della matrice " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Elemento A[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    float det = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
        }
        det = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
    }

    cout << "Valore del determinante: " << det;
}