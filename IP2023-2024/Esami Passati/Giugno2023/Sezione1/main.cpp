#include "array.h"
#include <iostream>
#include <string>

int main() {
    int array1[] = {};
    std::cout << "Array vuoto: " << stampa(array1, 0) << std::endl;

    int array2[] = {77};
    std::cout << "Array con un elemento: " << stampa(array2, 1) << std::endl;

    int array3[] = {77, 56};
    std::cout << "Array con due elementi: " << stampa(array3, 2) << std::endl;

    int array4[] = {77, 56, 104};
    std::cout << "Array con tre elementi: " << stampa(array4, 3) << std::endl;
}