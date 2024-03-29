#include "array.h"
#include <iostream>

//                   source
//                     ||
void reverseArray(int* arr, unsigned int size)
{
    // Creo nuovo array che mi servira per copiare gli elementi di source (array originale) 
    int dest[size];

    // copio gli elementi al contrario
    for(unsigned int i = 0; i < size; ++i) {
        dest[i] = arr[size - i - 1];
    }

    // ricopio nell'array originale
    for(unsigned int i = 0; i < size; ++i) {
        arr[i] = dest[i];
    }
}
