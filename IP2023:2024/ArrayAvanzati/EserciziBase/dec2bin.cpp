#include <iostream>
#include <cmath>

using namespace std;

int main() {

    const int N = 10;

    cout << "Inserisci un numero: ";
    int n;
    cin >> n;

    int Elevazione = pow(2, N);

    if (n > Elevazione || n < 0) {
        cout << "Numero NON valido";
    }

    int index = N - 1;

    int Binario[N];

    for (int i = 0; i < N; ++i) {
        Binario[i] = 0;
    }

    while (n > 0) {
        Binario[index] = n % 2;
        n = n / 2;
        index--;
    }


    for (int i = 0; i < N; ++i) {
        cout << Binario[i] << " "; 
    }




    
}