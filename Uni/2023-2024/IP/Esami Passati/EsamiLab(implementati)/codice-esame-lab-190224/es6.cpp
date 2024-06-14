#include <iostream>
#include "list.h"

void deleteAllCircList(List &l, int v) {
     if (l == nullptr) {
        return; // La lista è vuota, non c'è nulla da eliminare
    }

    Cell *prev = nullptr;
    Cell *cur = l;

    while (cur->next != l) {
        Cell *temp = cur->next;
        if (cur->elem == v) {
            if (prev == nullptr) {           // Caso in testa
                if (cur->next == l) {       // Unico elemento nella lista
                    delete cur;
                    l = nullptr;
                    return;
                } else {
                    Cell *last = l;
                    while (last->next != l) {
                        last = last->next;
                    }
                    last->next = temp;
                    delete cur;
                    l = temp;
                    cur = temp;
                }
            } else {
                prev->next = temp;      // Tutti gli altri casi intermedi
                delete cur;
                cur = temp;
            }
        } else {
            prev = cur;
            cur = temp;
        }
    }

    // Controlla l'ultimo nodo della lista
    if (cur->elem == v) {
        if (prev == nullptr) {  // Caso in testa con un solo elemento
            delete cur;
            l = nullptr;
        } else {  // Caso generale
            prev->next = cur->next;
            delete cur;
        }
    }
}
