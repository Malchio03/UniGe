#include <iostream>

using namespace std;

int main() {
    const int N = 10;

    int tavolaPitagorica[N][N];

    // Creo la tavola pitagorica
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tavolaPitagorica[i][j] = (i + 1) * (j + 1);
        }
    }

    int a = 0;
    int b = 0;

    cout << "Inserisci valore di a: ";
    while (a < 1 || a > 10) {
        cin >> a;
    };
    cout << "Inserisci valore di b: ";
    while (b < 1 || b > 10) {
        cin >> b;
    };

    cout << "Il prodotto dei due numeri secondo la tavola pitagorica è: " << tavolaPitagorica[a - 1][b - 1];
   
}