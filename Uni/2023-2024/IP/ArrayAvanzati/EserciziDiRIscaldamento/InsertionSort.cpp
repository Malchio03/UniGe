#include <iostream>

using namespace std;

int main() {
    const int N = 6;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    int current, prev;
    for (int i = 1; i < N; ++i) {
        current = i;
        prev = i - 1;
        while (prev >= 0 && a[current] < a[prev]) {
            int temp = a[current];
            a[current] = a[prev];
            a[prev] = temp;
            prev--;
            current--;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }

}