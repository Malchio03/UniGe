#include <iostream>
#include "list.h"

unsigned int computeListSize(const List l){
    if (l == nullptr) {
        return 0;
    }
    Cell* cur = l;
    unsigned int i = 1;
    while (cur -> next != l) {
        ++i;
        cur = cur -> next;
    }
    return i;
}

