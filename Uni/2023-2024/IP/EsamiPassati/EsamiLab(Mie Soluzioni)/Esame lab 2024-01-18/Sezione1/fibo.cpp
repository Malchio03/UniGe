#include "array.h"
#include <iostream>
using namespace std;

bool arrayContainsFibonacciSeries(const int* arr, unsigned int size) {
    // F0
    unsigned int F0 = 0;

    // F1
    unsigned int F1 = 1;

    // Controllo array vuoto
    if (size == 0) {
        return true;
    }

    // controllo array con size 1 se ha come primo valore lo 0
    if (size == 1) {
        if (arr[0] == F0) {
            return true;
        } else {
            return false;
        }
    }

    // Controllo generico prima di entrare nel for principale per evitare segmentation fault
    if (arr[0] != F0 || arr[1] != F1) {
        return false;
    }

    // ora controlliamo il resto
    // parto da 2 perche ho gia controllato quelli di prima
    for (unsigned int i = 2; i < size - 1; ++i) {
        if (arr[i] + arr[i - 1] != arr[i + 1]) {
            return false;
        }
    }
    return true;
}
