#include <iostream>
#include "list.h"

void test_stampaAdiacenti() {
    int nTest = 1;
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Venezia");
        inserimentoInTesta(list, "Milano");
        inserimentoInTesta(list, "Genova");
        std::string expected = "Genova,Milano,Venezia";
        std::string result = stampaAdiacenti(list, "Milano");
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Venezia");
        inserimentoInTesta(list, "Milano");
        inserimentoInTesta(list, "Genova");
        std::string expected = "-,Genova,Milano";
        std::string result = stampaAdiacenti(list, "Genova");
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Venezia");
        inserimentoInTesta(list, "Milano");
        inserimentoInTesta(list, "Genova");
        std::string expected = "Milano,Venezia,-";
        std::string result = stampaAdiacenti(list, "Venezia");
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Venezia");
        inserimentoInTesta(list, "Milano");
        inserimentoInTesta(list, "Genova");
        std::string expected = "-,-,-";
        std::string result = stampaAdiacenti(list, "Roma");
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_stampaAdiacenti();
    return 0;
}
