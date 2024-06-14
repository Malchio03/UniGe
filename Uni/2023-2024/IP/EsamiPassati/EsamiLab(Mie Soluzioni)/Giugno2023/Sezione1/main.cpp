#include <iostream>
#include "array.h"

void test_stampa() {
    int nTest = 1;
    
    {
        int array[] = {};
        unsigned int size = 0;
        std::string expected = "";
        std::string result = stampa(array, size);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77};
        unsigned int size = 1;
        std::string expected = "77";
        std::string result = stampa(array, size);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56};
        unsigned int size = 2;
        std::string expected = "77,56";
        std::string result = stampa(array, size);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        std::string expected = "77,56,104";
        std::string result = stampa(array, size);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_stampa();
    return 0;
}
