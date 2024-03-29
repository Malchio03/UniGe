#include "array.h"
#include <iostream>

int findEquilibriumIndex(const int* arr, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        int sinistra = 0;
        int destra = 0;
        
        // Somma gli elementi precedenti
        for (unsigned int j = 0; j < i; ++j) {
            sinistra += arr[j];
        }
        
        // Somma gli elementi successivi
        for (unsigned int k = i + 1; k < size; ++k) {
            destra += arr[k];
        }

        if (sinistra == destra) {
            return i;
        }
    }
    return -1;







    
   /* unsigned int sinistra = 0;
    unsigned int destra = 0;
    bool found = false;
    unsigned int equilibrio = 0;
    // Ciclo principale che mi seleziona l'elemento
    for (unsigned int i = 0; i < size; ++i) {
        // Ciclo che mi somma gli elementi precedenti
        for (unsigned int j = i - 1; j >= 0; --j) {
            sinistra += arr[j];
        }
        // Ciclo che mi somma gli elementi successivi
        for (unsigned int k = i  + 1; k < size; ++k) {
            destra += arr[k];
        }

        if (sinistra == destra) {
            found = true;
            equilibrio = i;
            break;
        }
    }
    if (found) {
        return equilibrio;
    } else {
        return - 1;
    }*/
}
