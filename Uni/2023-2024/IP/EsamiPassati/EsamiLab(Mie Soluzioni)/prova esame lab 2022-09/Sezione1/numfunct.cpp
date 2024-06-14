#include "num.h"
#include <iostream>
using namespace std;

typedef num*list;

num * int2list(int inum){
    num* head = nullptr;
    num* cur = nullptr;

    while (inum > 0) {
        // estraggo ultima cifra
        int cifra = inum % 10;
        // riaggiorno il nmero
        inum = inum / 10;

        // Creo un nuovo nodo, e come se fosse la mia lista
        num* aux = new num;
        // punto alla cifra
        aux -> digit = cifra;
        aux -> next = nullptr;

        // caso inserimento in testa
        if (head == nullptr) {
            head = aux;
        }
        // inserimento in coda
        else {
            cur -> next = aux;
        }
        cur = aux;    // Aggiorna il puntatore al nodo precedente
    }
    return head;
}

num* sum(num* n1, num* n2) {
    num* head = nullptr;  
    num* prev = nullptr;   
    int carry = 0;         // Variabile per il riporto

    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int digit1 = 0;
        if (n1 != nullptr) {
            digit1 = n1->digit;  // Estrai la cifra corrente da n1
            n1 = n1->next;       // Passa al nodo successivo in n1
        }

        int digit2 = 0;
        if (n2 != nullptr) {
            digit2 = n2->digit;  // Estrai la cifra corrente da n2
            n2 = n2->next;       // Passa al nodo successivo in n2
        }

        int total = digit1 + digit2 + carry;  // Calcola la somma delle cifre e del riporto
        carry = total / 10;                   // Aggiorna il riporto
        int digit = total % 10;               // Calcola la cifra corrente della somma

        // Creo un nuovo nodo per la cifra corrente
        num* list = new num;
        list->digit = digit;
        list->next = nullptr;

        if (head == nullptr) {
            head = list;  
        } else {
            prev->next = list;  
        }
        prev = list;  
    }

    return head;  
}
