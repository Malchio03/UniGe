#include <iostream>

using namespace std;

int main() {
   cout << "Inserisci un numero maggiore di 0: ";
    int n;
    char answer;
   do {
    cin >> n;

    if (n < 0) {
        cout << "Errore: il numero doveva essere positivo";
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << " | ";
    }
    cout << "\nDesideri continuare? (premi n per terminare o altro tasto per continuare): ";
    cin >> answer;
   } while(answer != 'n');
}