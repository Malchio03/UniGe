#include<iostream>
using namespace std;

const int N = 3;

void iarray(int a[]) {
    cout << "Inserisci elementi:";
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
}

void swap(int a[]) {
    for (int i = 0; i < N; ++i) {
        a[i] = a[i + 1];
    }
    a[N - 1] = 0;
}
int main() {
    int array[N];
    iarray(array);
    swap(array);
    // stampa
    for (int i = 0; i < N;++i ) {
        cout << array[i] << " ";
    }
}