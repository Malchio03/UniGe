#include "list.h"

void deleteLastInstanceOfElemInList(List &l, Elem s) {
    if (l == nullptr) {
        return; // Lista vuota, niente da fare
    }

    Cell* prev = nullptr;
    Cell* current = l;
    Cell* lastInstance = nullptr;
    Cell* prevLastInstance = nullptr;

    // Trova l'ultima istanza dell'elemento e il suo predecessore
    while (current != nullptr) {
        if (current->elem == s) {
            prevLastInstance = prev;
            lastInstance = current;
        }
        prev = current;
        current = current->next;
    }

    // Se non è stata trovata l'ultima istanza, non c'è nulla da eliminare
    if (lastInstance == nullptr) {
        return;
    }

    // Elimina l'ultima istanza
    if (lastInstance == l) {
        l = l->next;
    } else {
        // nelle semplici sarebbe prev -> next = cur -> next
        prevLastInstance->next = lastInstance->next;
    }
    delete lastInstance;
}


/*void deleteLastInstanceOfElemInList(List &l, Elem s) {

    if (l == nullptr) {
        return;
    }
    // Contatore per la lista
    unsigned int i = 0;
    // Contatore per le istanze
    unsigned int found = 0;

    Cell* cur = l;
    while(cur != nullptr) {
        if (cur -> elem == s) {
            // Memorizzo la posizione
            found = i;
        }
        ++i;
        cur = cur -> next;
    }

    // Caso in cui l'elemento si trovi in testa
    if (found == 0) {
        Cell* temp = l -> next;
        delete cur;
        l = temp;
    } else  if (found > 0){
        Cell* scorro = l;
        Cell* prima = nullptr;
        unsigned int pos = 0;
        while(scorro != nullptr && pos < found) {
            prima = scorro;
            scorro = scorro -> next;
        }
        prima -> next = scorro -> next;
        delete scorro;
    } else {
        return; 
    }
}
*/