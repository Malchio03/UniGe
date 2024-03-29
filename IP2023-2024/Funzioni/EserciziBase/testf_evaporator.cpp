#include <iostream>
using namespace std;

int giorniOperativi(float litri_iniziali, int percentuale_evaporazione, float soglia_minima) {
    int giorni = 0;
    while (litri_iniziali > soglia_minima) {
        litri_iniziali -= (litri_iniziali * percentuale_evaporazione / 100);
        giorni++;
    }
    return giorni;
}

int main() {
    float litri_iniziali = 10.0; 
    int percentuale_evaporazione = 5;
    float soglia_minima = 1.0; 

    int giorni = giorniOperativi(litri_iniziali, percentuale_evaporazione, soglia_minima);
    cout << "La macchina può operare per " << giorni << " giorni senza essere riempita." << endl;
}
