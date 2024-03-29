#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Inserisci un numero intero positivo: " << endl;
        cin >> n;
        if (n < 0) {
            cout << "Errore, hai inserito un numero negativo" << endl;
        }
    } while(n < 0);

    // Triangolo superiore
    for (int i = 0; i < n; ++i) {
        for (int j = i; j <= n; ++j) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Triangolo inferiore
    for (int i = n; i >= 0; --i) {
        for (int j = i; j <= n; ++j) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            cout << "*";
        }
        cout << endl;
    }


}
