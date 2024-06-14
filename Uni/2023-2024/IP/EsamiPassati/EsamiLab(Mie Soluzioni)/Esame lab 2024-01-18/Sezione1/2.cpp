#include "array.h"
#include <iostream>
using namespace std;

void reverseArray(int* arr, unsigned int size) {
    unsigned int temp[size];
    for (unsigned int i = 0; i < size; ++i) {
        temp[i] = arr[size - 1 - i];
    }
    for (unsigned int j = 0; j < size; ++j) {
        arr[j] = temp[j];
}
}