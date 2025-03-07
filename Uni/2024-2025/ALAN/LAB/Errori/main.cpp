#include "Taylor.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int valori_N[] = {3, 10, 50, 100, 150};
    double punto_x[] = {0.5, 30, -0.5, -30};

    cout << endl;
   // cout << "----------------------------------------" << endl;
    cout << "Algoritmo 1:\n";
    //cout << "----------------------------------------" << endl;
    cout << endl;

    // i minore di 4 visto che abbiamo solo 4 x da tener conto
    for (int i = 0; i < 4; ++i) { 
        double x = punto_x[i];
        for (int j = 0; j < 5; ++j) { 
            int N = valori_N[j];
            algoritmo_1(x, N);
        }
    }

    cout << endl;
   // cout << "----------------------------------------" << endl;
    cout << "Algoritmo 2:\n";
   // cout << "----------------------------------------" << endl;
    cout << endl;

    double punti_x[] = {0.5, 30};
    for (int i = 0; i < 2; ++i) { 
        double x = punti_x[i];
        for (int j = 0; j < 5; ++j) { 
            int N = valori_N[j];
            algoritmo_2(x,N);
        }
    }
}