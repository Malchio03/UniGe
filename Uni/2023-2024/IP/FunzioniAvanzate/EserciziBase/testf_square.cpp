#include <iostream>
#include <string>
using namespace std;

void square(int n) {
    if (n <= 0) {
        string err = "Errore valore < 1";
        throw err;
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0 || i == n - 1) { // Prima e ultima riga
            for (int j = 0; j < n; ++j) {
                cout << "x ";
            }
        } else { // Altre righe
            cout << "x ";
            for (int j = 1; j < n - 1; ++j) {
                cout << "  "; // Spazi vuoti
            }
            cout << "x ";
        }
        cout << endl;
    }
}

int main() {
    try {
        cout << "Inserisci un numero intero positivo: ";
        int n;
        cin >> n;
        square(n);
    } catch (string& err){
        cout << err;
    }
}
