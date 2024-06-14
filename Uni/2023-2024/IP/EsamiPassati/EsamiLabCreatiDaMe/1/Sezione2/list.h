#ifndef LIST_H
#define LIST_H

#include <string>

typedef std::string Elem;

struct Cell {
    Elem elem;
    struct Cell *next;
};

typedef Cell* List;

unsigned int contaElementi(const List &l);
void aggiungiInTesta(List &l, Elem e);
void eliminaElementi(List &l, Elem e);

#endif // LIST_H
