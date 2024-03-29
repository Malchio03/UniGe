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
    int loc = -1;

    for (int i = 0; i < N; ++i) {
        if (a[i] == item) {
            loc = i;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "L'elemento " << item << " è stato trovato in "  << loc << " posizione";
    } else {
        cout << "Elemento non trovato";
    }
}