#include <iostream>
#include "list.h"

void test_inserimentoInTesta() {
    int nTest = 1;
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Pisa");
        bool passed = (list != nullptr && list->city == "Pisa" && list->next == nullptr && list->prev == nullptr);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
    }
    
    {
        List list = nullptr;
        inserimentoInTesta(list, "Pisa");
        inserimentoInTesta(list, "Genova");
        bool passed = (list != nullptr && list->city == "Genova" && list->next->city == "Pisa" && list->prev == nullptr);
        std::cout << "Test " << nTest << ": " << (passed ? "superato" : "fallito") << std::endl;
        nTest++;
    }
}

int main() {
    test_inserimentoInTesta();
    return 0;
}
