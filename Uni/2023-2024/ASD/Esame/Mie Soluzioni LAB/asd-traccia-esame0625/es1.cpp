#include "ternary-tree.h"

//Ritorna il numero di elementi (positivi) nel albero
unsigned int nbElem(const terTree& tr){
  if (tr == emptyTerTree) return 0;
  unsigned int count = 0;

  if (tr -> v1 != -1) ++count;

  if (tr -> v2 != -1) ++count;

  count += nbElem(tr -> left);
  count += nbElem(tr -> middle);
  count += nbElem(tr -> right);

  return count;
}


