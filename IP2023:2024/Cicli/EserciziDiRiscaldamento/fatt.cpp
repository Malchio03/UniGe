#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci numero : ";
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Errore: il numero doveva essere positivo";
        return 7;
    }

    int fattoriale = 1;

    for (int i = n; i >= 1; --i) {
        fattoriale = fattoriale * i;
    }

    cout << "Il fattoriale di " << n << " è " << fattoriale;

}