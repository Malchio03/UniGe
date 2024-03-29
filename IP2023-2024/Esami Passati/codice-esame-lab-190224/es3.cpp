#include "array.h"
#include <iostream>


dyn_array indexOfInArray(int v, const int* arr, unsigned int dim) {
    dyn_array ret;
    ret.D = 0;
    ret.A = nullptr;
    
    // Controlla se l'array è vuoto
    if (dim == 0) {
        return ret;
    }
    
    // Cerca gli indici in cui si trova il valore v
    unsigned int count = 0;
    for (unsigned int i = 0; i < dim; ++i) {
        if (arr[i] == v) {
            ++count;
        }
    }
    
    // Se non ci sono occorrenze di v nell'array, restituisci ret
    if (count == 0) {
        return ret;
    }
    
    // Alloca un nuovo array dinamico per memorizzare gli indici
    ret.D = count;
    ret.A = new unsigned int[count];
    
    // Riempie l'array con gli indici in cui si trova v
    unsigned int index = 0;
    for (unsigned int i = 0; i < dim; ++i) {
        if (arr[i] == v) {
            ret.A[index++] = i;
        }
    }
    return ret;
}
