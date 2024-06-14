#include <iostream>
#include "array.h"

void test_sort() {
    int nTest = 1;
    
    {
        int array[] = {3, 1, 2};
        unsigned int size = 3;
        int expected[] = {1, 2, 3};
        sort(array, size);
        bool passed = true;
        for (unsigned int i = 0; i < size; ++i) {
            if (array[i] != expected[i]) {
                passed = false;
                break;
            }
        }
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {};
        unsigned int size = 0;
        sort(array, size);
        std::cout << "Test " << nTest << ": superato" << std::endl;  // Array vuoto rimane vuoto
        nTest++;
    }
    
    {
        int array[] = {5};
        unsigned int size = 1;
        int expected[] = {5};
        sort(array, size);
        bool passed = (array[0] == expected[0]);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_sort();
    return 0;
}
