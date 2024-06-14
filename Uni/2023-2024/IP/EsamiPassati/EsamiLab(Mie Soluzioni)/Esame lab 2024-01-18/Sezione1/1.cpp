#include "array.h"
#include <iostream>
using namespace std;

bool arrayContainsFibonacciSeries(const int* arr, unsigned int size) {
    unsigned int F0 = 0;
    unsigned int F1 = 1;

    if (size == 0) {
        return true;
    }

    // Controllo primi due
    if (arr[0] != F0 && arr[1] != F1) {
        return false;
    }

    // se ho un solo elemento controllo il primo
    if (arr[0] != 0) {
        return false;
    }

    // controllo resto della serie
    for (unsigned int i = 2; i < size - 1; ++i) {
        if (arr[i] + arr[i - 1] != arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void reverseArray(int* arr, unsigned int size) {
    int a[size];
    for (unsigned int i = 0; i < size; ++i) {
        a[i] = arr[i];
    } 

    for (unsigned int i = 0; i < size; ++i) {
        arr[i] = a[size - 1 - i];
    } 

}
int findEquilibriumIndex(const int* arr, unsigned int size) {

    int trovato = 0;
    for (unsigned int i = 0; i < size; ++i) {
        unsigned int sommasx = 0;
        unsigned int destro = 0;

        for (unsigned int j = 0; j < i; ++j) {
            sommasx += arr[j];
        }

        for (unsigned int k = i + 1; k < size - 1; ++k) {
            destro += arr[k];
        }
        if (sommasx == destro) {
            trovato = i;
        }
}
return trovato;
}