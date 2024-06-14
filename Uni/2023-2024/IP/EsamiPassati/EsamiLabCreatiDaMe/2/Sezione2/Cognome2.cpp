#include <iostream>
#include "list.h"
using namespace std;


// Funzione per calcolare la lunghezza di una lista
unsigned int computeListSize(const List &l) {
    Cell *cur = l;
    unsigned int i = 0;

    while (cur != nullptr) {
        ++i;
        cur = cur -> next;
    }
    return i;
}

bool insertElemInListAtIndex(List &l, Elem s, unsigned int index) {
    Cell *aux = new Cell;
    aux -> elem = s;
    // caso in testa
    if (index == 0) {
        if (l == nullptr) {
            l = aux;
            return true;
        }
        aux -> next = l;
        l = aux;
        return true;
    }

    Cell *cur = l;
    Cell *prev = nullptr;

    unsigned int pos = 0;

    while (cur != nullptr && pos < index) {
        prev = cur;
        cur = cur -> next;
        ++pos;
    }
    
    if (pos == index) {
        prev -> next = aux;
        aux -> next = cur;
        return true;
    } else {
        return false;
    }
}

void deleteLastInstanceOfElemInList(List &l, Elem s) {
    Cell *cur = l;
    Cell *prev = nullptr;

    Cell *last = nullptr;
    Cell *PrevLast = nullptr;

    while (cur != nullptr) {
        if (cur -> elem == s) {
            last = cur;
            PrevLast = prev;
        } 
        prev = cur;
        cur = cur -> next;
    }

    if (last == nullptr) {
        // non lo trovo
        return;
    }

    if (last == l) {
        l = l -> next;
    } else {
        PrevLast -> next = last -> next;
    }
    delete last;
}