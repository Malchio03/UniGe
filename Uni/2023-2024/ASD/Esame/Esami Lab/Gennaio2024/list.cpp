#include "list.h"
#include <iostream>
using namespace std;

void insert_tail(List& l, const int v) {
    cell *aux = new cell;
    aux -> value = v;
    // caso lista vuota
    if (l.head == nullptr) {
        aux -> next = nullptr;
        l.head = aux;
        return;
    }
    // tutti gli altri casi
    cell *cur = l.head;
    while (cur -> next != nullptr) {
        cur = cur -> next;
    }
    cur -> next = aux;
    aux -> next = nullptr;
}

bool remove(List& l, unsigned int pos) {
    // se la lista è vuota non abbiamo nulla da eliminare
    if (l.head == nullptr) {
        return false;
    }
    // caso in testa
    if (pos == 0) {
        cell *temp = l.head;
        l.head = l.head -> next;
        delete temp;
        return true;
    }
    // tutti gli altri casi
    cell *cur = l.head;
    cell *prev = nullptr;
    unsigned int i = 0;
    while (cur != nullptr && i < pos) {
        i++;
        prev = cur;
        cur = cur -> next;
    }
    if (i == pos) {
        prev -> next = cur -> next;
        delete cur;
        return true;
    }
    return false;
}

unsigned int count_between(const List& l, const int a, const int b) {
    unsigned int count = 0;
    cell *cur = l.head;
    while (cur != nullptr) {
        if (cur->value >= a && cur->value < b) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}