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

    bool indovinato = false;
    int quadrato = n * n;
    int result;
    do {
        cout << "Indovina il quadrato del numero intero " << n << ": ";
        cin >> result;

        if (quadrato == result ) {
            cout << "Bravo!";
            indovinato = true;
            break;
        } else {
            cout << "Errato, riprova" << endl;
        }
    } while (indovinato == false);
}