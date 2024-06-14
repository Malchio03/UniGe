#include <iostream>
using namespace std;

void print_rhombus(int n) {
    // Stampare la parte superiore del rombo
    for (int i = 1; i <= n; ++i) {
        // Stampa spazi bianchi
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Stampare la parte inferiore del rombo
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Inserisci un numero intero per la dimensione del rombo: ";
    cin >> n;
    print_rhombus(n);
}
