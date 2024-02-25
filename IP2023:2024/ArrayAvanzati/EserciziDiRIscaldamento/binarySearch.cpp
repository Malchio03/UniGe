#include <iostream>

using namespace std;

int main() {
    const int N = 15;
    int a[N];

    for (int i = 0; i < N; ++i) {
        cout << "Inserisci valore intero per a[" << i << "]: ";
        cin >> a[i];
    }

    int item;
    cout << "Quale elemento vuoi cercare? ";
    cin >> item;

    bool found = false;
    int max = N - 1;
    int mid = 0;
    int min = 0;

    while (min <= max && !found) {
        mid = (max + min) / 2;

        if (a[mid] == item) {
            found = true;
            break;
        } else if (a[mid] > item) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    if (found) {
        cout << "Trovato! ";
    } else {
        cout << "Elemento non trovato";
    }

}