#include "array.h"
#include <iostream>
using namespace std;

void reverseArray(int* arr, unsigned int size){
    unsigned int dest[size];

    // riempio dest
    for (unsigned i = 0; i < size; ++i) {
        dest[i] = arr[size - 1 - i];
    }

    // ricopio
    for (unsigned i = 0; i < size; ++i) {
        arr[i] = dest[i];
    }
}