#include <iostream>

using namespace std;

int main() {
    const int N = 4;
    const int elements = N * (N + 1) / 2;

    int tavolaPitagorica[elements];

    // Riempio l'array monodimensionale con i valori della tavola pitagorica
    int index = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            tavolaPitagorica[index++] = i * j;
        }
    }

    int a = 0;
    int b = 0;

    cout << "Inserisci valore di a: ";
    while (a < 1 || a > N) {
        cin >> a;
    };
    cout << "Inserisci valore di b: ";
    while (b < 1 || b > N) {
        cin >> b;
    };

    // Scambio a e b se b < a per mantenere consistenza con l'ordinamento dell'array monodimensionale
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Calcolo l'indice dell'array monodimensionale corrispondente a (a,b)
    int linearIndex = (N * (a - 1) - ((a - 2) * (a - 1)) / 2) + (b - a);

    cout << "Il prodotto dei due numeri secondo la tavola pitagorica è: " << tavolaPitagorica[linearIndex];

    return 0;
}
