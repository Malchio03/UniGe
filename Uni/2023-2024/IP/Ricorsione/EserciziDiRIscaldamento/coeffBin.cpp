#include <iostream>
using namespace std;

unsigned coeffBin(unsigned n, unsigned k) {
    if (k > n) {
        string err = "Errore: k > n";
        throw err;
    }
    if (n == k || k == 0) {
        return 1;
    }

    return coeffBin(n - 1, k - 1) + coeffBin(n - 1, k);
}

int main() {
    cout << "Inserisci n: ";
    int n;
    cin >> n;
    cout << "Inserisci k: ";
    int k;
    cin >> k;
    try {
        cout << "Risultato: " << coeffBin(n,k);
    }catch(string &err) {
        cout << err;
    }
}