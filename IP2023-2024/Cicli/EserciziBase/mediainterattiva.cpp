#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    int i = 0;
    char c;
    
    do {
        cout << "inserisci un numero: ";
        cin >> n;

        if (n >= 0) {
            sum += n;
            i++;
        }

        if (n < 0) {
            cout << "Numero negativo";
        }
        cout << "Vuoi continuare? ";
        cin >> c;
    } while (c != 'n');

    float media;

    media = sum / i;

    cout << "Media " << media;
}
