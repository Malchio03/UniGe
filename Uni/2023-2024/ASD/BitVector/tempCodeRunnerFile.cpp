#include <iostream>
using namespace std;

int main() {
    unsigned int x1, x2; 
    x1 = 0;
    x2 = ~0;
    cout << "0: " << x1 << endl;
    cout << "~0: " << x2 << endl; // Stampa il valore di x2 (~0, ovvero tutti i bit impostati a 1)

    cout << "~~0: " << ~x2 << endl; // Stampa il valore ottenuto invertendo nuovamente i bit di x2 (0)

    x1 = 2;
    x2 = 4;
    cout << x1 << "|" << x2 << "=" << (x1 | x2) << endl; // Stampa il risultato dell'operazione OR tra x1 e x2

    x1 = 2;
    x2 = 4;
    cout << x1 << " & " << x2 << " = " << (x1 & x2) << endl; // Stampa il risultato dell'operazione AND tra x1 e x2

    x1 = 6;
    x2 = 4;
    cout << x1 << " | " << x2 << " = " << (x1 | x2) << endl;

    x1 = 6;
    x2 = 4;
    cout << x1 << " & " << x2 << " = " << (x1 & x2) << endl;

    return 0;
}
