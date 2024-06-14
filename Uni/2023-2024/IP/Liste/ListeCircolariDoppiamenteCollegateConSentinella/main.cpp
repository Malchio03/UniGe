#include <iostream>
#include "list.h"

int main() {
    using namespace list;
    using namespace std;

    // Creazione della lista vuota
    List myList;
    createEmpty(myList);

    // Inserimento in testa
    addFront(3, myList);
    addFront(5, myList);
    addFront(7, myList);
    add(2, 69, myList);

    // Stampa della lista
    cout << "Lista dopo l'inserimento in testa: ";
    print(myList);
    
    return 0;
}
