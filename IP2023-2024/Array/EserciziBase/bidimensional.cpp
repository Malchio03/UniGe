#include <iostream>

using namespace std;

int main() {
    const int N = 8;    // Colonne
    const int M = 5;    // Righe

    int a[M][N];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = i;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}