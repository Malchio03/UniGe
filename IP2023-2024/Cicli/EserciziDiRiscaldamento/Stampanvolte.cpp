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

    cout << "Inserisci carattere da replicare: ";
    char c;
    cin >> c;

    for(int i = 0; i < n; ++i) {
        cout << c << " ";
    }

}