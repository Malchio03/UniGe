#ifndef PLIST_H
#define PLIST_H

struct Elem {
    int cont;
    struct Elem * next;
};

typedef Elem * PList; 

// Funzioni che dovete implementare
void PList_insert(PList &L, int val);
void PList_delete(PList &L, int val);


// Funzioni definite da noi. Se vi servono potete usarle
#endif //PLIST_H
