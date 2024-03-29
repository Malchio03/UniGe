#include "array.h"
#include <string> 
#include <iostream>

using namespace std;

void sort(int arrayInteri[], int dimensione) {
    // Per ordinare uso selection sort
    int index;
    for (int i = 0; i < dimensione; ++i) {
        index = i;
        for (int j = i + 1; j < dimensione; ++j) {
            if (arrayInteri[j] < arrayInteri[index]) {
                index = j;
            }
        }
        int temp = arrayInteri[i];
        arrayInteri[i] =  arrayInteri[index];
         arrayInteri[index] = temp;
    }
}
