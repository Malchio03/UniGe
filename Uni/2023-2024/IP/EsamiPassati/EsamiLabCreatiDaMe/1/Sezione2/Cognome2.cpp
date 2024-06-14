#include <iostream>
#include <vector>
#include "list.h"

using namespace std;

unsigned int contaElementi(const List &l) {
    Cell *cur = l;
    unsigned int size = 0;

    while (cur != nullptr) {
        ++size;
        cur = cur -> next;
    }
    return size;
}

void aggiungiInTesta(List &l, Elem e) {
    Cell *aux = new Cell;
    aux -> elem = e;
    aux -> next = l;
    l = aux;
}

void eliminaElementi(List &l, Elem e) {
    Cell *cur = l;
    Cell *prev = nullptr;

    while (cur != nullptr) {
        if (cur -> elem == e) {
            // caso in testa
            if (prev == nullptr) {
                Cell *temp = cur;
                l = cur -> next;
                delete temp;
                cur = l;
            }
            // altri casi
            else {
                prev -> next = cur -> next;
                Cell *temp = cur;
                delete temp;
                cur = prev -> next;
            }
        } else {
            // se non trovo
            prev = cur;
            cur = cur -> next;
        }
    }
}