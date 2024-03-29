#include <iostream>
#include <cmath>
using namespace std;

struct Time {
    unsigned int ora;
    unsigned int minuti;
    unsigned int secondi;
};

int main() {
    Time T1, T2;

    cout << "Inserisci primo orario (ora, minuti, secondi): ";
    cin >> T1.ora >> T1.minuti >> T1.secondi;

    cout << "Inserisci secondo orario (ora, minuti, secondi): ";
    cin >> T2.ora >> T2.minuti >> T2.secondi;

    // Controllo T1
    if (T1.ora > 23 || T1.minuti > 59 || T1.secondi > 59) {
        cout << "Errore: almeno uno dei valori per l'orario T1 non è valido." << endl;
        return 1;
    }

    // Controllo T2
    if (T2.ora > 23 || T2.minuti > 59 || T2.secondi > 59) {
        cout << "Errore: almeno uno dei valori per l'orario T2 non è valido." << endl;
        return 1;
    }

    // Verifica se T1 è precedente o uguale a T2
    if (T1.ora > T2.ora || (T1.ora == T2.ora && T1.minuti > T2.minuti) || (T1.ora == T2.ora && T1.minuti == T2.minuti && T1.secondi > T2.secondi)) {
        cout << "Errore: l'orario T1 non è precedente o uguale a T2." << endl;
        return 1;
    }

    // Calcola il tempo trascorso
    int oreTrascorse = T2.ora - T1.ora;
    int minutiTrascorsi = T2.minuti - T1.minuti;
    int secondiTrascorsi = T2.secondi - T1.secondi;

    if (secondiTrascorsi < 0) {
        secondiTrascorsi += 60;
        minutiTrascorsi--;
    }
    if (minutiTrascorsi < 0) {
        minutiTrascorsi += 60;
        oreTrascorse--;
    }

    cout << "Sono trascorse " << oreTrascorse << " ore, " << minutiTrascorsi << " minuti e " << secondiTrascorsi << " secondi." << endl;

    return 0;
}
