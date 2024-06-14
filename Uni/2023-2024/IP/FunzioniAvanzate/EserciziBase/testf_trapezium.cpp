#include <iostream>
#include <string>
using namespace std;

void replicate(int length, char c) {
    if (length < 0) {
        string err = "Errore valore < 1";
        throw err;
    }
    for (int i = 1; i <= length; ++i) { 
        cout << c;
    }
}

void trapezio(int a, int b) {
    int altezza = (b - a) + 1;

    for (int i = 0; i < altezza; ++i) {
        replicate(a + i, 'x'); // Stampa una riga con il numero corretto di asterischi
        cout << endl; // Vai a capo dopo ogni riga
    }
}


int main() {
    try {
        cout << "Inserisci prima base: ";
        int a;
        cin >> a;
        cout << "Inserisci seconda base: ";
        int b;
        cin >> b;
        trapezio(a, b);
    } catch (string& err) {
        cout << err;
    }
}

