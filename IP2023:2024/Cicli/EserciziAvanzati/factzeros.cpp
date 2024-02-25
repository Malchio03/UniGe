#include <iostream>
using namespace std;

int main() {
    cout << "Inserisci un numero intero positivo: ";
    int numero;
    cin >> numero;

    if (numero < 0) {
        cout << "Errore: numero negativo." << endl;
        return 1;
    }

    int zeri = 0;
    while (numero >= 5) {
        zeri += numero / 5;
        numero /= 5;
    }

    cout << "Il numero di zeri alla fine del fattoriale di " << numero << " è: " << zeri << endl;

    return 0;
}
