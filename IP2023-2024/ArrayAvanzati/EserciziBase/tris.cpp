#include <iostream>
#include <string>
using namespace std;

int main() {
    const int N = 3;
    char a[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char Giocatore1 = 'X';
    char Giocatore2 = 'O';

    int Posizione;
    int turni = 0;

    // Stampa della griglia
    while (turni < 9) {
        // Alternanza dei giocatori
        char giocatoreCorrente = (turni % 2 == 0) ? Giocatore1 : Giocatore2;

        cout << "Turno del giocatore " << giocatoreCorrente << ". Inserisci la tua mossa (numero da 1 a 9): ";
        cin >> Posizione;

        // Controllo se la mossa è valida e la casella è libera
        if (Posizione < 1 || Posizione > 9 || a[(Posizione - 1) / 3][(Posizione - 1) % 3] == 'X' || a[(Posizione - 1) / 3][(Posizione - 1) % 3] == 'O') {
            cout << "Mossa non valida. Riprova." << endl;
            continue;
        }

        // Aggiornamento griglia
        if (Posizione == 1) a[0][0] = giocatoreCorrente;
        else if (Posizione == 2) a[0][1] = giocatoreCorrente;
        else if (Posizione == 3) a[0][2] = giocatoreCorrente;
        else if (Posizione == 4) a[1][0] = giocatoreCorrente;
        else if (Posizione == 5) a[1][1] = giocatoreCorrente;
        else if (Posizione == 6) a[1][2] = giocatoreCorrente;
        else if (Posizione == 7) a[2][0] = giocatoreCorrente;
        else if (Posizione == 8) a[2][1] = giocatoreCorrente;
        else if (Posizione == 9) a[2][2] = giocatoreCorrente;

        turni++;

        // Stampa della griglia aggiornata
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << " " << a[i][j] << " ";
                if (j < N - 1) {
                    cout << "|";
                }
            }
            cout << endl;
            if (i < N - 1) {
                cout << "-----------" << endl;
            }
        }

        // Controllo vittoria
        if ((a[0][0] == giocatoreCorrente && a[0][1] == giocatoreCorrente && a[0][2] == giocatoreCorrente) ||
            (a[1][0] == giocatoreCorrente && a[1][1] == giocatoreCorrente && a[1][2] == giocatoreCorrente) ||
            (a[2][0] == giocatoreCorrente && a[2][1] == giocatoreCorrente && a[2][2] == giocatoreCorrente) ||
            (a[0][0] == giocatoreCorrente && a[1][0] == giocatoreCorrente && a[2][0] == giocatoreCorrente) ||
            (a[0][1] == giocatoreCorrente && a[1][1] == giocatoreCorrente && a[2][1] == giocatoreCorrente) ||
            (a[0][2] == giocatoreCorrente && a[1][2] == giocatoreCorrente && a[2][2] == giocatoreCorrente) ||
            (a[0][0] == giocatoreCorrente && a[1][1] == giocatoreCorrente && a[2][2] == giocatoreCorrente) ||
            (a[0][2] == giocatoreCorrente && a[1][1] == giocatoreCorrente && a[2][0] == giocatoreCorrente)) {
            cout << "Il giocatore " << giocatoreCorrente << " ha vinto!" << endl;
            return 0;
        }
    }

    // Se dopo 9 mosse nessuno ha vinto, è pareggio
    cout << "Pareggio!" << endl;

    return 0;
}
