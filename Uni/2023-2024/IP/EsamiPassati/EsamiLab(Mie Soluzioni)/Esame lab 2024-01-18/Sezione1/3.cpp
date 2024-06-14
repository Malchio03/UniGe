#include "array.h"
#include <iostream>
using namespace std;

int findEquilibriumIndex(const int* arr, unsigned int size) {
    // ciclo principale
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int sinistra = 0;
        unsigned int destra = 0;
        
        // sommo elementi a sinistra
        for(unsigned int j = 0; j < i; ++j) {
            sinistra += arr[j];
        }

        // sommo elementi a destra
        for(unsigned int k = i + 1; k < size; ++k) {
            destra += arr[k];
        }

        // controllo se ho l'indice
        if (sinistra == destra) {
            return i;
        }
    }
    return - 1;
}