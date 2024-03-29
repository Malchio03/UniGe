#include <iostream>
using namespace std;

int factorial(int n) {
    if (n < 0) {
        string err = "Numero negativo";
        throw err;
    }

    if (n == 0) {
        return 1;
    }

    for (int i = n - 1; i > 1; --i) {
        n = n * i;
    }
    return n;
}

int main() {
    try {
        cout << "Inserire un numero positivo: ";
        int num;
        cin >> num;

        cout << "Il fattoriale di " << num << " è " << factorial(num);
    } catch (string& err) {
        cout << err;
    }
}