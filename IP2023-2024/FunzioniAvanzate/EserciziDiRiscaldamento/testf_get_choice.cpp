#include <iostream>
using namespace std;


int get_choice(int max) {
    int scelta;

    do {
        cout << "Inserisci una scelta fra 1 e " << max << endl;
        cin >> scelta;
    } while (scelta < 1 || scelta > max);

    return scelta;
}

int main() {
    int scelta =  get_choice(7);
    cout << "Scelta effetutata: " << scelta;
}