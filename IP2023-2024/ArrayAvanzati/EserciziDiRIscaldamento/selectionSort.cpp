#include <iostream>

using namespace std;

int main() {
    const int N = 3;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    int index;
    
    for (int i = 0; i < N - 1; ++i) {
        index = i;
        for (int j = i + 1; j < N; ++j) {
            if (a[j] < a[index]) {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }

    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }

}