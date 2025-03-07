#include "dict-tree.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di parole nell' albero
unsigned int nbWords(const dictTree& dt){
  unsigned int count = 0;

  if (dt == emptyDictTree) {
    return 0;
  }

  if (dt -> val == 8) {
    ++count;
  }
  
  count += nbWords(dt -> son);
  count += nbWords(dt -> brother);
}

