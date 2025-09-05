#include "double-hash.h"

/*************************************************/
/* Funzione da implementare                      */
/*************************************************/

//Es 1
//Ritorna il numero di elementi nella tabella
unsigned int nbElem(const dhash_table& dht){

  unsigned int count = 0;

  for (unsigned int i = 0; i < tableDim; ++i) {

    // Caso 1: lista T1
    while(dht.T1[i] != emptydllist) {
      ++count;
      dht.T1[i] = dht.T1[i]-> next;
    }

    // Caso 2: lista T2
    while(dht.T2[i] != emptydllist) {
      ++count;
      dht.T2[i] = dht.T2[i]-> next;
    }
    

  }
  return count;
}


