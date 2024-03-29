#include <iostream>
#include <string>
#include "circular.h"

using namespace std;

void headInsert(list &l, string s) {
      cell *aux = new cell; 
      aux -> data = s;
       
      if (l == nullptr) {
        aux -> next = aux;
        l = aux;
        return;
      }
     cell *cur = l;
     // Scorro fino alla fin
     while(cur -> next != l) {
        cur = cur -> next;
     }
     // Collego l'ultimo elemento ad aux visto che aux diventa la nuova testa
     cur -> next = aux;
     aux -> next = l;
     l = aux;
}

void insertAtTail(list &l, string s) {
    // Se la lista e vuota faccio inserimento in testa
    if (l == nullptr) {
        headInsert(l, s);
        return;
    }
    cell *aux = new cell;
    aux -> data = s;
    cell *cur = l;

    // finche il successivo di cur e diverso dalla testa scorro la lista
    while(cur -> next != l) {
        cur = cur -> next;
    }
     cur -> next = aux;      // ora il suo successivo deve puntare ad aux 
     aux -> next = l;       // ora aux e l'ultimo elemento e punta all'inizio
}

unsigned int size(const list&l) {
    if (l == nullptr) {
        return 0;
    }

    unsigned int count = 1;
    cell *aux = l;
    while (aux -> next != l) {
        ++count;
        aux = aux -> next;
    }
    return count;
}

void insertAt(list&l , string s, unsigned int pos) {
    if (pos >= size(l) || pos < 0) {
        string err = "insertAt: indice invalido";
        throw err;
    }
    if ((pos == 0 ) || (l == nullptr && pos == 0)) {
        headInsert(l, s);
        return;
    }

    if (l == nullptr) {
        string err = "insertAt: lista vuota";
        throw err;
    }

    cell *prev = nullptr;
    cell *cur = l;
    cell *aux = new cell;
    aux -> data = s;
    unsigned int count = 0;

    while (cur -> next != l && count < pos) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }

    prev -> next = aux;
    aux -> next = cur;

}

void read(list &l) {
    cout << "Inserisci valori: ";
    string s;
    do {
        cin >> s;
        if (s != "s") {
            headInsert(l, s);
        }
    }while(s != "STOP!");
}

void print(const list &l) {
    if (l == nullptr) {
        cout << "Lista vuota" << endl;
        return;
    }
    cell *aux = l;
    do {
        cout << aux->data;
        if (aux -> next != l) {
            cout << " -> ";
        }
        aux = aux->next;
    } while (aux != l);
}

void deleteAt(list &l, unsigned int pos) {
    if (l == nullptr) {
        string err = "DeleteAt: lista vuota";
        throw err;
    }

    if (pos >= size(l)) {
        string err = "DeleteAt: indice invalido";
        throw err;
    }

    if (pos == 0) {
        cell *temp = l;
        while (temp -> next != l) {
            temp = temp -> next;
        }
        temp -> next = l -> next;
        delete l;
        l = temp -> next;
        return;
    }

    cell *prev = nullptr;
    cell *cur = l;
    unsigned int count = 0;
    while(cur -> next != l && count < pos) {
        prev = cur;
        cur = cur -> next;
        ++count;
    }
    prev -> next = cur -> next;
    delete cur;
}


bool isEmpty(const list&l) {
    return l == nullptr;
}

string getElem(const list &l, unsigned int pos) {
    if (l == nullptr) {
        string err = "getElem: lista vuota";
        throw err;
    }

    if (pos >= size(l) || pos < 0) {
        string err = "indice invalido";
        throw err;
    }

    unsigned count = 0;
    cell *cur = l;
    while(cur -> next != l && count < pos) {
        cur = cur -> next;
        count++;
    }
    return cur -> data;
}

void deleteOnce(list &l, string s) {
    if (l == nullptr) {
        string err = "Lista vuota";
        throw err;
    }

    // elemento da eliminare in testa
    if (l -> data == s) {
        cell *temp = l;
        while (temp -> next != l) { 
            temp = temp -> next;
        }
        temp -> next = l -> next;   // L'ultimo elemento punta al secondo della lista che poi diventera il primo
        delete l;
        l = temp -> next;
        return;
    }

    cell *cur = l;
    cell *prev = nullptr;

    while (cur -> data != s && cur -> next != l) {
        prev = cur;
        cur = cur -> next;
    }
    if (cur -> data == s) {
        prev -> next = cur -> next;
        delete cur;
        return; 
    } else {
        string err = "Elemento non trovato";
        throw err;
    }
}

void deleteALL(list &l, const string s) {
    if (l == nullptr) {
        return; // La lista è vuota, non c'è nulla da eliminare
    }

    cell *prev = nullptr;
    cell *cur = l;

    while (cur->next != l) {
        cell *temp = cur->next;
        if (cur->data == s) {
            if (prev == nullptr) {           // Caso in testa
                if (cur->next == l) {       // Unico elemento nella lista
                    delete cur;
                    l = nullptr;
                    return;
                } else {
                    cell *last = l;
                    while (last->next != l) {
                        last = last->next;
                    }
                    last->next = temp;
                    delete cur;
                    l = temp;
                    cur = temp;
                }
            } else {
                prev->next = temp;      // Tutti gli altri casi
                delete cur;
                cur = temp;
            }
        } else {
            prev = cur;
            cur = temp;
        }
    }

    // Controlla l'ultimo nodo della lista
    if (cur->data == s) {
        if (prev == nullptr) {  // Caso in testa con un solo elemento
            delete cur;
            l = nullptr;
        } else {  // Caso generale
            prev->next = cur->next;
            delete cur;
        }
    }
}
