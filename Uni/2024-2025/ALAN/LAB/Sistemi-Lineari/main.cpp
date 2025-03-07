#include "Linear.h"
#include <iostream>
#include <vector>
#include <cmath> // Per std::abs
#include <iomanip> // Per la formattazione in output

using namespace std;

int main() {

    cout << "************************************************************************************************************************************************************************************************************\n" << endl;
    cout << "\n************************************************************************************************Esercizio 1*************************************************************************************************\n" << endl;

    vector<vector<double>> matrice1 = {
        {3, 1, -1, 0},
        {0, 7, -3, 0},  
        {0, -3, 9, -2},
        {0, 0, 4, -10}
    };
    vector<vector<double>> matrice2 = {
        {2, 4, -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}
    };

    // Stampa delle norme
    cout << "Norma infinito della prima matrice: " << normaInfinito(matrice1) << endl;
    cout << "Norma infinito della seconda matrice: " << normaInfinito(matrice2) << endl;


    // Matrice di Pascal con n = 10
    int n = 10;
    vector<vector<double>> matricePascal = generaMatricePascal(n);
/*
    cout << "\nMatrice di Pascal:" << endl;
    for (int i = 0; i < matricePascal.size(); i++) {
        for (int j = 0; j < matricePascal[i].size(); j++) {
            cout << setw(6) << matricePascal[i][j];
        }
        cout << endl;
    }
*/
    cout << "\nNorma infinito della matrice di Pascal: " << normaInfinito(matricePascal) << endl;

    // Generazione della matrice triangolare
    int d0 = 4;
    int d1 = 2;
    int n1 = 10 * (d1 + 1) + d0;
    vector<vector<double>> matriceT = generaMatriceTridiagonale(n1);
/*
    cout << "\nMatrice Triangolare: " << endl;
    for (int i = 0; i < matriceT.size(); i++) {
        for (int j = 0; j < matriceT[i].size(); j++) {
            cout << setw(6) << matriceT[i][j];
        }
        cout << endl;
    }
*/
    cout << "\nNorma infinito della matrice Triangolare: " << normaInfinito(matriceT) << endl;

    cout << "************************************************************************************************************************************************************************************************************\n" << endl;

    cout << "\n************************************************************************************************Esercizio 2*************************************************************************************************\n" << endl;

    // Calcola il termine noto b = A * x, con x = (1, 1, ..., 1)
    vector<double> b1 = generaTermineNoto(matrice1);
    vector<double> b2 = generaTermineNoto(matrice2);
    vector<double> bPascal = generaTermineNoto(matricePascal);
    vector<double> bT = generaTermineNoto(matriceT);

    // Risoluzione dei sistemi
    cout << "\nRisoluzione del sistema con matrice1:" << endl;
    eliminazioneGaussiana(matrice1, b1);

    cout << "\nRisoluzione del sistema con matrice2:" << endl;
    eliminazioneGaussiana(matrice2, b2);

    cout << "\nRisoluzione del sistema con matrice Pascal:" << endl;
    eliminazioneGaussiana(matricePascal, bPascal);

    cout << "\nRisoluzione del sistema con matrice Triangolare:" << endl;
    eliminazioneGaussiana(matriceT, bT);

    cout << "************************************************************************************************************************************************************************************************************\n" << endl;

    cout << "\n************************************************************************************************Esercizio 3*************************************************************************************************\n" << endl;

    cout << "\nRisoluzione del sistema con matrice1 (perturbato):" << endl;
    vector<double> b1_perturbato = aggiungiPerturbazione(b1);
    eliminazioneGaussiana(matrice1, b1_perturbato);

    cout << "\nRisoluzione del sistema con matrice2 (perturbato):" << endl;
    vector<double> b2_perturbato = aggiungiPerturbazione(b2);
    eliminazioneGaussiana(matrice2, b2_perturbato);

    cout << "\nRisoluzione del sistema con matrice Pascal (perturbato):" << endl;
    vector<double> bPascal_perturbato = aggiungiPerturbazione(bPascal);
    eliminazioneGaussiana(matricePascal, bPascal_perturbato);

    cout << "\nRisoluzione del sistema con matrice Triangolare (perturbato):" << endl;
    vector<double> bT_perturbato = aggiungiPerturbazione(bT);
    eliminazioneGaussiana(matriceT, bT_perturbato);

    cout << "************************************************************************************************************************************************************************************************************\n" << endl;

}
