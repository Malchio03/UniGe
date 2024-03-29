#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Inserisci un numero maggiore di 0: ";
    int k;
    cin >> k;

    if (k < 0) {
        cout << "Errore: il numero doveva essere positivo";
        return 66;
    }

    cout << "Rovesciando: " << k;

    int inv = 0;

    while (k > 0) {
        int mod = k % 10;
        k = k / 10;
        inv = inv * 10;
        inv = inv + mod;
    };

    cout << " si ottiene " << inv;





}