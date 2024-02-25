#include <iostream>

using namespace std;

int main() {

    const int N = 1000;

    bool isprime[N];

    // Ciclare su tutti gli N elementi di isprime per impostarli a true
    for (int i = 0; i < N - 1; ++i) {
        isprime[i] = true;
    }

    // Impostare gli elementi di isprime con indice 0 e 1 a false
    isprime[0] = false;
    isprime[1] = false;

    for (int p = 2; p < N - 1; ++p) {
        if (isprime[p]) {
            for (int i = 2; i * p < N - 1; ++i) {
                isprime[p * i] = false;
            }
        }
    }

    // Stampa tutti i numeri primi

    for (int i = 0; i < N - 1; ++i) {
        if (isprime[i] == true) {
            cout << i << " ";
        }
    }

}

