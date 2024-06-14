#include "array.h"
#include <iostream>

using namespace std;

bool arrayContainsArithmeticSeries(const int* arr, unsigned int size, int difference) {
    if (size == 0) {
        return true;
    }
    for (unsigned int i = 0; i < size - 1; ++i) {
        if (arr[i] + difference != arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int findSecondLargest(const int* arr, unsigned int size) {
    if (size == 0) {
        return -1;
    }

    int max = arr[0];

    // ciclo per trovare il primo piu grande
    for (unsigned int i = 1; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    int secondo = 0;
    bool found = false;

    // Modifica del secondo ciclo for
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] < max && arr[i] > secondo) {
            secondo = arr[i];
            found = true;
        }
    }

    if (!found) {
        return -1;
    }

    return secondo;
}

int findMajorityElement(const int* arr, unsigned int size) {
    if (size == 0) {
        return -1;
    }

    // Fase 1: trovare il candidato
    int candidate = arr[0];
    int count = 1;

    for (unsigned int i = 1; i < size; ++i) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    // Fase 2: verificare se il candidato è davvero l'elemento maggioritario
    count = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1;
    }
}