#include <iostream>
using namespace std;

int main() {

    const int N = 4;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore per a[" << i << "]: ";
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        a[i] = a[i + 1];
    }

    a[N - 1] = 0;


    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
   
    
}