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

    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            cout << "*";
        }
        cout << endl;
    }

}