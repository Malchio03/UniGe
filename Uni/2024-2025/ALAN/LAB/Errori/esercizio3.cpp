#include <iostream>
#include <math.h>

using namespace std;

int main() {
    float eps1 = 2.0;  // Base per la precisione in singola precisione
    double eps2 = 2.0; // Base per la precisione in doppia precisione

    int d = 1; // Inizializzazione dell'esponente

    // Calcolo della precisione in singola precisione (float)
    while (1.0f + (float)pow(eps1, -d) > 1.0f) {
        d++;
    } 

    cout << "Precisione singola: " << pow(eps1, -d + 1) << endl;

    // Resetto d per il calcolo della precisione doppia
    d = 1;

    // Calcolo della precisione in doppia precisione (double)
    while (1.0 + pow(eps2, -d) > 1.0) {
        d++;    
    }
    cout << "Precisione doppia: " << pow(eps2, -d + 1) << endl;
}
