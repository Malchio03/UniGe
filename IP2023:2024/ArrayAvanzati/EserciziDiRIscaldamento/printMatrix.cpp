#include <iostream>

using namespace std;

int main() {
    const int M = 3;
    const int N = 4;
    int a[M][N];

    for (int i = 0; i < M; ++i) {
       for (int j = 0; j < N; ++j) {
        cout << "Inserisci valore: ";
        cin >> a[i][j];
       }
}
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
        cout << a[i][j] << " ";
       }
       cout << endl;
    }
}