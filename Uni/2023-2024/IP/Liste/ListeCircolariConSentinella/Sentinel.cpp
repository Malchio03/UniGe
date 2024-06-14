#include "double.h"
#include <iostream>
#include <string>

using namespace std;

void createEmpty(list &l) {
    cell* aux = new cell;
    aux -> next = aux;
    l = aux;
}

void headInsert(list &l, string s) {
    cell* aux = new cell;
    aux -> data = s;
    aux -> next = l -> next;
    l -> next = aux;
}

void tailInsert(list &l, string s) {
    cell* cur = l -> next;

    while (cur -> next != l) {
        cur = cur -> next;
    }
    cell* aux = new cell;
    aux -> data = s;
    cur -> next = aux;
    aux -> next = l;
}

void print(const list& l) {
    cell* cur = l -> next;
    while (cur != l) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
}

unsigned int size(const list &l) {
    cell* cur = l -> next;
    unsigned int i = 0;
    while (cur != l) {
        ++i;
        cur = cur -> next;
    }
    return i;
}

bool isEmpty(const list &l) {
    return l -> next == l;
}

string getElem(const list &l, unsigned int i) {
    // Caso lista vuota
    if (isEmpty(l)) {
        string err = "Lista vuota";
        throw err;
    }

    // Caso indice invalido
    if (i >= size(l) || i < 0) {
        string err =  "Indice invalido";
        throw err;
    }

    if (i == 0) {
        return l -> next -> data;
    }

    cell* cur = l -> next;
    unsigned int count = 0;
    while (cur != l && count < i) {
        cur = cur -> next;
        ++count;
    }
    return cur -> data;
}

void insertAt(list &l, string s, unsigned int i) {
    // Caso lista vuota
    if (isEmpty(l)) {
        string err = "Lista vuota";
        throw err;
    }

    // Caso indice invalido
    if (i > size(l) || i < 0) {
        string err =  "Indice invalido";
        throw err;
    }

    cell* aux = new cell;
    aux -> data = s;

    // Inserisco in testa
    if (i == 0) {
        aux -> next = l -> next;
        l -> next = aux;
        return;
    }

    cell* cur = l -> next;
    cell* prev = nullptr;
    unsigned int count = 0;

    while (cur != l && count < i) {
        ++count;
        prev = cur;
        cur = cur -> next;
    }
        prev -> next = aux;
        aux -> next = cur;
}

void deleteAt(list &l, unsigned int i) {
    // Caso lista vuota
    if (isEmpty(l)) {
        string err = "Lista vuota";
        throw err;
    }

    // Caso indice invalido
    if (i >= size(l) || i < 0) {
        string err =  "Indice invalido";
        throw err;
    }

    // Caso elimino in testa
    if (i == 0) {
        cell* temp = l -> next;
        l -> next = temp -> next;
        delete temp;
        return;
    }

    cell* cur = l -> next;
    cell* prev = nullptr;
    unsigned int count = 0;

    while (cur != l && count < i) {
        ++count;
        prev = cur;
        cur = cur -> next;
    }
    prev -> next = cur -> next;
    delete cur;
}

void deleteOnce(list &l, string s) {
    // Caso lista vuota
    if (isEmpty(l)) {
        string err = "Lista vuota";
        throw err;
    }

    // Caso elimino in testa
    if (l -> next -> data == s) {
        cell* temp = l -> next;
        l -> next = temp -> next;
        delete temp;
        return;
    }

    cell* cur = l -> next;
    cell* prev = nullptr;

    while(cur != l && cur -> data != s) {
        prev = cur;
        cur = cur -> next;
    }
    if (cur -> data == s){
        prev -> next = cur -> next;
        delete cur;
    } else {
        string err = "Lista vuota";
        throw err;
    }
}

void deleteALL(list &l, string s) {
    // Caso lista vuota
    if (isEmpty(l)) {
        string err = "Lista vuota";
        throw err;
    }

    cell* cur = l -> next;
    cell* prev = nullptr;

    while(cur != l) {
        if (cur -> data == s) {
            // Caso inserimento in testa
            if (l -> next -> data == s) {
                cell* temp = l -> next;
                l -> next = temp -> next;
                delete temp;
                cur = l -> next;
                } else {
                prev -> next = cur -> next;
                delete cur;
                cur = prev -> next;
            }
        } else {
            prev = cur;
            cur = cur -> next;
        }
    }
}