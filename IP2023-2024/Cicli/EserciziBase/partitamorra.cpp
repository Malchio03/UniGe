#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); 

    char risposta;
    do {
        cout << "Scegli tra forbice (f), carta (c), o sasso (s): ";
        char mossaGiocatore;
        cin >> mossaGiocatore;

        // Generazione della mossa del computer
        char mossaCPU;
        int randomNumber = rand() % 3;
        switch (randomNumber) {
            case 0:
                mossaCPU = 'f'; // Forbice
                break;
            case 1:
                mossaCPU = 'c'; // Carta
                break;
            case 2:
                mossaCPU = 's'; // Sasso
                break;
        }

        // Determinazione del vincitore
        char vincitore;
        if (mossaGiocatore == mossaCPU)
            vincitore = 'n'; // Pareggio
        else if ((mossaGiocatore == 'f' && mossaCPU == 'c') || (mossaGiocatore == 'c' && mossaCPU == 's') || (mossaGiocatore == 's' && mossaCPU == 'f'))
            vincitore = '1'; // Giocatore 1 vince
        else
            vincitore = '2'; // Giocatore 2 (computer) vince

        cout << "Il computer ha scelto: " << mossaCPU << endl;
        cout << "Il vincitore di questa mano è: ";
        if (vincitore == '1')
            cout << "Giocatore umano." << endl;
        else if (vincitore == '2')
            cout << "Il computer." << endl;
        else
            cout << "Pareggio." << endl;

        cout << "Vuoi continuare? (S/s per sì, altrimenti termina): ";
        cin >> risposta;
    } while (risposta == 'S' || risposta == 's');
}
