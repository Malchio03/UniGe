#include <iostream>

using namespace std;

int main() {

    char first;

    do {
        cout << "Inserisci una lettera: ";
        cin >> first;

    } while(first < 'A' || first > 'Z');

    char c = 'Z';

    do {
        if (c < first) {
            first = c;
        }
        cout << "Inserisci una lettera maiuscola (o altro carattere per terminare)";
        cin >> c;
    } while(c >= 'A' && c <= 'Z');

    cout << "La lettera più piccola inserita è " << first << endl;




}