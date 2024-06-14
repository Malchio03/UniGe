#include <iostream>
#include "list.h"

unsigned int countOccurrences(const List &l, Elem s) {
    unsigned int count = 0;
    Cell* current = l;
    while (current != nullptr) {
        if (current->elem == s) {
            count++;
        }
        current = current->next;
    }
    return count;
}

bool insertElemInSortedOrder(List &l, Elem s) {
    Cell* newCell = new Cell;
    newCell->elem = s;
    newCell->next = nullptr;

    if (l == nullptr || l->elem > s) {
        newCell->next = l;
        l = newCell;
        return true;
    }

    Cell* current = l;
    while (current->next != nullptr && current->next->elem < s) {
        current = current->next;
    }

    newCell->next = current->next;
    current->next = newCell;
    return true;
}


void reverseList(List &l) {
    Cell* prev = nullptr;
    Cell* current = l;
    Cell* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    l = prev;
}
