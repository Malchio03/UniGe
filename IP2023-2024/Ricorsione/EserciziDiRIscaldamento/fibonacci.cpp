#include <iostream>
using namespace std;

unsigned fibonacci(unsigned n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Inserisci n: ";
    int n;
    cin >> n;
    cout << "Fibonacci: " << fibonacci(n);
}