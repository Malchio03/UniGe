#include <iostream>
#include "array.h"

// Funzione ausiliare
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned int countPrimes(const int* arr, unsigned int size) {
    if (size == 0) {
        return 0;
    }

    unsigned int count = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) {
            ++count;
        }
    }
    return count;
    
}

void rotateArray(int* arr, unsigned int size, int positions) {
    if (size == 0) return;

    // Normalizzare il numero di posizioni
    positions = positions % size;
    if (positions < 0) {
        positions += size; // Convertire le rotazioni a sinistra in rotazioni a destra
    }

    // Creare un array temporaneo per memorizzare il risultato
    int* temp = new int[size];

    // Copiare gli elementi ruotati nell'array temporaneo
    for (unsigned int i = 0; i < size; ++i) {
        temp[(i + positions) % size] = arr[i];
    }

    // Copiare gli elementi dall'array temporaneo all'array originale
    for (unsigned int i = 0; i < size; ++i) {
        arr[i] = temp[i];
    }

    // Deallocare la memoria dell'array temporaneo
    delete[] temp;
}


int maxSubArraySum(const int* arr, unsigned int size) {
    if (size == 0) return 0;

    int max_sum = arr[0];
    int current_sum = arr[0];

    for (unsigned int i = 1; i < size; ++i) {
        // Confrontare manualmente e aggiornare current_sum
        if (current_sum + arr[i] > arr[i]) {
            current_sum = current_sum + arr[i];
        } else {
            current_sum = arr[i];
        }

        // Confrontare manualmente e aggiornare max_sum
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

