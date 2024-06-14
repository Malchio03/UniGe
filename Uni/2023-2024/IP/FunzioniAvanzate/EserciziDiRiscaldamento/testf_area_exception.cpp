#include <iostream>
using namespace std;

float area(float base, float altezza) {

    if (base && altezza < 0) {
        int err = 3;
        throw err;
    }
    if (base < 0) {
        int err = 1;
        throw err;
    }
    if (altezza < 0) {
        int err = 2;
        throw err;
    }

    return base * altezza;
}

int main() {
    float b, h;
    cout << "Inserisci base e altezza: ";
    cin >> b >> h;
    try {
        float a;
        
        a = area(b, h);

        cout << "L'area vale: " << a;
        
    } catch(int& err) {
        if (err == 1) {
            cout << "Base negativa";
        } else if (err == 2) {
            cout << "Altezza negativa";
        } else {
            cout << "Valori non validi";
        }
    }
}