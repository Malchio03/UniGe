#ifndef LIST_H
#define LIST_H

#include <string>

typedef std::string Elem;

struct Cell {
    Elem elem;
    Cell* next;
};

typedef Cell* List;

// Funzione per calcolare la lunghezza di una lista
unsigned int computeListSize(const List &l);

// Funzione per inserire un elemento in una posizione specifica di una lista
bool insertElemInListAtIndex(List &l, Elem s, unsigned int index);

// Funzione per eliminare l'ultima istanza di un elemento in una lista
void deleteLastInstanceOfElemInList(List &l, Elem s);


#endif
