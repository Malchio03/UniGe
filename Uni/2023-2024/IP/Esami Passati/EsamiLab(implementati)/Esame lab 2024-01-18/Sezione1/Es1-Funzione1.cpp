#include "array.h"
#include <iostream>

bool arrayContainsFibonacciSeries(const int* arr, unsigned int size) {
    // Caso array vuoto
    if (size == 0) {
        return true;
    }

    // Caso f0 = 0 ovviamente nel caso di un elemento
    if ((arr[0] == 0 && size == 1)) {
        return true;
    }

    // Controllo se le prime due celle corrispondono a 0 e a 1
    if (arr[0] != 0 && size >= 1) {
        return false;
    }
    if (arr[1] != 1 && size > 1) {
        return false;
    }

    // Tutti gli altri casi
    for (unsigned int i = 2; i < size - 1; ++i) {
        if ((arr[i] + (arr[i - 1])) != arr[i + 1]) {        // Controllo se l'elemento corrente sommato a quello precedenete mi da il risultato del successivo 
            return false;
        }
    }
    return true;
}
