#include "ll.h"
#include <iostream>

void addhead(ll &s, char & c)
{
    elem *temp = new elem;
    temp -> next = s;
    temp -> c = c;
    s = temp;
}

bool removehead(ll &s, char & c)
{
    if (s != nullptr) {
        elem *aux = s;
        c = aux -> c;
        s = s -> next;
        delete aux;
        return true;
    } 
    return false;
}

int size(ll s)
{
    int count = 0;
    elem *cur = s;
    while (cur != nullptr) {
        cur = cur -> next;
        ++count;
    }
    return count;
}
