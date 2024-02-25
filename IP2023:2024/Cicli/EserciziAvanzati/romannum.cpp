#include <iostream>
#include <string>
using namespace std;

int main() {
    int numero;
    cout << "Inserisci un numero intero positivo compreso fra 1 e 3000: ";
    cin >> numero;

    if (numero < 1 || numero > 3000) {
        cout << "Errore: il numero inserito non è compreso nell'intervallo richiesto." << endl;
        return 1;
    }

    string romano = "";
    
    // Convertire migliaia
    while (numero >= 1000) {
        romano += "M";
        numero -= 1000;
    }
    
    // Convertire centinaia
    if (numero >= 900) {
        romano += "CM";
        numero -= 900;
    }
    else if (numero >= 500) {
        romano += "D";
        numero -= 500;
    }
    else if (numero >= 400) {
        romano += "CD";
        numero -= 400;
    }
    while (numero >= 100) {
        romano += "C";
        numero -= 100;
    }
    
    // Convertire decine
    if (numero >= 90) {
        romano += "XC";
        numero -= 90;
    }
    else if (numero >= 50) {
        romano += "L";
        numero -= 50;
    }
    else if (numero >= 40) {
        romano += "XL";
        numero -= 40;
    }
    while (numero >= 10) {
        romano += "X";
        numero -= 10;
    }
    
    // Convertire unità
    if (numero >= 9) {
        romano += "IX";
        numero -= 9;
    }
    else if (numero >= 5) {
        romano += "V";
        numero -= 5;
    }
    else if (numero >= 4) {
        romano += "IV";
        numero -= 4;
    }
    while (numero >= 1) {
        romano += "I";
        numero -= 1;
    }

    cout << "Il numero in notazione romana è: " << romano << endl;
}
