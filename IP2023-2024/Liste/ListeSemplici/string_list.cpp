#include "string_list.h"
#include <iostream>
#include <string>

using namespace std;

// Inserimento in testa
void headInsert(list &l, string s) {
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = l;
    l = aux;
}

// Inserimento in coda
void tailInsert(list &l, string s) {
    cell *aux = new cell;
    cell *cur = l;
    aux -> data = s;
    aux -> next = nullptr;

    if (l == nullptr) {
        headInsert(l, s);
        return;
    }

    while (cur -> next != nullptr) {
        cur = cur -> next;
    }

    cur -> next = aux;
}

// legge valori da input e li memorizza nella lista l
// l'inserimento termina se l'utente inserisce "STOP!"
void read(list &l) {
    cout << "Inserisci valore: (scrivere STOP! per terminare l'inserimento)";
    string s;
    do {
        cin >> s;
        if (s != "STOP!") {
            headInsert(l, s);
        }
    } while (s != "STOP!");
    }

// Stampa
void print(const list &l) {
    cell *aux = l;
    while (aux  != nullptr) {
        cout << aux -> data;
        if (aux -> next != nullptr) {
            cout << " -> ";
        }
        aux = aux -> next;
    }
}

// Size della lista
unsigned int size(const list &l) {
    unsigned int count = 0;
    cell *aux = l;
    while (aux != nullptr) {
        count++;
        aux = aux -> next;
    }
    return count;
}

// Verificare se la lista contiene elementi
bool isEmpty(const list &l) {
    return l == nullptr;
}

// Ritorna il contenuto dell'i-esimo elemento della lista l
string getElem(const list &l, unsigned int i) {

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

// Inserisco elemento alla posizione i
void insertAt(list &l, string s, unsigned int i) {
    unsigned int j = 0;
    cell *aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    cell *cur = l;
    cell *prev = nullptr;

    if (l == nullptr) {
        string err = "insertAt: Errore, lista vuota";
        throw err;
    }

    // Elemento da inserire è il primo
    if (i == 0) {
        aux -> next = l;
        l = aux;
        return;
    }

    while (cur -> next != nullptr && j < i) {
        prev = cur;
        cur = cur -> next;
        j++;
    }

    if (j == i && aux != nullptr) {
        prev -> next = aux;
        aux -> next = cur;      // metto = cur se voglio slittare tutti gli elementi verso destra
        // Nel caso volessi sostuire senza aumentare la size della lista devo usare:
        // aux -> next = cur -> next
    } else {
        string err = "InsertAt: indice invalido";
        throw err;
    }
}

// Elimino elemento alla posizione i
void deleteAt(list &l, unsigned int i) {
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

// Elimina il primo elemento s dalla lista
void deleteOnce(list &l, string s) {
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

// Elimina TUTTI gli elementi s dalla lista
void deleteAll(list &l, string s) {
    cell *cur = l;
    cell *prev = nullptr;

    if (l == nullptr) {
        string err = "deleteAll: Errore, lista vuota";
        throw err;
    }

    while (cur != nullptr) {
        if (cur->data == s) {
            if (prev == nullptr) {  // Caso elemtno si trova in testa
                l = cur->next;      
                delete cur;
                cur = l;           
            } else {                // Tutti gli altri casi
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

