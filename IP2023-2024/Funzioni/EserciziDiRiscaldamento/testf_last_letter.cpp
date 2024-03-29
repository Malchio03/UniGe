#include <iostream>
using namespace std;

char last_letter() {
    cout << "Inserisci una lettera minuscola ";
    char last;
    do {
        cin >> last;
    } while (last < 'a' || last > 'z');

    char c;
    do {
        cout << "Inserisci una lettera minuscola (o altro carattere per terminare): ";
        cin >> c;
        if (c >= 'a' && c <= 'z' && c > last) {
            last = c;
        }
    } while (c >= 'a' && c <= 'z');

    return last;
}

int main() {
    char last = last_letter();
    cout << "La lettera più grande inserita è: " << last << endl;
}
