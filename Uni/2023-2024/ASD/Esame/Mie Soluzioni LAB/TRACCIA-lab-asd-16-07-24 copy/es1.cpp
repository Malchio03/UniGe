#include "intpair-bst.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

unsigned int bst2(const pairBstTree2& pbst) {
  if (pbst == emptyPairBstTree2) return 0;

  unsigned int count = 0;

  count += bst2(pbst -> left2);
  count += bst2(pbst -> right2);

  return count + 1;
}

//Es 1
//Ritorna il numero di coppie nel albero
unsigned int nbPairs(const pairBstTree& pbst){
  if (pbst == emptyPairBstTree) return 0;

  unsigned int count = 0;

  count += bst2(pbst -> bst2);

  count += nbPairs(pbst -> left1);
  count += nbPairs(pbst -> right1);

  return count;
}

unsigned int contaV1(const pairBstTree& pbst) {
  unsigned int count = 0;

  if (pbst == emptyPairBstTree) return 0;

  if (pbst != emptyPairBstTree) {
    ++count;
  }

  count += contaV1(pbst -> left1);
  count += contaV1(pbst -> right1);
}