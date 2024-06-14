#include "array.h"
#include <iostream>
#include <string>

int main() {
    int array1[] = {77, 56, 104};
    std::cout << "k = 0: " << stampaKelementi(array1, 3, 0) << std::endl;

    int array2[] = {77, 56, 104};
    std::cout << "k = 1: " << stampaKelementi(array2, 3, 1) << std::endl;

    int array3[] = {77, 56, 104};
    std::cout << "k = 2: " << stampaKelementi(array3, 3, 2) << std::endl;

    int array4[] = {77, 56, 104};
    std::cout << "k = 3: " << stampaKelementi(array4, 3, 3) << std::endl;

    int array5[] = {77, 56, 104};
    std::cout << "k = 3: " << stampaKelementi(array5, 3, 4) << std::endl;
}