#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int i = 0;
    cout << "Inserisci un numero positivo: ";
    cin >> n;
    if (n < 0) {
        cout << "numero negativo, riprova ";
        cin >> n;
        while (n < 0) {
        cout << "Numero non valido ";
        cin >> n;
    }
    }

    if (n >= 1 && n <= 9) {
        cout << "Il numero e composto da una sola cifra ";
    } else {
        
        while (n > 0) {
            n = n / 10;
            i++;
        }
        cout << "Il numero inserito e' composto da " << i << " cifre" ;
    }
}