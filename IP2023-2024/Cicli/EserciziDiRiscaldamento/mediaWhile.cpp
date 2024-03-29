#include <iostream>

using namespace std;

int main() {
    cout << "Di quanti numeri vuoi fare la media?: ";
    int how_many;
    cin >> how_many;

    if (how_many < 0) {
        cout << "Errore: il numero doveva essere positivo";
        return 42;
    }
    float sum = 0;

    int i = 0;

    while (i < how_many) {
        cout << "Inserisci un numero: ";
        int n;
        cin >> n;
        sum += n;
        i++;
    };
    
    cout << "La media è " << sum / how_many;

}