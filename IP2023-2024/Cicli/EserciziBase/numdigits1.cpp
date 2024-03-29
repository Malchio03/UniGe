#include <iostream>

using namespace std;

int main() {
    cout << "Inserisci un numero strettamente positivo: ";
    int k;
    cin >> k;

     int i = 0;

    if (k < 0) {
        cout << "Il numero inserito NON e' valido";
        return 34;
    } else if (k >= 1 && k <= 9) {
        cout << "Il numero inserito e' composto da 1 cifra";
    } else {
        while(k > 0) {
            k = k / 10;
            i++;
        }
        cout << "Il numero inserito e' composto da " << i << " cifre";
    }
}