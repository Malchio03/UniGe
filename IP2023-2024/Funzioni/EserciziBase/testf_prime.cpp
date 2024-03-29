#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[5] = {1, 2, 3, 4, 16};

    for (int i = 0; i < 5; ++i) {
        cout << boolalpha;
        cout << "Il numero " << a[i] << " è primo: ";
        cout << isPrime(a[i]);
        cout << endl;
    }
}