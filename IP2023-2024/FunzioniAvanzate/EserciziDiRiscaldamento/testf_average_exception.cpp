#include <iostream>
using namespace std;

float average(int hm) {

    if (hm < 0) {
        int err = 64;
        throw err;
    }

    float sum = 0;

    for (int i = 0; i < hm; ++i) {
        cout << "Inserisci un numero: ";
        float x;
        cin >> x;
        sum += x;
    }
    return sum / hm;
}

int main() {
    try {
        cout << "Di quanti numeri vuoi fare la media: ";
        int how_many;
        cin >> how_many;

        float media = average(how_many);
        
        cout << "La media è: ";
        cout << media;
        
    } catch(int& err) {
        cout << "Errore 64: numero negativo";
    }
}