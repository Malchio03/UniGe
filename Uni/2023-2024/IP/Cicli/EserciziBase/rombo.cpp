#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Input del numero intero positivo n
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;
    
    // Stampa del triangolo superiore del rombo
    for (int i = 0; i <= n; ++i) {
        // Stampa degli spazi bianchi
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        // Stampa degli asterischi
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Stampa del triangolo inferiore del rombo
    for (int i = n - 1; i >= 0; --i) {
        // Stampa degli spazi bianchi
        for (int j = 0; j < n - i; ++j) {
            cout << " ";
        }
        // Stampa degli asterischi
        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}
