#include "trinary-tree.h"

void deleteCur(Elem el, triTree& tr, unsigned int son) {
  if (tr == emptyTriTree) return;

  if (tr->el == el) {
    triTree temp = emptyTriTree;
    
    if (son == 1) temp = tr -> child1;
    else if (son == 2) temp = tr -> child2;
    else if (son == 3) temp = tr -> child3;

    delete tr;
    tr = temp;

    deleteCur(el, tr, son);
    return; // mi serve per uscire dal sotto albero, se non lo metto vado a segmentation fault
  }
  deleteCur(el, tr -> child1, 1);
  deleteCur(el, tr -> child2, 2);
  deleteCur(el, tr -> child3, 3);
}

void deleteAll(Elem el, triTree& tr) {
  // la radice si considera come figlio2 (regola data nell'esercizio)
  deleteCur(el, tr, 2);
}
