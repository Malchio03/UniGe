#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

int main() {
    int N = 3; // Cambia il valore di N a 3
    Point a[N];
    double distanza = 0.0;
    bool stessaLunghezza = true;
    bool lineaChiusa = false;
    double lunghezzaSegmento = 0.0;

    // Input delle coordinate dei punti
    for (int i = 0; i < N; ++i) {
        cout << "Inserisci le coordinate del punto " << i + 1 << ": ";
        cin >> a[i].x >> a[i].y;
    }

    // Calcolo della distanza tra i punti e verifica della lunghezza dei segmenti
    for (int i = 0; i < N - 1; ++i) {
        double parentesi_x = pow(abs(a[i].x - a[i + 1].x), 2);
        double parentesi_y = pow(abs(a[i].y - a[i + 1].y), 2);
        double distanzaSegmento = sqrt(parentesi_x + parentesi_y);
        distanza += distanzaSegmento;

        if (i == 0)
            lunghezzaSegmento = distanzaSegmento;
        else {
            if (lunghezzaSegmento != distanzaSegmento)
                stessaLunghezza = false;
        }
    }

    // Verifica se la linea è chiusa
    if (a[0].x == a[N - 1].x && a[0].y == a[N - 1].y)
        lineaChiusa = true;

    cout << "La distanza totale tra i punti vale: " << distanza << endl;

    // Nome del poligono
    string nomePoligono;
    switch (N - 1) {
        case 3:
            nomePoligono = "triangolo";
            break;
        case 4:
            nomePoligono = "rettangolo";
            break;
        case 5:
            nomePoligono = "pentagono";
            break;
        default:
            nomePoligono = "poligono";
            break;
    }

    if (lineaChiusa)
        cout << "La linea è chiusa e quindi definisce un " << nomePoligono << "." << endl;
    else
        cout << "La linea non è chiusa." << endl;

    if (stessaLunghezza) {
        cout << "Tutti i lati hanno la stessa lunghezza." << endl;
        if (lineaChiusa && (N - 1 >= 3 && N - 1 <= 5))
            cout << "Il " << nomePoligono << " è regolare." << endl;
    } else {
        cout << "Non tutti i lati hanno la stessa lunghezza." << endl;
    }
}
