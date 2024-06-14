#include <iostream>

using namespace std;

int main() {

    const int N = 4;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore per a[" << i << "]: ";
        cin >> a[i];
    }

    int temp = a[0];
    a[0] = a[N - 1];

    for (int i = N - 1; i > 1; --i) {
        a[i] = a[i - 1];
    }

    a[1] = temp;



    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
   
    
}