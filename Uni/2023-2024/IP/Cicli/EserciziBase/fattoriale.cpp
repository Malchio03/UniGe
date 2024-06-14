#include <iostream>
using namespace std;

int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int num;
    cout << "Inserisci un numero intero positivo: ";
    cin >> num;
    int zeros = countTrailingZeros(num);
    cout << "Il numero di zeri alla fine del fattoriale di " << num << " è: " << zeros << endl;
    return 0;
}
