#include <iostream>
using namespace std;

float average(int hm) {
    if (hm < 0) {
        cout << "Errore: hm negativo";
        exit(0);
    }
    float sum = 0;

    for (int i = 0; i < hm; ++i) {
        cout << "Inserisci un numero: " << endl;
        float x;
        cin >> x;
        sum += x;
    }
    return sum / hm;
}

int main() {
    cout << "Di quanti numeri vuoi fare la media? ";
    int how_many;
    cin >> how_many;
    float avg = average(how_many);
    cout << "La media è ";
    cout << avg;
}