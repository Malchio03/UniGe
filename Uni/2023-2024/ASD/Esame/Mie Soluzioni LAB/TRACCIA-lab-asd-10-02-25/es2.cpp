#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 2
//Verifica se un elemento e' presente
bool isPresent(const dhash_table& dht,Elem e){

 for (unsigned int i = 0; i < tableDim; ++i) {

  cell *cur = dht.T1[h1(e)];
   // Caso 1: lista T1
   while(cur != emptydllist) {
    if (cur -> elem == e) {
      return true;
    }
    cur = cur -> next;
  }

  // Caso 2: lista T2
  cell *cur2 = dht.T2[h2(e)];
  while(cur2 != emptydllist) {
    if (cur2 -> elem == e) {
      return true;
    }
    cur2 = cur2 -> next;
  }
 }

  return false;
}
