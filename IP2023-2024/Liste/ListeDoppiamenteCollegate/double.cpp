#include "double.h"
#include <iostream>
#include <string>

using namespace std;

void headInsert(list &l, string s) {
    cell* aux = new cell;
    aux -> data = s;
    aux -> prev = nullptr;
    aux -> next = nullptr;

    // Caso lista vuota
    if (l == nullptr) {
        l = aux;
        return;
    }

    l -> prev = aux;
    aux -> next = l;
    l = aux;
}

void tailInsert(list &l, string s) {
    cell* aux = new cell;
    aux -> data = s;
    aux -> next = nullptr;

    if (l == nullptr) {
        aux -> prev = nullptr;
        l = aux;
        return;
    }

    cell* cur = l;
    while(cur -> next != nullptr) {
        cur = cur -> next;
    }

    aux -> prev = cur;
    cur -> next = aux;
}

void print(const list &l) {
    cell* aux = l;
    while(aux != nullptr) {
        cout << aux -> data;
        if (aux -> next != nullptr) {
            cout << " -> ";
        }
        aux = aux -> next;
    }
}

unsigned int size(const list &l) {

    if (l == nullptr) {
        return 0;
    }
    unsigned int i = 0;
    cell* aux = l;
    while(aux != 0) {
        ++i;
        aux = aux -> next;
    }
    return i;
}

bool isEmpty(const list &l) {
    return l == nullptr;
}

string getElem(const list &l, unsigned int i) {
    if (l == nullptr) {
        string err = "getElem: lista vuota";
        throw err;
    }

    if (i >=size(l) || i < 0) {
        string err = "getElem: indice invalido";
        throw err;
    }

    unsigned int count = 0;
    cell* cur = l;
    while (cur != nullptr && count < i) {
        ++count;
        cur = cur -> next;
    }

    return cur -> data;
}

void insertAt(list &l, string s, unsigned int i) {
     if (l == nullptr) {
        string err = "insertAt: lista vuota";
        throw err;
    }

    if (i >=size(l) || i < 0) {
        string err = "insertAt: indice invalido";
        throw err;
    }

    cell* aux = new cell;
    aux -> data = s;
    aux -> prev = nullptr;
    aux -> next = nullptr;
    cell* cur = l;

    if (i == 0) {
        aux -> next = l;
        if (l != nullptr) {
            l -> prev = aux;
        }
        l = aux;
        return;
    }

    unsigned int count = 0;
    while (cur != nullptr && count < i) {
        ++count;
        cur = cur -> next;
    }

    aux -> next = cur;
    aux -> prev = cur -> prev;
    cur -> prev -> next = aux;
    cur -> prev = aux;
}

void deleteOnce(list &l, string s) {
    cell* cur = l;

    while (cur != nullptr && cur -> data != s) {
        cur = cur -> next;
    }

    if ( cur != nullptr && cur -> data == s) {
        if (cur -> prev == nullptr) {
            l = cur -> next;
            delete cur;
        } else {
            cur -> prev -> next= cur -> next;
            delete cur;
        }
    } else {
        string err = "deleteOnce: elemento non trovato";
        throw err;
    }
}

void deleteALL(list &l, string s) {
    cell* cur = l;
    while (cur != nullptr) {
        if (cur -> data == s) {
            // Caso elemento in testa
            if (cur -> prev == nullptr) {
                l = cur -> next;
            } else {
                cur -> prev -> next= cur -> next;
            }
            cell *temp = cur;
            cur = cur -> next;
            delete temp;
        } else {
            cur = cur -> next;
        }
    }
}