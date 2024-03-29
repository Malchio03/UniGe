#include <iostream>
using namespace std;

int countZerosInFactorial(int n) {
    int count = 0;

    // Conta quante volte 5 compare nei fattori del fattoriale di n
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }

    return count;
}

int main() {
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;

    int zeros = countZerosInFactorial(n);
    cout << "Il numero di zeri alla fine del fattoriale di " << n << " è: " << zeros << endl;
}
