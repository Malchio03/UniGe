#include <iostream>

using namespace std;

int main() {

    char first = 'A';
    char c;

    do {
        cout << "Inserisci una lettera: ";
        cin >> c;

        if (c > first && c >= 'A' && c <= 'Z') {
            first = c;
        }

    } while(c >= 'A' && c <= 'Z');


    cout << "La lettera più grande inserita è " << first << endl;




}