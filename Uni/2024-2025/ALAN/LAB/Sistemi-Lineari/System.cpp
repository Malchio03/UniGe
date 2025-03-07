#include "Linear.h"
#include <iostream>
#include <vector>
#include <cmath> // Per abs
#include <iomanip> // Per la formattazione in output
#include <algorithm>   // per swap

using namespace std;

// FUNZIONI GENERICHE
double normaInfinito(const vector<vector<double>>& matrice) {
    double max_sum = 0.0;

    for (int i = 0; i < matrice.size(); i++) {
        double somma = 0.0;
        for (int j = 0; j < matrice[i].size(); j++) {
            somma += abs(matrice[i][j]);
        }
        if (somma > max_sum) {
            max_sum = somma;
        }
    }
    return max_sum;
}

// FUNZIONI ESERCIZIO 1

unsigned long long coeffBinomiale(int n, int k) {
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n){ 
        return 1;
    }
    unsigned long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

vector<vector<double>> generaMatricePascal(int n) {
    vector<vector<double>> pascal(n,vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pascal[i][j] = coeffBinomiale(i + j, i);
        }
    }
    return pascal;
}

vector<vector<double>> generaMatriceTridiagonale(int size) {
    vector<vector<double>> T(size, vector<double>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (i == j){
                T[i][j] = 2;
            }
            else if (abs(i - j) == 1){
                    T[i][j] = -1;
            }
            else{
                T[i][j] = 0;
            }
        }
    return T;
}

// FUNZIONI ESERCIZIO 2

vector<double> generaTermineNoto(const vector<vector<double>>& A) {
    int n = A.size();
    vector<double> b(n, 0.0f);
    
    // Calcola b come la somma delle righe della matrice A (A * x, con x = (1,1,...,1))
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i] += A[i][j];  
        }
    }
    return b;
}

// Funzione di eliminazione gaussiana con pivoting parziale
bool eliminazioneGaussiana(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    
    for (int k = 0; k < n; k++) {
        // Pivoting parziale: cerca il massimo elemento nella colonna k
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(A[i][k]) > abs(A[maxRow][k])) {
                maxRow = i;
            }
        }
        
        // Scambia la riga k con la riga maxRow
        swap(A[k], A[maxRow]);
        swap(b[k], b[maxRow]);
        
        // Elimina la colonna sotto A[k][k]
        for (int i = k + 1; i < n; i++) {
            float factor = A[i][k] / A[k][k];
            for (int j = k; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }
    
    // Sostituzione all'indietro
    vector<double> x(n, 0.0f);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(4) << x[i] << " ";
    }
    cout << endl;
    
    return true;
}

// FUNZIONI ESERCIZIO 3

double normaInfinitoVettore(const vector<double>& b) {
    double max_sum = 0.0;
    for (double val : b) {
        max_sum = max(max_sum, abs(val));
    }
    return max_sum;
}


// Funzione per aggiungere la perturbazione al termine noto b
vector<double> aggiungiPerturbazione(const vector<double>& b) {
    double norma_b = normaInfinitoVettore(b);
    vector<double> delta_b(b.size(), 0.01 * norma_b);
    
    // Aggiungere la perturbazione, alternando segno
    for (size_t i = 0; i < delta_b.size(); i++) {
        if (i % 2 == 0) {
            delta_b[i] = -delta_b[i];
        }
    }
    
    // Sommare la perturbazione al termine noto
    vector<double> b_perturbato(b.size());
    for (size_t i = 0; i < b.size(); i++) {
        b_perturbato[i] = b[i] + delta_b[i];
    }
    
    return b_perturbato;
}