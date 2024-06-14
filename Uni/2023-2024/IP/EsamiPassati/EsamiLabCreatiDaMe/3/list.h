#ifndef LIST_H
#define LIST_H

#include <string>

typedef std::string Elem;

struct Cell {
    Elem elem;
    struct Cell* next;
};

typedef Cell* List;

unsigned int countOccurrences(const List &l, Elem s);
bool insertElemInSortedOrder(List &l, Elem s);
void reverseList(List &l);

#endif // LIST_H
