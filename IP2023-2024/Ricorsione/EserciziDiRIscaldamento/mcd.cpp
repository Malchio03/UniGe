#include <iostream>
using namespace std;

unsigned MCD(unsigned m, unsigned n) {
    if (m == n) {
        return m;
    }
    if (m > n) {
        return MCD(m - n, n);
    } else {
        return MCD(m, n - m);
    }
}

int main() {
    int n = 3;
    int m = 6;

    cout << "MCD dei due numeri e: " << MCD(n,m);
}