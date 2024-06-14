#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Inserisci un numero: ";
    int n;
    cin >> n;

    int numeroOriginale = n;

    if (n < 0) {
        cout << "Errore: numero negativo";
        return 7;
    }

    int numeroCifre = 0;
    int temp = n;

    // Calcola il numero di cifre nel numero
    while (temp != 0) {
        temp /= 10;
        numeroCifre++;
    }

    int armstrong = 0;

    // Calcola la somma delle potenze delle cifre
    temp = n;
    while (temp != 0) {
        int cifra = temp % 10;
        armstrong += pow(cifra, numeroCifre);
        temp /= 10;
    }

    if (armstrong == numeroOriginale) {
        cout << "Il numero " << numeroOriginale << " è un numero di Armstrong." << endl;
    } else {
        cout << "Il numero " << numeroOriginale << " non è un numero di Armstrong." << endl;
    }
}
