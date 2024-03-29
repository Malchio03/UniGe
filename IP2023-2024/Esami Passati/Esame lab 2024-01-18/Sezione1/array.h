#ifndef ARRAY
#define ARRAY

#include <stdbool.h> // Include necessary header for bool data type
#include<iostream>
#include <string>

// Function declarations
bool arrayContainsFibonacciSeries(const int* arr, unsigned int size);
void reverseArray(int* arr, unsigned int size);
int findEquilibriumIndex(const int* arr, unsigned int size);

// Additional function declarations
int* mergeSortedArrays(const int* arr1, unsigned int size1, const int* arr2, unsigned int size2);
void removeDuplicates(int* arr, unsigned int* size);
void printArray(const int* arr, unsigned int size);
bool testResult(std::string s1, std::string s2);
#endif
