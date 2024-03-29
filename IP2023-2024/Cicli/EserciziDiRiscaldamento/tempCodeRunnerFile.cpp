#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci un numero maggiore di 0: ";
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Errore: il numero doveva essere positivo";
        return 1;
    }

    int inverso = 0;

    while (n > 0) {
        int cifra = n / 10;     //Estraggo ultima cifra
        inverso = inverso * 10;
        inverso += cifra;
    }

    cout << "numero inverso: " << inverso;

}