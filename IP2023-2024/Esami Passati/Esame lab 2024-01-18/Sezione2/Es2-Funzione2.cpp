#include "list.h"

bool insertElemInListAtIndex(List &l, Elem s, unsigned int index){
    Cell* aux = new Cell;
    aux -> elem = s;
    aux->next = nullptr;

    if (index < 0) {
        return false;
    }
    if (index > computeListSize(l)){
        return false;
    }
    // Inserimento in testa
    if (index == 0 || l == nullptr) {
        aux -> next = l;
        l = aux;
        return true;
    }

    // Tutti gli altri casi
    Cell* cur = l;
    Cell* prev = nullptr;

    unsigned int count = 0;

    while(cur != nullptr && count < index) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }
    prev -> next = aux;
    aux -> next = cur;
    return true;
    
}