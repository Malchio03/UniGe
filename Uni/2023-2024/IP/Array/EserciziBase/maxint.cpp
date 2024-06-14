#include <iostream>

using namespace std;

int main() {
    const int N = 5;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    int max = a[0];

    for (int i = 1; i  < N; ++i) {
            if (a[i] > max) {
                max = a[i];
        }
    }

    int maxCount = 0;

    for (int i = 0; i < N - 1; ++i) {
        if (a[i] == max) {
            maxCount++;
        }
    }

    cout << "maxVal: " << max << endl;
    cout << "maxCount: " << maxCount;
}