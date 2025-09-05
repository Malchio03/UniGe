#include "trinary-tree.h"

unsigned int nbOccurrence(Elem el,const triTree& tr){

  // caso base: albero vuoto
  if (tr == emptyTriTree) return 0;

  unsigned int count = 0;

  // trovo elemento
  if (tr -> el == el) ++count;

  // scorro
  count += nbOccurrence(el, tr -> child1);
  count += nbOccurrence(el, tr -> child2);
  count += nbOccurrence(el, tr -> child3);

  // ritorno
  return count;

  
}
