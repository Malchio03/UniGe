#include "set_dll.h"
#include <iostream>

void insert_set_dll(set_dll &s, int v) {
    set_cell *new_cell = new set_cell;
    new_cell->data = v;

    if (s == nullptr) {
        s = new_cell;
        s->next = s;
        s->prev = s;
        return;
    }

    set_cell *cur = s;
    while (cur->next != s && cur->next->data < v) {
        cur = cur->next;
    }

    new_cell->next = cur->next;
    new_cell->prev = cur;
    cur->next = new_cell;
    new_cell->next->prev = new_cell;
}

void print_set_dll(const set_dll &s) {
    if (s == nullptr) {
        std::cout << "Empty set" << std::endl;
        return;
    }

    set_cell *cur = s;
    do {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != s);
    std::cout << std::endl;
}

void revprint_set_dll(const set_dll &s) {
    if (s == nullptr) {
        std::cout << "Empty set" << std::endl;
        return;
    }

    set_cell *cur = s->prev;
    do {
        std::cout << cur->data << " -> ";
        cur = cur->prev;
    } while (cur != s->prev);
    std::cout << std::endl;
}

set_dll union_set_dll(const set_dll &s1, const set_dll &s2) {
    set_dll result = nullptr;

    set_cell *cur1 = s1;
    set_cell *cur2 = s2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->data < cur2->data) {
            insert_set_dll(result, cur1->data);
            cur1 = cur1->next;
        } else if (cur1->data > cur2->data) {
            insert_set_dll(result, cur2->data);
            cur2 = cur2->next;
        } else {
            // Duplicates, insert only one
            insert_set_dll(result, cur1->data);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    while (cur1 != nullptr) {
        insert_set_dll(result, cur1->data);
        cur1 = cur1->next;
    }

    while (cur2 != nullptr) {
        insert_set_dll(result, cur2->data);
        cur2 = cur2->next;
    }

    return result;
}

set_dll intersect_set_dll(const set_dll &s1, const set_dll &s2) {
    set_dll result = nullptr;

    set_cell *cur1 = s1;
    set_cell *cur2 = s2;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->data < cur2->data) {
            cur1 = cur1->next;
        } else if (cur1->data > cur2->data) {
            cur2 = cur2->next;
        } else {
            // Common element found, insert into result
            insert_set_dll(result, cur1->data);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    return result;
}
