#include "list.h"
#include <string> 
#include <iostream>

using namespace std;

void inserimentoInTesta(List &list, City newCity) {
    Cell* aux = new Cell;
    aux -> city = newCity;
    // Caso lista vuota
    if (list == nullptr) {
        aux -> prev = nullptr;
        aux -> next = list;
        list = aux;
        return;         // esco dalla funzione
    }
    aux -> next = list;
    list -> prev = aux;
    list = aux; // questa è come dire "Ora la lista sarebbe aux essendo la testa"
}
