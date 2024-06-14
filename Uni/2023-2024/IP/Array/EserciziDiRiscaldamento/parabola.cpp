#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int N = 10;
    float arr[N];

    float a, b, c;

    cout << "Inserisci valore di a = ";
    cin >> a;
    cout << "Inserisci valore di b = ";
    cin >> b;
    cout << "Inserisci valore di c = ";
    cin >> c;


    cout << "Valori nell'intervallo [0,9] della parabola " << a << "x^2 + " << b << "x + " << c << endl;

    for (int x = 0; x < N; x++) {
        arr[x] = (a * (pow(x , 2))) + (b * (x)) + c; 
    }

     for (int i = 0; i < N; ++i) {
        cout <<  "Valore di a[" << i << "] = " << arr[i] << endl;
    }
}