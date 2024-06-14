#include <iostream>
#include <vector>
#include "array.h"

using namespace std;

int sommaArray(int arrayInteri[], int dimensione) {
    int sum = 0;
    for (int i = 0; i < dimensione; ++i) {
        sum += arrayInteri[i];
    }
    return sum;
}

int trovaMax(int arrayInteri[], int dimensione) {
    if (dimensione == 0) {
        return INT_MIN;
    }
    int max = arrayInteri[0];
    // parto da 1 per confrontare tutti gli elementi successivi
    for (int i = 1; i < dimensione; ++i) {
        if (arrayInteri[i] > max) {
            max = arrayInteri[i];
        }
    }
    return max;
}

std::vector<int> filtraPari(const int arrayInteri[], int dimensione) {
    vector<int> v;

    for (int i = 0; i < dimensione; ++i) {
        if (arrayInteri[i] % 2 == 0) {
            v.push_back(arrayInteri[i]);
        }
    }
    return v;
}