#include "trinary-tree.h"

unsigned int nbOccurrence(Elem el,const triTree& tr){

  if (tr == emptyTriTree) return 0;

  unsigned int count = 0;

  if (tr -> el == el) {
    ++count;
  }

  count += nbOccurrence(el, tr -> child1);
  count += nbOccurrence(el, tr -> child2);
  count += nbOccurrence(el, tr -> child3);

  return count;
}
