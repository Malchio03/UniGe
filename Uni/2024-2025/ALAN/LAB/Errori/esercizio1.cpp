#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int d0 = 0;
    int d1 = 0;

    double a[7];    // array contenente tutte le combinazioni di i {0,1..,6}
    double b = (d1 + 1) * pow(10,20);
    double c = -b;

    double result1;
    double result2;
    double differenza;

    // calcolo per ciascun valore di a
    for (int i = 0; i < 7; ++i) {
        a[i] = (d0 + 1) * pow(10,i);        // a = (d0 + 1) * 10^i
    }

    // calcoliamo (a+b)+c e a+(b+c) per ogni valore di i
    for (int i = 0; i < 7; ++i) {
        result1 = ((a[i] + b) + c);
        result2 = (a[i] + (b + c));
        differenza = fabs(result1 - result2);       // usiamo il modulo visto che l'obiettivo è quello di vedere la differenza tra un risultato e l'altro

        cout << "Per i = " << i << ": " << endl;
        cout << "(a+b)+c = " << result1 << endl;
        cout << "a+(b+c) = " << result2 << endl;
        cout << "Differenza: " << differenza << endl;
        cout << "---------------------" << endl;
    }
}   