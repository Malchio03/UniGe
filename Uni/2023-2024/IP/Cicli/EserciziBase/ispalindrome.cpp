#include <iostream>
using namespace std;

int main() {
    cout << "Inserisci un numero intero positivo: ";
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Errore: il numero non e positivo";
        return 32;
    }

    int numeroOriginale = n;
    int cifra;
    int reverse = 0;
    
    while(n > 0) {
        cifra = n % 10; //estraggo ultima cifra
        n = n / 10;
        reverse = reverse * 10;
        reverse = cifra + reverse;
    }

    if (reverse == numeroOriginale) {
        cout << "Il numero e palindromo";
    } else {
        cout << "Il numero non e palindromo";
    }

}