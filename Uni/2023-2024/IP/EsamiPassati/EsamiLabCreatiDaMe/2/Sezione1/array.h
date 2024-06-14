#ifndef ARRAY_H
#define ARRAY_H

#include <string>

// Funzione per contare i numeri primi in un array
unsigned int countPrimes(const int* arr, unsigned int size);

// Funzione per ruotare un array di un certo numero di posizioni
void rotateArray(int* arr, unsigned int size, int positions);

// Funzione per trovare la somma massima di un sottarray contiguo
int maxSubArraySum(const int* arr, unsigned int size);

// Funzione per stampare un array in formato stringa
std::string stampa(const int* arr, unsigned int size);

// Funzione per stampare i primi k elementi di un array in formato stringa
std::string stampaKelementi(const int* arr, unsigned int size, unsigned int k);

// Funzione per ordinare un array
void sort(int* arr, unsigned int size);

#endif
