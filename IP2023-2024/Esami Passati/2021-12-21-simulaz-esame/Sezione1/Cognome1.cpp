#include <iostream>
#include <string>
#include <sstream>
#include "plist.h"

using namespace std;

void PList_insert(PList &L, int val) {
    Elem *cur = L;
    if (L != nullptr) {
        while (cur -> next != nullptr) {
            // Se il valore è già presente, esci dalla funzione
            if (cur -> cont == val) {
                return ;
            }
            cur = cur -> next;
        }
    }
    Elem *aux  = new Elem;
    aux -> cont = val;
    aux -> next = L;
    L = aux;

    // Alloco di nuovo aux
    aux = new Elem;
    aux -> cont = val;
    aux -> next = nullptr;
    if (cur == nullptr) {
        cur = L;
    }
    cur -> next = aux;
}

void PList_delete(PList &L, int val) {
    Elem *cur = L;
    Elem *prev = nullptr;
    if (L == nullptr) {
        string err = "Lista vuota";
        throw err;
    }

   while (cur!= nullptr) {
        Elem* next = cur -> next;
        if (cur -> cont == val) {
            // caso in testa
            if (prev == nullptr) {
                L = next;
                delete cur;
                cur = L;
            } else {
                prev -> next = next;
                delete cur;
                cur = next;
            }
        } else {
            prev = cur;
            cur = next;
        }
    }
}