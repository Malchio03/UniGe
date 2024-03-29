#include <iostream>
using namespace std;

// Se non passo per riferimento (&) la funzione non effettua lo scambio
void swapDouble(double &a, double &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    double a = 2.0;
    double b = 5.4;
    cout << "Valore di a e b prima dello scambio: " << a << ", " << b << endl;
    swapDouble(a,b);
    cout << "Valore di a e b prima dopo lo  scambio: " << a << ", " << b << endl;
}