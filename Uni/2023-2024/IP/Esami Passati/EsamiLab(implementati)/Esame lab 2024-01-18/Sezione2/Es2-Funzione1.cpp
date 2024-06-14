#include "list.h"

unsigned int computeListSize(const List &l) {
    if (l == nullptr) {
        return 0;
    }
    Cell* cur = l;
    unsigned int size = 0;
    while (cur != nullptr) {
        ++size;
        cur = cur -> next;
    }
    return size;
}
