#include <iostream>
#include <cmath>
using namespace std;

bool armstrong(int n) {
    int temp = n;

    // Calcolo della lunghezza totale del numero
    int lunghezza = 0;
    while (n > 0) {
        n = n / 10;
        lunghezza++;
    }
    
    // Calcolo del numero di Armstrong
    int somma = 0;
    n = temp; // Ripristina il valore originale di n
    while (temp > 0) {
        int cifra = temp % 10;
        somma += pow(cifra , lunghezza);
        temp = temp / 10;
    }

    // Verifica se il numero è un numero di Armstrong
    return (n == somma);
}

int main() {
    int numero;
    cout << "Inserisci un numero: ";
    cin >> numero;

    if (armstrong(numero))
        cout << numero << " è un numero di Armstrong." << endl;
    else
        cout << numero << " non è un numero di Armstrong." << endl;
}
