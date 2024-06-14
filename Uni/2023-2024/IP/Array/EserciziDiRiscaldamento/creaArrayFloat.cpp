#include <iostream>

using namespace std;

int main() {
    const int N = 10;
    float a[N];

    cout << "Inserisci valore di v = ";
    float v;
    cin >> v;

    for (int i = 0; i < N; ++i) {
        a[i] = v * i;
    }

    for (int i = 0; i < N; ++i) {
        cout <<  "Valore di a[" << i << "] = " << a[i] << endl;
    }
}