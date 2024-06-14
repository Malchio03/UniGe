#include "selectVar_funct.h"
#include <iostream>

using namespace std;

char* selectVar(char& a, char& b, char& c) {
    char* p = nullptr;

    cout << "Scegli fra queste variabili, potrai cambiare idea in seguito e sceglierne una diversa che preferisci" << endl;
    cout << "Vuoi  la prima (y/n)? contiene " << a << endl;
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        p = &a;
    }

    cout << "preferisci la seconda (y/n)? contiene " << b << endl;
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        p = &b;
    }

    cout << "preferisci la terza (y/n)? contiene " << c << endl;
    cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        p = &c;
    }
    return p;
}