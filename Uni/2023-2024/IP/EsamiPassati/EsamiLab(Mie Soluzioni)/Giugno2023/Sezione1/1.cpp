#include "array.h"
#include <iostream>
#include <string>



void sort(int arrayInteri[], int dimensione) {
    std::string out = "";
    int index;
    for (int i = 0; i < dimensione - 1; ++i) {
        index = i; 
        for (int j = i + 1; j < dimensione; ++j) {
            if (arrayInteri[j] < arrayInteri[index]) {
                index = j;
            }
        }
        int temp = arrayInteri[i];
        arrayInteri[i] = arrayInteri[index];
        arrayInteri[index] = temp;
    }
}