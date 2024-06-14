#include <iostream>
#include "array.h"

void test_stampaKelementi() {
    int nTest = 1;
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        int k = 0;
        std::string expected = "";
        std::string result = stampaKelementi(array, size, k);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        int k = 1;
        std::string expected = "77";
        std::string result = stampaKelementi(array, size, k);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        int k = 2;
        std::string expected = "77,56";
        std::string result = stampaKelementi(array, size, k);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        int k = 3;
        std::string expected = "77,56,104";
        std::string result = stampaKelementi(array, size, k);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        int array[] = {77, 56, 104};
        unsigned int size = 3;
        int k = 4;
        std::string expected = "77,56,104";
        std::string result = stampaKelementi(array, size, k);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_stampaKelementi();
    return 0;
}
