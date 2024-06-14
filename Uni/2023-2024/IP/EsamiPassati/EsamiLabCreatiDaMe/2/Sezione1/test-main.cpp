#include <iostream>
#include "array.h"

void test_countPrimes() {
    int nTest = 1;
    std::cout << "TEST DI test_countPrimes()" << std::endl;
    {
        int array[] = {};
        unsigned int size = 0;
        unsigned int result = countPrimes(array, size);
        std::cout << "Test " << nTest << ": " << (result == 0 ? "superato" : "fallito") << std::endl;
        nTest++;
    }

    {
        int array[] = {2, 3, 4, 5, 6, 7};
        unsigned int size = 6;
        unsigned int result = countPrimes(array, size);
        std::cout << "Test " << nTest << ": " << (result == 4 ? "superato" : "fallito") << std::endl;
        nTest++;
    }

    {
        int array[] = {1, 2, 3, 4, 5};
        unsigned int size = 5;
        unsigned int result = countPrimes(array, size);
        std::cout << "Test " << nTest << ": " << (result == 3 ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

void test_rotateArray() {
    std::cout << "TEST DI test_rotateArray()" << std::endl;
    int nTest = 1;

    {
        int array[] = {1, 2, 3};
        unsigned int size = 3;
        int positions = 1;
        int expected[] = {3, 1, 2};
        rotateArray(array, size, positions);
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
        int array[] = {1, 2, 3, 4};
        unsigned int size = 4;
        int positions = 2;
        int expected[] = {3, 4, 1, 2};
        rotateArray(array, size, positions);
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
}

void test_maxSubArraySum() {
    std::cout << "test_maxSubArraySum()" << std::endl;
    int nTest = 1;

    {
        int array[] = {};
        unsigned int size = 0;
        int result = maxSubArraySum(array, size);
        std::cout << "Test " << nTest << ": " << (result == 0 ? "superato" : "fallito") << std::endl;
        nTest++;
    }

    {
        int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        unsigned int size = 9;
        int result = maxSubArraySum(array, size);
        std::cout << "Test " << nTest << ": " << (result == 6 ? "superato" : "fallito") << std::endl;
        nTest++;
    }

    {
        int array[] = {1, 2, 3, 4};
        unsigned int size = 4;
        int result = maxSubArraySum(array, size);
        std::cout << "Test " << nTest << ": " << (result == 10 ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_countPrimes();
    test_rotateArray();
    test_maxSubArraySum();
    return 0;
}
