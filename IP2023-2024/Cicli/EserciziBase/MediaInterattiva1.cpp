#include <iostream>

using namespace std;

int main() {
    char c;
    int n;
    float media = 0;
    float sum = 0;
    int i = 0;
    do {
        cout << "Inserisci un numero intero: ";
        cin >> n;
        sum += n;
        i++;
        cout << "Vuoi continuare? ";
        cin >> c;
    } while(c != 'n');
    media = sum / i;
    cout << "La media vale: " << media;
}