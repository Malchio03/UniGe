#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x, y;
};

double dist(Punto p1, Punto p2) {
    double diff_x = p2.x - p1.x;
    double diff_y = p2.y - p1.y;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

int main() {
    const int N = 3;
    Punto punti[N];

    cout << "Inserisci le coordinate dei punti:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Punto " << i + 1 << ": ";
        cin >> punti[i].x >> punti[i].y;
    }

    // Calcolo della lunghezza totale della linea spezzata
    double lunghezza_totale = 0.0;
    for (int i = 0; i < N - 1; ++i) {
        lunghezza_totale += dist(punti[i], punti[i + 1]);
    }

    cout << "La lunghezza della spezzata è " << lunghezza_totale << endl;
}
