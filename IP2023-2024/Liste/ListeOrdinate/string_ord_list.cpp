#include "string_ord_list.h"
#include <iostream>
#include <string>

using namespace std;

// inserisce un elemento contenente s nella lista ordinata l mantenendo la lista ordinata
void insertElement(ordList &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    cell *cur = l;
    cell *prev = nullptr;

    while (cur != nullptr && cur -> data <= s) {
        prev = cur;
        cur = cur -> next;
    }

    if (l == nullptr || l -> data > s) {
        aux -> next = l;
        l = aux;
    } else {
        prev -> next = aux;
        aux -> next = cur;
    }
}

// legge valori da input e li memorizza (aggiunge) nella lista ordinata l
void readList(ordList &l) {
    string choice;
    do {
        cout << "Inserisci valore:";
        cin >> choice;

        if (choice != "STOP!") {
            insertElement(l, choice);
        }
    } while(choice != "STOP!");
}

// Stampa
void printList(const ordList &l) {
    cell *aux = l;
    while (aux  != nullptr) {
        cout << aux -> data;
        if (aux -> next != nullptr) {
            cout << " -> ";
        }
        aux = aux -> next;
    }
}

unsigned int listSize(const ordList &l) {
    unsigned int j = 0;
    cell *aux = l;
    while (aux != nullptr) {
        aux = aux -> next;
        j++;
    }
    return j;
}

bool isEmptyList(const ordList &l) {
    return l == nullptr;
}

string getElement(const ordList &l, unsigned int i) {

    if (l == nullptr) {
        string err = "getElem: Errore, lista vuota";
        throw err;
    }
    unsigned int j = 0;
    cell *aux = l;
    while (aux != nullptr && j < i) {
        aux = aux -> next;
        j++;
    }
    if (j == i && aux != nullptr) {
        return aux -> data;
    } else {
        string err = "getElem: indice invalido";
        throw err;
    }
}

void deleteElementAt(ordList &l, unsigned int i) {

    unsigned int j = 0;
    cell *cur = l;
    cell *prev = nullptr;

    if (l == nullptr) {
        string err = "deleteAt: Errore, lista vuota";
        throw err;
    }
    // Caso in cui l'elemento si trovi in testa
    if (i == 0) {
        l = l -> next;
        delete cur;
        return;
    }

    while (cur -> next != nullptr && j < i) {
        prev = cur;
        cur = cur -> next;
        j++;
    }
    if (j == i) {
        prev -> next = cur -> next;
        delete cur;
    } else {
        string err = "deleteAt: indice invalido";
        throw err;
    }
}

void deleteElementOnce(ordList &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;

    if (l == nullptr) {
        string err = "deleteOnce: Errore, lista vuota";
        throw err;
    }

    if (l -> data == s) {
        l = l -> next;
        delete cur;
        return;
    }

    while (cur -> next != nullptr && cur -> data != s) {
        prev = cur;
        cur = cur -> next;
    }

    if (cur -> data == s) {
        prev -> next = cur -> next;
        delete cur;
    } else {
        cout << "Elemento non trovato" << endl;
    }
}

void deleteAllElements(ordList &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;

    while (cur != nullptr && cur->data <= s) {
        if (cur->data == s) { // Se troviamo un elemento da eliminare
            if (prev == nullptr) { // Se l'elemento da eliminare è il primo
                l = cur->next;
                delete cur;
                cur = l;
            } else { // Se l'elemento da eliminare è in mezzo o in fondo alla lista
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        } else { 
            prev = cur;
            cur = cur->next;
        }
    }
}

bool listAreEqual(const ordList &l1, const ordList &l2) {
    const cell *cur1 = l1;
    const cell *cur2 = l2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->data != cur2->data) { // Se le stringhe non corrispondono
            return false;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return true;
}

ordList concatLists(const ordList &l1, const ordList &l2) {
    ordList concatenated = nullptr;

    // Copia gli elementi della prima lista nella lista concatenata
    cell *cur = l1;
    while (cur != nullptr) {
        insertElement(concatenated, cur->data);
        cur = cur->next;
    }

    // Aggiunge gli elementi della seconda lista alla fine della lista concatenata
    cell *cur2 = l2;
    while (cur2 != nullptr) {
        insertElement(concatenated, cur2->data);
        cur2 = cur2->next;
    }
    return concatenated;
}


// Funzione ausiliaria per unionList, mi serve per trovare un possibile duplicato
bool findElement(const ordList &lista, string elemento) {
    cell *cur = lista;

    while (cur != nullptr) {
        if (cur -> data == elemento) {
            return true;
        }
        cur = cur -> next;
    }
    return false;
}

ordList unionLists(const ordList &l1, const ordList &l2) {
    ordList NewLista = nullptr;

    // Copia gli elementi della prima lista nella lista concatenata
    cell *cur = l1;
    while (cur != nullptr) {
        if (!findElement(NewLista, cur->data)) {
            insertElement(NewLista, cur->data);
        }
        cur = cur->next;
    }

    // Aggiunge gli elementi della seconda lista alla fine della lista concatenata
    cur = l2;
    while (cur != nullptr) {
        if (!findElement(NewLista, cur->data)) {
            insertElement(NewLista, cur->data);
        }
        cur = cur->next;
    }

    return NewLista;
}


ordList intersectLists(const ordList &l1, const ordList &l2) {
    ordList NewLista = nullptr;
    cell *cur1 = l1;
    cell *cur2 = l2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1 -> data == cur2 -> data) {
            insertElement(NewLista, cur1->data);
        }
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return NewLista;
}



