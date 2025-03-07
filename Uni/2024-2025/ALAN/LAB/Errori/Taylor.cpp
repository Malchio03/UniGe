#include "Taylor.h"
#include <iostream>
#include <cmath>

using namespace std;

double fact(int n) {
    double factorial = 1.0;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

double taylor(double x, int N) {
    double value = 0.0; 
    for (int i = 1; i <= N; i++) {
        value += (pow(x, i) / fact(i));
    }
    return 1 + value;
}

void algoritmo_1(double x, int N) {
    double fN = taylor(x, N);
    double fx = exp(x);  
    
    double absolute_error = fabs(fN - fx); 
    double relative_error; 

    if (fx != 0) {
        relative_error = absolute_error / fabs(fx); 
    } else {
        relative_error = 0.0;  // Assegniamo 0.0 se fx è zero

        // in alternativa si potrebbe mettere un string err come abbiamo visto in ASD
    }

    cout << "x: " << x << ", N: " << N << endl;
    cout << "fN: " << fN << ", fx: " << fx << endl;
    cout << "Errore Assoluto: " << absolute_error << endl;
    cout << "Errore Relativo: " << relative_error << endl;
    cout << "----------------------------------------" << endl;
}

void algoritmo_2(double x, int N) {
    double fN = taylor(x, N);
    double reciprocal = 1.0 / fN;  // Calcola il reciproco per e^-x
    double fx = exp(-x);  
    
    double absolute_error = fabs(reciprocal - fx); 
    double relative_error; 

    if (fx != 0) {
        relative_error = absolute_error / fabs(fx); 
    } else {
        relative_error = 0.0;  // Assegniamo 0.0 se fx è zero
    }

    cout << "fN(" << x << ") = " << fN << ", f(-" << x << ") (reciproco) = " << reciprocal << endl;
    cout << "Errore Assoluto: " << absolute_error << endl;
    cout << "Errore Relativo: " << relative_error << endl;
    cout << "----------------------------------------" << endl;
}