#include <iostream>
#include "list.h"

void test_stampaAndata() {
    int nTest = 1;
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Venezia");
        inserimentoInTesta(list, "Milano");
        inserimentoInTesta(list, "Genova");
        std::string expected = "Genova,Milano,Venezia";
        std::string result = stampaAndata(list);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        List list = nullptr;
        std::string expected = "";
        std::string result = stampaAndata(list);
        std::cout << "Test " << nTest << ": " << (result == expected ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_stampaAndata();
    return 0;
}
