#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        cout <<  "Valore di a[" << i << "] = " << a[i] << endl;
    }
}