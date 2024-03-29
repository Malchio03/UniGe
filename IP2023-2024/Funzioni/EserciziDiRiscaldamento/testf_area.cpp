#include <iostream>
using namespace std;

float area(float base, float altezza) {
    if (base && altezza < 0) {
        return - 3;
    }

    if (base < 0) {
        return -1;
    }

    if (altezza < 0) {
        return -2;
    }
    return base * altezza;
}

int main() {
    float b, h;
    cin >> b >> h;
    float a;
    a = area(b, h);
    if (a < 0) {
        if (a == -3) {
            cout << "Entrambi base e altezza non sono positivi." << endl;
        } else if (a == -1) {
            cout << "La base non è positiva." << endl;
        } else if (a == -2) {
            cout << "L'altezza non è positiva." << endl;
        }
    } else {
        cout << "L'area del rettangolo è: " << a << endl;
    }
}